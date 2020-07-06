#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;
void print_path(int *p,int s,int v){
if(s==v){
    //cout<<s<<" ";
}else if(v==NULL){
cout<<"no path"<<endl;
}
else
    print_path(p,s,p[v]);
cout<<v<<" ";

}
void BFs(int n,vector<int>arr[],int source_V)
{
    queue<int>q;
    int color[n],dis[n],prev[n];

    for(int i=0; i<n; i++)
    {
        color[i]=0;
        dis[i]=-1;
        prev[i]=-1;
    }

    q.push(source_V);
    color[source_V]=1;
    dis[source_V]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0; i<arr[u].size(); i++)
        {
            int  othervirtex=arr[u][i];

            if(color[othervirtex]==0){
                q.push(othervirtex);
                color[othervirtex]=1;
                dis[othervirtex]=dis[u]+1;
                prev[othervirtex]=u;
            }





        }
        color[u]=2;
    }

    for(int i=0;i<n;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
    int v;
    cin>>v;
    print_path(prev,source_V,v);

}
main()
{
    vector<int>arr[10];
    int n=5;
    int loopend=n;
    for(int i=0; i<5; i++)
    {
        int row,col;
        cin>>row>>col;

//            if(row==col)
//                cout<<"multi graph self loop in vertex number : " <<row<<endl;
            arr[row].push_back(col);
            arr[col].push_back(row);



    }


    BFs(n,arr,0);
}
