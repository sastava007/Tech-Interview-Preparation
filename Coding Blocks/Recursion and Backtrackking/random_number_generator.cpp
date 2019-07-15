#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    for(int i=0;i<20;i++)
        cout<<rand()%10<<"\n";
    return 0;
}

