#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;
search_same_number(vector<int>arr,int num=0)
{
    for (int i=0; i<arr.size(); i++)
    {
        int match_this=arr[i];
        for(int j=i+1; j<arr.size(); j++)
        {
            if(match_this==arr[j])
                return 1;
        }
    }
    return 0;

}
display_rsult(int arr[],int n,string text){
    cout<<text<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void BFs(int n,vector<int>arr[],int source_V)
{
    queue<int>q;
    int color[n],dis[n],prev[n];
//color  1 is gray
//color 2 is black
//color 0 is white
    for(int i=0; i<n; i++)
    {
        color[i]=0;
        dis[i]=-1;
        prev[i]=-1;
    }
    /**/
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
//            if( color[arr[u][i]]==1 || color[arr[u][i]]==2)
//            {
//
//            }
//            else
//            {
//
//            }
/**
* arr [u][i] return a index that represent a vertex which is connected to this vertex
* and this vertex index is 'u'
*/
            if(color[othervirtex]==0){
                q.push(othervirtex);
                color[othervirtex]=1;
                dis[othervirtex]=dis[u]+1;
                prev[othervirtex]=u;
            }





        }
        color[u]=2;
    }

display_rsult(color,n,"***color***");
display_rsult(dis,n,"**distance**");
display_rsult(prev,n,"**previous node **");
}
main()
{
    vector<int>arr[10];
    int n=5;
    int loopend=n;
    for(int i=0; i<loopend; i++)
    {
        int row,col;
        cin>>row>>col;
        if ((row<0 || col<0)||(row>=n||col>=n))
        {
            loopend++;
            cout<<"ohhww looks like you enter wrong value , please enter a right one !"<<endl;
        }
        else
        {
//            if(row==col)
//                cout<<"multi graph self loop in vertex number : " <<row<<endl;
            arr[row].push_back(col);
            arr[col].push_back(row);
        }


    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<arr[i].size(); j++)
        {


            cout<<arr[i][j]<<" ";
            if(i==arr[i][j])
                cout<<"multi graph self loop in vertex number : " <<i<<endl;
        }

        if (search_same_number(arr[i]))
        {
            cout<<"multi graph with one or more edges "<<endl;
        }
        cout<<endl;
    }

    BFs(n,arr,1);
}

