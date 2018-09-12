//
// Created by han on 18-9-12.
//

#include <iostream>

using namespace std;

class CMyString{
  public:
    CMyString(char* pData = nullptr){}
    CMyString(const CMyString& str){};
    ~CMyString(){ delete[] m_pData;}

    CMyString& operator=(const CMyString& str);

  private:
    char* m_pData;
};

CMyString& CMyString::operator=(const CMyString &str)
{
    if(this != &str)
    {
        CMyString strTemp(str);
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = this->m_pData;
        this->m_pData=pTemp;
    }
    return *this;
}


int main(int argc, char const *argv[])
{
    cout<<"hello"<<endl;

    return 0;
}