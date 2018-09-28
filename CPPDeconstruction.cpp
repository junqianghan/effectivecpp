
#include "common.h"

/**
 * 验证CPP析构函数执行
 * 子类析构
 * 子类成员析构
 * 基类析构
 */


class help{
  public:
    help(int a):i(a){}
    ~help(){
        cout<<"~help"<<i<<endl;
    }

  private:
    int i;
};


class Base{
  public:
    ~Base(){
        cout<<"~Base"<<endl;
    }
};


class Deried : public Base{
  public:
    Deried():h1(1),h2(2){}
    ~Deried(){
        cout<<"~Deried"<<endl;
    }

  private:
    help h1;
    help h2;
};





int main(int argc, char const *argv[])
{
    Deried d;

    return 0;
}