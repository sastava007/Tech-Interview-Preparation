/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                                                                    SHIVANSH SRIVASTAVA
                                                                                Email: sastava007@gmail.com

                                                                            Bachelors in Computer Science (2018-22)
                                                                    INDIAN INSTITUTE OF INFORMATION TECHNOLOGY, GWALIOR

                                                                                    GOD PRAY FOR ME !
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
main()
{
    int n,m,i,j,ele;
    unordered_map<int, int> a,b;
    set<int> missing;
    sf(n);
    fr(n)
    {
        sf(ele);
      if (b.find(ele) != b.end())
        b[ele]++;
      else
        b[ele] = 1;
    }


    sf(m);
    fr(m)
    {
        sf(ele);
      if (a.find(ele) != a.end())
        a[ele]++;
      else
        a[ele] = 1;
    }

    for(auto it:a)
    {
            auto x=b.find(it.first);
            if(x==b.end() || x->second!=it.second)
                missing.insert(it.first);

    }

    for(auto k:missing)
        cout<<k<<" ";
    return 0;
}

