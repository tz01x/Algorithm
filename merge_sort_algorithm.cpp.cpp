/**

#include<bits/stdc++.h>
using namespace std;
bool func(int i,int j){return (i>j);}
void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << " " << *it;
    cout << '\n';
}

list<int> divides_(int *arr,int start,int size_){
if(start==size_){
    return {arr[size_]};
}
int p=(start+size_)/2;
list<int> x=divides_(arr,start,p);
list<int> y=divides_(arr,p+1,size_);
x.sort();
y.sort();
x.merge(y);
return x;
}
//list<int> add(){
//return {5,8};
//}
int main(){
int coin[]={5,4,3,2,1,56,7,6,959,9,566,962,65,956,95,1,7,6,6,2,9,296,2,6};
int size_=sizeof(coin)/sizeof(coin[0]);
//list<int> a=add();
list<int> a=divides_(coin,0,size_-1);
showlist(a);
//int a=4;
//int b=5;
//int c=(a<b)?0:111;
//cout<< c <<endl;

}
**/
#include<iostream>
using namespace std;
void swapping(int &a, int &b)       //swap the content of a and b
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void display(int *array, int size)
{
    for(int i = 0; i<size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void mergeSort(int *array, int l, int r)
{
    int m;
    if(l < r)
    {
        int m = l+(r-l)/2;
        // Sort first and second arrays
        mergeSort(array, l, m);
        mergeSort(array, m+1, r);

        int i, j, k, nl, nr;

        nl = m-l+1;
        nr = r-m;
        int larr[nl], rarr[nr];

        for(i = 0; i<nl; i++)
            larr[i] = array[l+i];
        for(j = 0; j<nr; j++)
            rarr[j] = array[m+1+j];
        i = 0;
        j = 0;
        k = l;

        while(i < nl && j<nr)
        {
            if(larr[i] <= rarr[j])
            {
                array[k] = larr[i];
                i++;
            }
            else
            {
                array[k] = rarr[j];
                j++;
            }
            k++;
        }
        while(i<nl)
        {
            array[k] = larr[i];
            i++;
            k++;
        }
        while(j<nr)
        {
            array[k] = rarr[j];
            j++;
            k++;
        }
    }
}
int main()
{
    int n;

    cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }


    mergeSort(arr, 0, n-1);

    display(arr, n);
}

