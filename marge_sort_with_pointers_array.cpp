#include<iostream>
#define loop(i,s,e) for(i=s;i<e;i++)
using namespace std;

int* marge_sort(int *arr,int n,int first_ele,int last_ele){

    if(first_ele==last_ele)
    {
        int *t= new int [2];
        t[0]=arr[first_ele];
        //cout<<"first_ele "<<arr[first_ele]<<endl;
        return t;

    }
    int povit=(first_ele+last_ele)/2;
    //cout<<povit<<endl;
    int *x=marge_sort(arr,n,first_ele,povit);
    int *y=marge_sort(arr,n,povit+1,last_ele);
    int i=0,j=0,k=0;
    int *marge;
    marge=new int [n+1];

    while(x[i]!=NULL and y[j]!=NULL){
        if(x[i]<y[j]){
            marge[k]=x[i];
            i++;
        }else{
         marge[k]=y[j];
         j++;
        }
        k++;
    }

    if(x[i]==NULL and y[j]!=NULL){
        while(y[j]!=NULL){
        marge[k]=y[j];
        j++;
        k++;
        }
    }else if(x[i]!=NULL and y[j]==NULL){
     while(x[i]!=NULL){
        marge[k]=x[i];
        i++;
        k++;
        }
    }
    return marge;
}


int main(){

int arr[100]={1,8,8,97,2,4,3,9,55,5,11,85,78,18,2,987,287,218,2718,117,14,2,77,8,22};
int n=sizeof(arr)/4;

int *sort_array= marge_sort(arr,n,0,n-1);
int i=0;

while(sort_array[i]!=NULL){
    cout<<sort_array[i]<<endl;
    i++;
}
//    loop( i,0,n){
//    cout<<arr[i]<<",";
//    }
//    cout<<endl;

}
