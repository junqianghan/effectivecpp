#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s("");
    while(n>0)
    {
        if(n%2 == 1)
        {
            s.push_back('2');
            n=(n-1)/2;
        }
        else
        {
            s.push_back('3');
            n=(n-2)/2;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}

