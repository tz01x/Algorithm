#include<bits/stdc++.h>


using namespace std ;
struct node
{
    int nd, weight ;
}temp;
struct myqueue
{
    int name, key ;
    bool flag ;
}Q[100];

vector<node> g[100] ;
int n ;
int dis[100], par[100] ;

int pop()
{
    int min = 1000000 ;
    int index ;
    for(int i = 0 ; i < n ; i++)
    {
        if(Q[i].key < min && Q[i].flag == true){
            min = Q[i].key ;
            index = i ;
        }
    }
    Q[index].flag = false ;
    return Q[index].name ;
}
bool isEmpty(){
    for(int i = 0 ; i < n ; i++){
        if(Q[i].flag)
		return false ;
    }
    return true ;
}
void Dijkstra(){
    while(!isEmpty()){
        int u = pop() ;
       // printf("u : %d\n", u) ;
        for(int i = 0 ; i < g[u].size() ; i++){
            node t = g[u][i] ;
            int v = t.nd ;
            int w = t.weight ;
          //  printf("v : %d w: %d\n", v, w) ;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w ;
                par[v] = u ;
                Q[v].key = dis[v] ;
            }
        }
    }

}
int main()
{

    int u, v, w, i ;
    int edge ;

    cout<<"n:";
    cin>>n;
    cout<<"r:";
    cin>>edge;
    for(i = 0 ; i < edge ; i++)
    {
        scanf("%d %d %d", &u, &v, &w) ;
        temp.nd = v ;
        temp.weight = w ;
        g[u].push_back(temp) ;
        temp.nd = u ;
        g[v].push_back(temp) ;
    }
    int tiger=0;
    cout<<"m:"<<endl;
    cin>>tiger;
    int min_dis_travel=99999;
    int mayor_win=-1;
    for (int mayor=0;mayor<n;mayor++){
        if(tiger==mayor){
            continue;
        }
        for(i = 0 ; i < n ; i++)
    {
        dis[i] = 99999 ;
        par[i] = -1 ;
    }

    int src = mayor ;
    dis[src] = 0 ;
    for(i = 0 ; i < n ; i++){
        Q[i].name = i ;
        Q[i].key = dis[i] ;
        Q[i].flag = true ;
    }
    Dijkstra() ;

    if(min_dis_travel>dis[tiger]){
        min_dis_travel=dis[tiger];
        mayor_win=mayor;

    }


    }

    cout<<" mayor in city "<<mayor_win<<" will capture first"<<endl;


    return 0 ;
}


/**
4
4
0 1 7
2 3 5
0 3 10
2 1 1
2


*/



