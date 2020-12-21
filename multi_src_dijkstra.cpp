#include <bits/stdc++.h>
#define SIZE 100105
#define INF 1000000000
using namespace std;
struct element{
    int node=0, weight=0;
    element(){}

    element(int n, int w){
        node=n;
        weight=w;
    }
    bool operator <(const element &a)const{
        return weight<a.weight;
    }
    bool operator >(const element &a)const{
        return weight>a.weight;
    }
};

priority_queue <element, vector <element>, greater <element> > pq;
int dis[SIZE];
bool vis[SIZE];
vector <int> adj[SIZE];
vector <int> adjw[SIZE];
int n, e;
void init(int source){
    for(int i=1; i<=n; i++){
        dis[i]=INF;
        vis[i]=false;
    }
    dis[source]=0;
}

void dijkstra(int source){
    init(source);
    pq.push(element(source, 0));
    int u, v;
    while(!pq.empty()){
        u=pq.top().node;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0; i<(int)adj[u].size(); i++){
            v=adj[u][i];
            if(dis[v]>dis[u]+adjw[u][i]){
                dis[v]=dis[u]+adjw[u][i];
                pq.push(element(v, dis[v]));
            }
        }
    }
}
int main(){
    int u, v, w;
    scanf("%d %d", &n, &e);

    for(int i=0; i<e; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(v);
        adj[v].push_back(u);
        adjw[u].push_back(w);
        adjw[v].push_back(w);
    }
    int m;
    cin>>m;
    int min_Src=10000000000;
    for(int i=0;i<m;i++){
        int src;
        cin>>src;
        dijkstra(src);
        if(min_Src>dis[n])
            min_Src=dis[n];
        
    }
    cout<<min_Src<<endl;
   
    
    return 0;
}

/**
input

6 8
1 4 7
1 3 3
1 2 4
2 4 2
2 5 2
4 6 3
5 6 2
3 5 5
3
2
1
3

*/
