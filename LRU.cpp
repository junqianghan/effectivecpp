// A simple LRU cache written in C++
// Hash map + doubly linked list
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template <class K,class T>
struct Node
{
    K key;
    T data;
    Node *prev,*next;
};


template <class K, class T>
class LRUCache{
  public:
    LRUCache(size_t size){
        entries_ = new Node<K,T>[size];
        for(int i=0;i<size;i++)
        {
            free_entries_.push_back(entries_+i);
        }
        head_ = new Node<K,T>;
        tail_ = new Node<K,T>;
        head_->prev = nullptr;
        head_->next = tail_;
        tail_->next = nullptr;
        tail_->prev = head_;
    }

    ~LRUCache(){
        delete head_;
        delete tail_;
        delete[] entries_;
    }

    void Put(K key, T data)
    {
        Node<K,T> *node = hashmap_[key];
        if(node)
        {
            detach(node);
            node->data = data;
            attach(node);
        }
        else
        {
            if(free_entries_.empty())
            {
                node = tail_->prev;
                detach(node);
                hashmap_.erase(node->key);
            }
            else
            {
                node = free_entries_.back();
                free_entries_.pop_back();
            }
            node->key = key;
            node->data = data;
            hashmap_[key] = node;
            attach(node);
        }
    }

    T Get(K key)
    {
        Node<K,T> *node = hashmap_[key];
        if(node)
        {
            detach(node);
            attach(node);
            return node->data;
        }
        else
        {
            return T();
        }
    }
  private:
    unordered_map<K, Node<K,T>*> hashmap_;
    vector<Node<K,T>*> free_entries_; //可用结点地址
    Node<K,T> *head_, *tail_;
    Node<K,T> *entries_; //双向链表中的结点；

    // 分离结点
    void detach(Node<K,T>* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 将结点插入头部
    void attach(Node<K,T>* node)
    {
        node->prev = head_;
        node->next = head_->next;
        head_->next = node;
        node->next->prev = node;
    }


};


int main(int argc, char const *argv[])
{
    LRUCache<int,string> lru_cache(100);
    lru_cache.Put(1,"One");
    cout<<lru_cache.Get(1)<<endl;
    if(lru_cache.Get(2) == "")
        lru_cache.Put(2,"two");
    cout<<lru_cache.Get(2)<<endl;
        
    return 0;
}