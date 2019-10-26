#include<iostream>
#include<vector>

using namespace std;
int _time=0;
const int _size=10;
vector<int>graph[_size];
int color[_size];
int prev[_size];
int d[_size];
int f[_size];
int low[_size];

void dfs_visit(int v)
{
    color[v]=1;
    _time+=1;
    d[v]=_time;
    low[v]=d[v];
    for(int i=0; i<graph[v].size();i++)
    {
         int w=graph[v][i];
        if(color[graph[v][i]]==0){

            dfs_visit(w);
            if(low[w]<low[v])
                low[v]=low[w];
        }else if(color[w]==1){
            if(d[w]<low[v]){
                low[v]=d[w];
            }
        }
        if(low[w]>=d[v]){
            cout<<v<<" is a articulation point "<<endl;
        }

    }
    _time+=1;
    color[v]=2;
    f[v]=_time;

}
void dfs(int n)
{
    for(int i=0; i<n; i++)
    {
        color[i]=0;
        /// here -1 is referencing infinity

        d[i]=-1;
        f[i]=-1;
        low[i]=-1;
    }
    for(int i=0; i<n; i++)
    {
        if(color[i]==0)
        {
            dfs_visit(i);
        }
    }

}
int main()
{
    int n;
    cin>>n;
    if(n<=_size)
    {
        int edge;
        cin>>edge;
        for(int i=0; i<edge; i++)
        {
            int row,col;
            cin>>row>>col;
            graph[row].push_back(col);
            graph[col].push_back(row);
        }
    }
    dfs(n);
//    cout<<"color"<<endl;
//    for(int i=0; i<n; i++)
//    {
//        cout<<color[i]<<endl;
//    }
}
