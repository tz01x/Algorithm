#include<bits/stdc++.h>

using namespace std;
int infinity=numeric_limits<int>::max();
class node{
public:
    int key;
    int weight;
    node(){
    key=0;
    weight=0;
    }
    node(int key,int weight){
        this->key=key;
        this->weight=weight;

    }
}temp;


void dfs_visit(vector<node>graph[],int v,int *color,stack<int>&s)
{

    color[v]=1;
    for(int i=0; i<graph[v].size();i++)
    {
        node w=graph[v][i];
        if(color[w.key]==0)

            dfs_visit(graph,w.key,color,s);
    }

    color[v]=2;

    s.push(v);

}
stack<int> topological_short( vector<node>graph[],int n,stack<int>&s)
{
int color[n];
//
//stack<int>s;

    for(int i=0; i<n; i++)
    {
        color[i]=0;
        /// here -1 is referencing infinity


    }
    for(int i=0; i<n; i++)
    {
        if(color[i]==0)
        {
            dfs_visit(graph,i,color,s);
        }
    }

    return s;

}

DAG_SHORTEST_PATHS(vector<node>graph[],int n,int s){
stack<int>_Stack;
topological_short(graph,n,_Stack);
long long int d[n],p[n];
for(int i=0;i<n;i++){
    d[i]=infinity;
    p[i]=-1;
}
d[s]=0;
while(!_Stack.empty()){
    int u=_Stack.top();
    printf("%d ,",u);
    _Stack.pop();
    for(int i=0;i<graph[u].size();i++){
        node v=graph[u][i];
        if(d[u]+v.weight<d[v.key]){
            d[v.key]=d[u]+v.weight;
            p[v.key]=u;
        }
    }
}
cout<<endl;

for(int i=0;i<n;i++){
    printf(" dis of %d  is %d  and parent is %d \n",i,d[i],p[i]);

}
}


int main(){
int n,en;
bool is_directed=true;
cout<<"enter node number "<<endl;
cin>>n;
 vector<node>g[n];
cout<<"enter edge number ";
cin>>en;
for(int i=0;i<en;i++){
        cout<<"enter row col weight "<<endl;
    int row,col,weight;
    cin>>row>>col>>weight;
    ///graph input
    temp.key=col;
    temp.weight=weight;
    g[row].push_back(temp);


    if (!is_directed){
            ///if graph is undirected
    temp.key=row;
    g[col].push_back(temp);
    }

}
int source=2;
DAG_SHORTEST_PATHS(g,n,source);

}
