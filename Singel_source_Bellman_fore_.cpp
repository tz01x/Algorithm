#include<bits/stdc++.h>
using namespace std;
int infinity=numeric_limits<int>::max();
//class node{
//public:
//    int key;
//    int weight;
//    node(){
//    key=0;
//    weight=0;
//    }
//    node(int key,int weight){
//        this->key=key;
//        this->weight=weight;
//
//    }
//}temp;
//class Edge{
//public:
//    int u,v;
//    int weight;
//    Edge(){
//    u=0;
//    v=0;
//    weight=0;
//    }
//    Edge(int u,int v,int weight){
//        this->u=u;
//        this->v=v;
//        this->weight=weight;
//
//    }
//}edge;
struct node{
int key,weight;
}temp;
struct Edge{
int u,v,weight;
}edge;
int Bellman_ford(vector<Edge>e,int n,int s){
long long int d[n],p[n];
for(int i=0;i<n;i++){
    d[i]=infinity;
    p[i]=  -1;

}
d[s]=0;
for(int i=0;i<n;i++){

       if (d[i]==infinity)
            printf("infinity ");
        else
            cout<<d[i] << "  ";

    }cout<<endl;
//for (int j=0;j<e.size();j++){
//        edge=e[j];
//        cout<<edge.u<<" "<<edge.weight<< "  w ";
//}
cout<<endl;
for(int i=0;i<n-1;i++){

    for (int j=0;j<e.size();j++){
        edge=e[j];
        if((d[edge.u]+edge.weight<d[edge.v])){
            printf("node {%d} -> node {%d} and weight is %d\n",edge.u,edge.v,edge.weight);
            cout<< "dis of u  "<<d[edge.u]<<endl;
            printf("dis of v  %d\n",d[edge.v]);
             d[edge.v]=d[edge.u]+edge.weight; ///Relaxing
             cout<<"Relaxing.."<<endl;
            printf("node {%d} -> node {%d} and weight is %d\n",edge.u,edge.v,edge.weight);
            cout<< "dis of u  "<<d[edge.u]<<endl;
            printf("dis of v  %d\n",d[edge.v]);

            p[edge.v]=edge.u;
        }

    }
}
for(int i=0;i<n;i++){

       if (d[i]==infinity)
            printf("infinity ");
        else
            cout<<d[i] << "  ";
//        printf("prante is %d \n",p[i]);

    }cout<<endl;
   for (int j=0;j<e.size();j++){
        edge=e[j];
        if(d[edge.u]+edge.weight<d[edge.v]){
           return 0;
        }

    }




        return 1;

}
int main(){
int n,en;
bool is_directed=true;
cin>>n;
 vector<node>g[n];
 vector<Edge>e;
cin>>en;
for(int i=0;i<en;i++){
    int row,col,weight;
    cin>>row>>col>>weight;
    ///graph input
    temp.key=col;
    temp.weight=weight;
    g[row].push_back(temp);
    ///edge
    edge.u=row;
    edge.v=col;
    edge.weight=weight;
    e.push_back(edge);

    if (!is_directed){
    temp.key=row;
    g[col].push_back(temp);




    edge.u=col;
    edge.v=row;
    e.push_back(edge);
    }

}
int source=2;
if (Bellman_ford(e,n,source)){
    cout<<"works perfectly "<<endl;
}
else{

    cout<<"neg or positive cycle found  "<<endl;
}
}
