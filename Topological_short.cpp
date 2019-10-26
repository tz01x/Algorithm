#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int _time=0;
const int _size=10;
vector<int>graph[_size];
int color[_size];
int prev[_size];
int d[_size];
int f[_size];
stack<int>s;



void dfs_visit(int idx)
{
    color[idx]=1;
    _time+=1;
    d[idx]=_time;
    for(int i=0; i<graph[idx].size();i++)
    {
        if(color[graph[idx][i]]==0)
            dfs_visit(graph[idx][i]);
    }
    _time+=1;
    color[idx]=2;
    f[idx]=_time;
    s.push(idx);

}
void dfs(int n)
{
    for(int i=0; i<n; i++)
    {
        color[i]=0;
        /// here -1 is referencing infinity

        d[i]=-1;
        f[i]=-1;
    }
    for(int i=0; i<n; i++)
    {
        if(color[i]==0)
        {
            dfs_visit(i);
        }
    }

}
int main(){
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
    cout<<"color"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<" -> "<<d[i]<<"/"<<f[i]<<endl;
    }
    cout<<endl;
    bool works=false;
    while(!s.empty()){
        cout<<s.top();
        cout<<" ";
      s.pop();

    }
    cout<<endl;

}
