#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"

class solution
{
    public:

//        bool compare(pair<int,int>&a, pair<int,int>&b)
//        {
//            return a.first<b.first;
//        }

        void solve(int *a, int *c)
        {
            bool fair=true;
            int i;
            vector<pair<int,int>> v;

            for(i=0;i<3;i++)
            {
                v.emplace_back(make_pair(a[i],c[i]));
            }
            sort(v.begin(),v.end());

            for(i=0;i<2;i++)
            {
                if(((v[i].first<v[i+1].first) && (v[i].second>v[i+1].second)) || ((v[i].first>v[i+1].first) && (v[i].second<v[i+1].second)))
                {
                    fair=false;
                    break;
                }
                else if(((v[i].first<v[i+1].first) && (v[i].second==v[i+1].second)) || ((v[i].first>v[i+1].first) && (v[i].second==v[i+1].second)))
                {
                    fair=false;
                    break;
                }
                else if(v[i].first==v[i+1].first && v[i].second!=v[i+1].second)
                {
                    fair=false;
                    break;
                }

            }
            printSolu(fair);
        }
        void printSolu(bool fair)
        {
            fair?cout<<"FAIR\n":cout<<"NOT FAIR\n";
        }


};
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,i,j;
    cin>>t;
    while(t--)
    {
        int a[3],c[3];
        for(i=0;i<3;i++)
        {
                cin>>a[i];
        }
        for(i=0;i<3;i++)
                cin>>c[i];
        solution obj;

        obj.solve(a,c);
    }

}
