#include<iostream>
using namespace std;

class complex
{

private:
    int a,b;
public:
    void showdata();
    void getdata();

};

void complex::getdata()
{

    cout<<"Enter two inetger:";
    cin>>a>>b;

}

void complex::showdata()
{

    cout<<"a="<<a<<"b="<<b;

}

int main()
{

    complex c1;
    complex *p;
    p=&c1;
    p->getdata();
    p->showdata();
    return 0;
}
