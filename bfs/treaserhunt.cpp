
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int bfs(vector<int>g[],int n,int t,int s){
int color[n],d[n];
for(int i=0;i<n;i++){
    color[i]=0;
    d[i]=-1;
}
queue<int>q;
q.push(s);
color[s]=0;
d[s]=0;
while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
        if(color[v]==0){
            d[v]=d[u]+1;
            color[v]=1;
            q.push(v);

        }
    }
    color[u]=2;
}
//for(int i=0;i<n;i++){
//    cout<<d[i]<<" ";
//}
cout<<endl;
return d[t];
}

int main(){
    int n;
    cin>>n;
vector<int>g[n];
int e;
cin>>e;
for(int i=0;i<e;i++){
    int row,col;
    cin>>row>>col;
    g[row].push_back(col);
    g[col].push_back(row);
}
int vik=0,min_dis=-1,dis,who;
cout<<"enter number of vikings "<<endl;
cin>>vik;
for(int i=0;i<vik;i++){
        cout<<"enter number of island"<<endl;
        int island;
    cin>>island;
    dis=bfs(g,n,3,island);
    if(min_dis==-1){
       min_dis=dis;
       who=island;
    }

    else{
        if(min_dis<dis){
            min_dis=dis;
            who=island;
        }
    }
}
cout<<who<<" vikings takes min distance of   "<<min_dis<<endl;

}
