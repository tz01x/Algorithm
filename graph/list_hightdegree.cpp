#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,e;
    cin>>n;
vector<int>adj[n];
cout<<"enter edge number"<<endl;

cin>>e;
for (int i=0;i<e;i++){
     int row,col;
    cin>>row>>col;

adj[row].push_back(col);
//adj[col].push_back(row);
}
int max=0;
int deg=0;
for (int i=0;i<n;i++){

    if(max<adj[i].size()){
            deg=i;
        max=adj[i].size();
    }
}
cout<<"node -> "<<deg;
cout<<max<<endl;
}
