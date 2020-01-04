#include<iostream>
using namespace std;
int arr[50][50];
int parents[50];
bool is_visited(int v,int node_visited){
 for(int i=0;i<node_visited;i++){
    if(parents[i]==v)
        return false;
 }
 return true;
}
display_path(int node_visited){
 for(int i=0;i<node_visited;i++){
     cout<<parents[i]<<"  ";
 }

}
int Hamilton_cycle(int u,int node_visited,int _size,int source){
    if(node_visited==_size-1){
        if(arr[u][source]==1){
            parents[node_visited+1]=u;

            display_path(node_visited+1);
            cout<<source<<endl;
            return 0;
        }
    }
    for(int i=0;i<_size;i++){


            if(arr[u][i]){
              int v=arr[u][i];

        if(is_visited(i,node_visited)){
            parents[node_visited+1]=i;
            Hamilton_cycle(i,node_visited+1,_size,source);
        }
            }

    }
}
int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        arr[i][j]=0;
    }
    parents[i]=-1;
}
int edges;
cin>>edges;
for(int i=0;i<edges;i++){
    int r,c;
    cin>>r>>c;
    arr[r][c]=1;
    arr[c][r]=1;
}
int source=0;
parents[0]=source;
Hamilton_cycle(source,0,n,source);
}


//5
//8
//0 1
//0 3
//0 2
//1 4
//1 3
//2 3
//2 4
//3 4
