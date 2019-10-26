 #include<iostream>
#include<vector>
#include <limits>
#include "priority_queue_with_key_value.h"
using namespace std;

//update_queue(int v){
//while(1){
//    node temp=
//}
//}
int infinity=numeric_limits<int>::max();

Dijkstra(vector<node> g[],int n,int s){
//    cout<<"workeing 14"<<endl;
    int d[n],p[n];
    for(int i=0;i<n;i++){
        d[i]=infinity;
        p[i]=-1;
    }
    d[s]=0;
    Priority_Queue q;
    for(int i=0;i<n;i++){
        q.push(i,d[i]);
    }
//     cout<<"workeing 25"<<endl;
    while(!q.is_empty()){
    node u=q.pop();/// v , Dis
    for (int i=0;i<g[u.key].size();i++){
            node v;
            v.key=g[u.key][i].key; /// v,W
            v.value=g[u.key][i].value; /// v,W
            cout<<"adj _  "<<v.key<<endl;

        if(d[v.key]>d[u.key]+v.value)
            {
                 cout<<" distance update _ "<<v.key<<endl;
                d[v.key]=d[u.key]+v.value;///distance + weight
                ///update distance
            vector<node>temp;
                ///update priority queue
                 while(!q.is_empty()){
                    cout<<"pop_ing ";
                    node t=q.pop();
                    cout<<t.key<<"  _ w->  "<<t.value<<endl;
                    cout<<"loking for "<<v.key<<endl;
                    if(v.key==t.key){
                            for(int i=0;i<temp.size();i++){
                                q.push(temp[i].key,temp[i].value);
                            }

                    break;
                    }else{
//                     q.push(t.key,t.value);
                    temp.push_back(t);
                    }

                 }
//                cout<< v.key<<endl;
                q.push(v.key,d[v.key]);

                p[v.key]=u.key;
                p[v.key]=u.key;
            }
    }

    }
    cout<<endl<<endl<<endl;
    for(int i=0;i<n;i++){
        cout<<d[i]<< " ";
    }cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<node>g[n];
    for(int i=0;i<n;i++){
        node temp;
        int row,col,w;
        cout<<"enter row col w "<<endl;
        cin>>row>>col>>w;
        temp.key=col;
        temp.value=w;
        g[row].push_back(temp);
        temp.key=row;
        g[col].push_back(temp);
    }
    int s=1;


   Dijkstra(g,n,s);
}
