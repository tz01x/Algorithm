#include<iostream>
using namespace std;
class graphColloring
{
private:
    int **arr;
    int numOfColor;
    int n;
    int *traceColor;
public:
    //constructor
    graphColloring(auto a,int n,int numOfColor)
    {
        this->n=n;
        this->numOfColor=numOfColor;

        //dynamically allocated a block memory of 'n' size
        traceColor=new int [n];
        //array copy
        arr=new int *[n];
        for(int i=0; i<n; i++)
        {
            //init the color array with -1 ;

            traceColor[i]=-1;
            arr[i] = new int[n];
            for(int j=0; j<n; j++)
            {
                arr[i][j]=a[i][j];
                //cout<<(arr[i][j])<<endl;
            }
        }


    }
    int StartGraphColloring(int startNode)
    {
        if(solve(startNode))
        {
            display();
        }
        else
        {
            cout<<"No fisible solution "<<endl;
        }
    }
    int solve(int nodeIndex)
    {
        if(nodeIndex==n)
        {
            return true;
        }
        for(int i=0; i<numOfColor; i++)
        {
            //checking current assign color is correct or not
            if(isValidColor(nodeIndex,i))
            {
                traceColor[nodeIndex]=i;
                return solve(nodeIndex+1);
            }
            //if its not right color assign new color


        }
        return false;
    }
    int isValidColor(int nodeIndex,int color)
    {

        for(int i=0; i<n; i++)
        {
            //if there is any eage between them

            if(arr[nodeIndex][i]==1)
            {
                //if both node has same color
                if(traceColor[i]==color)
                    return false;
            }
        }
        return true;

    }
    display(){
    for(int i=0;i<n;i++){
        cout<<traceColor[i]<<endl;
    }
    }


};
int main()
{
    int n=3;
    int a[3][3]= {{0,1,0},{1,0,1},{0,1,0}};
    graphColloring *g;
    g= new graphColloring(a,(int)n,1);
    g->StartGraphColloring(0);



}
