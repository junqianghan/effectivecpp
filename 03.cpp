
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char const *argv[])
{
    unordered_map<int,int> data;
    vector<int> v{2,3,1,0,2,5,3};

    for_each(v.begin(),v.end(),[&data](int a){data[a]++;});

    for_each(data.begin(),data.end(),[](pair<int,int > a){cout<<a.first<<" "<<a.second<<endl;});

    for(auto i:v)
    {
        if(data[i] > 1)
        {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
