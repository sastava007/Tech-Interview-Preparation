/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                                                                    SHIVANSH SRIVASTAVA
                                                                                Email: sastava007@gmail.com

                                                                            Bachelors in Computer Science (2018-22)
                                                                    INDIAN INSTITUTE OF INFORMATION TECHNOLOGY, GWALIOR

                                                                                    GOD PRAY FOR ME !

    QUES:  https://practice.geeksforgeeks.org/problems/min-sum-formed-by-digits/0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
                                                                                                                                                                                                                                                                                                                                                                                              */
#include<bits/stdc++.h>

#define ll                    long long int
#define fr(x)                 for(int i=0;i<x;i++)

#define sf(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

#define sfll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)
#define sfc(a)                scanf("%c",&a)

#define pf_sp(a)              printf("%d ",a);
#define pf_nw(a)              printf("%d\n",a);


using namespace std;
void solve(stack<int> *s1)
{
   stack<int>s2;
   int temp;
   while(s1->size()!=0)
   {
       temp=s1->top();
       s1->pop();
       while(s2.size()!=0 && s2.top()>temp)
            {
                s1->push(s2.top());
                s2.pop();
            }
            s2.push(temp);
   }
//   while(!s2.empty())
//   {
//       cout<<s2.top()<<" ";
//       s2.pop();
//   }




   vector<int> a,b;
   int l=s2.size();
   for(int i=0;i<l-1;i++)
   {
       a.push_back(s2.top());
       s2.pop();
       b.push_back(s2.top());
       s2.pop();
   }
   a.push_back(s2.top());
    s2.pop();
    cout<<a.size()<<" "<<b.size();
//   reverse(a.begin(),a.end());
//   reverse(b.begin(),b.end());
//   cout<<stoi(a)+stoi(b)<<endl;
}
main()
{
    int t,n,i,j,ele;
    sf(t);
    while(t--)
    {
        sf(n);
        stack<int>s1;
        fr(n)
        {
            sf(ele);
            s1.push(ele);
        }

        solve(&s1);
    }

}
