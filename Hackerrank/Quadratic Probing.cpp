#include<bits/stdc++.h>
using namespace std;
int table[10];
int hash_function(int key)
{
    int index=key%10;
    return index;
}
void insert_in_table(int key)
{
    int index=hash_function(key);
    if(table[index]==-1)
        table[index]=key;
    else
    {
        int i=1;
        while(table[(index+i*i)%10]!=-1 && (index+i*i)%10!=index)
            i++;
        if((index+i*i)%10 !=index)
            table[(index+i*i)%10]=key;
        else
            cout<<"Table is full\n";
    }

}
void find_key(int key)
{
    int index=hash_function(key);
    if(table[index]==key)
    {
        cout<<"YES present\n";
    }
    else
    {
        int i=1;
        while(table[(index+i*i)%10]!=key && table[(index+i*i)%10]!=-1)
            i++;
        if(table[(index+i*i)%10]==key)
            cout<<"YeS prseent\n";
        else
            cout<<"NO\n";

    }

}
main()
{
    for(int i=0;i<10;i++)
        table[i]=-1;

    insert_in_table(10);
    insert_in_table(11);
    insert_in_table(20);
    insert_in_table(23);
    insert_in_table(33);
    insert_in_table(50);
    insert_in_table(80);
    insert_in_table(75);

    find_key(14);
    find_key(20);
    find_key(15);
    find_key(50);
    find_key(80);
    find_key(75);
    find_key(59);
    find_key(83);
    find_key(77);






}
