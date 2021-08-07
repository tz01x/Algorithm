#include<iostream>
using namespace std;
int main()
{
    int val[4] = { 12,10,20,15};
    int wt[4] = { 2,1,3,2};
    int p[100][100]={0};
    int W = 5;
    int n = 4;

    if(n==0||W==0)
    {
        return 0;

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(j>=wt[i-1])
            {
                p[i][j]= max(val[i-1]+p[i-1][j-wt[i-1]],p[i-1][j]);
            }
            else
            {
                p[i][j]=p[i-1][j];
            }
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }

    int i=n;
    int j=W;

    while(i!=0 and j!=0){

        if(j>=wt[i-1]){
            if(p[i][j]!=p[i-1][j]){

            j=j-wt[i-1];
            //cout<<j<<" "<<wt[i-1]<<endl;
           cout<<i<<" ";
            }
        }
            i--;
    }





}
