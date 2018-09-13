
#include "common.h"
#include <string>

int main(int argc, char const *argv[])
{
    string s{"hello world"};
    auto it = s.find(' ');
    s.insert(it,"%20");
    s.erase(s.begin()+it+3,s.begin()+it+4);
//    cout<<it-s.begin()<<endl;
    cout<<s<<endl;


    return 0;
}
