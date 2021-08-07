#include<iostream>
using namespace std;
int main()
{
    int numset[]={1,3,5,9,2};
    bool t[100][100] ;
    int sum, n ;
    n=sizeof(numset)/sizeof(numset[0]);

    int i, j ;
//    cin>>n;
//    for(i = 1 ; i <= n ; i++)
//    {
//        cin>>numset[i];
//    }
//    cin>>sum;
        sum=6;

    for(i = 1 ; i <= sum ; i++)
        t[0][i] = false ;
    for(i = 0 ; i <= n ; i++)
        t[i][0] = true ;
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 1 ; j <= sum ; j++)
        {
            if(j >= numset[i])
                t[i][j] = (t[i-1][j-numset[i]]) || (t[i-1][j]) ;
            else
                t[i][j] = t[i-1][j] ;
        }
    }

    if(t[n][sum] == true)
    {
        cout<<"Possible\n" ;


        //trace op


        i=n;
        j=sum;

        while(i!=0 or j!=0){

            if(j>=numset[i-1]){
                cout<<numset[i-1]<<" ";
                j=j-numset[i-1];

                i--;
            }else{
            i--;
            }
        }
    }

    else
    {
        cout<<"Not possible\n";

    }

}


