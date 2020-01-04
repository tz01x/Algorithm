#include<iostream>
using namespace std;
int arr[50][50];
int mark[50][50];
int visited[50][50];
void display_mark(int n){
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

        cout<<mark[i][j]<<" ";
    }
    cout<<endl;
}
}
void display_arr(int n){
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
}
bool dapthfirst(int i,int j,int n,int dx,int dy){
if(i>=n||j>=n||i<0||j<0){

    return false;
}

if(i==dx && j==dy){
   mark[i][j]=1;
    return true;
}
visited[i][j]=1;
// mark this path or block as visited
bool p1=false,p2=false,p3=false,p4=false;
if(j+1<n&&arr[i][j+1]==1){
        if(visited[i][j+1]==0){
            p1=dapthfirst(i,j+1,n,dx,dy);
            if(p1)
             {
                 mark[i][j]=1;

                  return true;

             }
        }


}

if(j-1>=0 && arr[i][j-1]==1){

    if(visited[i][j-1]==0){
             p2=dapthfirst(i,j-1,n,dx,dy);
             if(p2)
             {
                 mark[i][j]=1;

 return true;
             }
        }
}

if(i-1>=0&&arr[i-1][j]==1)
{
    if(visited[i-1][j]==0){
             p3=dapthfirst(i-1,j,n,dx,dy);
             if(p3)
             {
                 mark[i][j]=1;

 return true;
             }
        }
}

if(i+1<n&&arr[i+1][j]==1)
{
    if(visited[i+1][j]==0){
            p4=dapthfirst(i+1,j,n,dx,dy);
            if(p4)
             {

                 mark[i][j]=1;
                 return true;

             }
        }
}



return false;


}
int main(){

int n=4;

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        arr[i][j]=1;
        visited[i][j]=0;
    }
}

arr[0][1]=0;
arr[0][2]=0;
arr[0][3]=0;

arr[2][2]=0;
arr[2][3]=0;

arr[2][0]=0;

display_arr(n);
dapthfirst(0,0,n,3,3);
cout<<endl;
display_mark(n);


}
