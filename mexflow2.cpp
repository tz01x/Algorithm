










#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

struct node{
int u,v,c,f;
}temp;
int pre[100];
int c_flow=-1;

int bfs(vector<node>arr[],int n,int source_V,int t)
{
    queue<int>q;
    int color[n];


for (int i=0; i<n; i++){
    pre[i]=-1;
color[i]=0;
}
    q.push(source_V);
    color[source_V]=1;
    pre[source_V]=-1;
    c_flow=arr[0][0].c;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0; i<arr[u].size(); i++)
        {
              temp=arr[u][i];

            if(color[temp.v]==0 && !temp.c<=0){
                q.push(temp.v);
                color[temp.v]=1;

                pre[temp.v]=u;
                if(c_flow>temp.c){
                    c_flow=temp.c;
                }
            }





        }
        color[u]=2;
    }
//    cout<<"color : "<<endl;
//for (int i=0; i<n; i++){
//    cout<<color[i]<<"  ";
//}cout<<endl;
if(color[t]==2){
return 1;
}
else
    return 0;
}
int findindex(vector<node>arr[],int u,int f){
for(int j=0;j<arr[u].size();j++){
    if(arr[u][j].v==f){
        return j;
    }
}
}
maxflow(vector<node>arr[],int n,int s,int t){

vector<node>grr[n];
for(int i=0; i<n; i++)
    {
      for(int j=0;j<arr[i].size();j++){
        temp=arr[i][j];
        grr[i].push_back(temp);
// cout<<"grr"<<endl;
      }
    }
for(int i=0; i<n; i++)
    {
      for(int j=0;j<grr[i].size();j++){
            cout<<i<<" "<<j<<endl;
            cout<<grr[i][j].u<< "   "<< grr[i][j].v<<"  "<<grr[i][j].c<<"  "<<grr[i][j].f<<endl;
      }
      }
while(bfs(grr,n,s,t)){
cout<<"c flow ::"<<c_flow<<endl;

    int v=t;
    if(c_flow!=1){
            while(1){

            if( pre[v]==-1){
                    cout<<"Break <<" << v<<endl;
                break;
            }else{
                int u=pre[v];
                cout<<u<<"  "<<v<<" "<<endl;
                int temp_v=findindex(grr,u,v);
//                cout<<"flow before "<<grr[u][temp_v].f<<endl;
//                cout<<"capacity   "<<grr[u][temp_v].c<<endl;
                grr[u][temp_v].f=grr[u][temp_v].f+c_flow;


                grr[u][temp_v].c=grr[u][temp_v].c-c_flow;
//               cout<<"flow after "<<grr[u][temp_v].f<<endl;
//                cout<<"capacity "<<grr[u][temp_v].c<<endl;

        v=u;
            }
        }
         c_flow=-1;
    }







}


int max_flow=0;
for(int i=0;i<grr[s].size();i++){
        temp=grr[s][i];
    max_flow+=temp.f;
}

cout<<"max flow :: " <<max_flow<<endl;

}
main()
{
    int n=6;
    vector<node>arr[n];


    for(int i=0; i<10; i++)
    {
        int row,col,c;
        cin>>row>>col>>c;
        temp.u=row;
        temp.c=c;
        temp.v=col;
        temp.f=0;

        arr[row].push_back(temp);


    }
int s,t;
s=0;
t=5;
maxflow(arr,n,s,t);
//    BFs(n,arr,1);
}


//0 1 16
//0 2 13
//1 2 10
//2 1 4
//1 3 12
//3 2 9
//2 4 14
//4 3 7
//3 5 20
//4 5 4
