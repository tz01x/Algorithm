#include<iostream>
#include<vector>
using namespace std;
struct node{
int index,weight;
}temp;
int main(){
    int n,e;
    cout<<"v"<<endl;
    cin>>n;
vector<node>adj[n];
cout<<"enter edge number"<<endl;

cin>>e;
for (int i=0;i<e;i++){

     int row,col,weigh;

    cin>>row>>col>>weigh;

    temp.index=col;
    temp.weight=weigh;
    adj[row].push_back(temp);
    temp.index=row;
    adj[col].push_back(temp);
}
cout<<endl;
cout<<endl;
int max=0,p=0,m;
for (int i=0;i<n;i++){

  for(int j=0;j<adj[i].size();j++){
    if(max<adj[i][j].weight){
        max=adj[i][j].weight;
        p=i;
        m=adj[i][j].index;
    }
    //cout<<i<<" node ->"<<adj[i][j].index<<"w-> "<<adj[i][j].weight<<"  ";
  }
  cout<<endl;
}
cout<<"max weight "<<max<<" row : " <<p<<"col -> "<<m<<endl;
}

