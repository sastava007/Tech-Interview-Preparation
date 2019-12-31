#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T,int> > > m;

public:

    void addEdge(T u,T v,int dist)
    {
        m[u].push_back(make_pair(v,dist));

    }
    void printAdj()
    {
        for(auto j:m)
            {
                cout<<j.first<<"->";
                for(auto l: j.second)
                        cout<<"("<<l.first<<","<<l.second<<")";
            cout<<endl;
            }
    }

    void dijsktra(T src)
    {
        unordered_map<T,int> dist;
        for(auto j:m)
            dist[j.first] = INT_MAX;

        set<pair<int, T> > s;
        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty())
            {
                auto p =   *(s.begin());
                T node = p.second;

                int nodeDist = p.first;
                s.erase(s.begin());
                for(auto childPair: m[node])
                    {

                        if(nodeDist + childPair.second < dist[childPair.first])
                            {
                                T dest = childPair.first;
                                auto f = s.find( make_pair(dist[dest],dest));
                                if(f!=s.end())
                                    s.erase(f);
                                dist[dest] = nodeDist + childPair.second;
                                s.insert(make_pair(dist[dest],dest));

                            }
                    }
            }

            cout<<"\nShortest distance from "<<src<<" : \n";
        for(auto d:dist)
            cout<<"( "<<d.first<<","<<d.second<<" )"<<" , ";
    }

};

int main()
{
    Graph<int> g;
//    g.addEdge(1,4,60);
//    g.addEdge(1,5,70);
//    g.addEdge(1,7,120);
//    g.addEdge(1,2,10);
//
//    g.addEdge(2,3,20);
//    g.addEdge(2,5,30);
//
//    g.addEdge(3,4,170);
//
//    g.addEdge(4,5,80);
//    g.addEdge(4,7,70);
//
//    g.addEdge(5,6,50);
//    g.addEdge(5,7,150);
//
//    g.addEdge(6,1,100);
//
//    g.addEdge(7,3,40);

    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);


    g.printAdj();

    g.dijsktra(1);
//    g.dijsktra(2);
//    g.dijsktra(3);
//    g.dijsktra(4);

 return 0;
}

