#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int adj[n][n]= {0};
for (int i=0;i<n;i++){

    for(int j=0;j<n;j++){
        adj[i][j]=0;
    }

}
    int v,e;

    cout<<"enter edge number"<<endl;

    cin>>e;
    for (int i=0; i<e; i++)
    {
        int row,col;
        cin>>row>>col;
        adj[row][col]=1;
        adj[col][row]=1;

    }
cout<<endl;
    for (int i=0; i<n; i++)
    {

        for(int j=0; j<n; j++)
        {
//            cout<<adj[i][j]<<" ";
            if(adj[i][j]==0&&(i!=j)){
                adj[i][j]=1;
                adj[j][i]=1;
                cout<<i<<" "<<j<<endl;
            }
        }

        cout<<endl;

    }
//    for (int i=0; i<n; i++)
//    {
//
//        for(int j=0; j<n; j++)
//        {
//            if(adj[i][j]==1)
//            {
//                adj[j][i]=1;
//                adj[i][j]=0;
//            }
//        }
//
//
//
//    }
  cout<<endl;  cout<<endl;  cout<<endl;
//
//    for (int i=0; i<n; i++)
//    {
//
//        for(int j=0; j<n; j++)
//        {
//            cout<<adj[i][j]<<" ";
//        }
//
//        cout<<endl;
//
//    }
}


