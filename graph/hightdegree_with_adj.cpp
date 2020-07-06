#include<iostream>
using namespace std;

int main(){
    int n=5;
int adj[n][n];
for (int i=0;i<n;i++){

    for(int j=0;j<n;j++){
        adj[i][j]=0;
    }

}
int v,e;

cout<<"enter edge number"<<endl;

cin>>e;
for (int i=0;i<e;i++){
    int row,col;
    cin>>row>>col;
    adj[row][col]=1;
    adj[col][row]=1;
}
int max=0,node;
for (int i=0;i<n;i++){
        int degree=0;
    for(int j=0;j<n;j++){
        degree+=adj[i][j];
    }
    if (max<degree){
            node=i;
        max=degree;
    }

cout<<"vertex number "<<i<<" degree is ->"<<degree<<endl;
}
cout<<"node ->"<<node;
cout<<"degree is "<<max<<endl;

}
