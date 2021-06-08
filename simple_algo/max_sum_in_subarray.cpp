/******************************************************************************

The maximum-sum
subarray of this array is
[2, 4, −3, 5, 2], whose sum
is 10

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;
typedef struct node{
    int ti,tii,q;
}node;
int main()
{
    int arr[]={-1,2,4,-3,5,2,-5,2};
    int n=sizeof(arr)/4;
    int ti=-1,tii=-1;
    int q=0;
  
    std::vector<node> subarrytracker;
    for(int i=0;i<n;i++){
        
        
        if( arr[i]+q>0){
            if(ti==-1){
                ti=i;
            }
           
            if(arr[i]<0){
                subarrytracker.push_back({ti,tii,q});
            }
            tii=i;
            q=arr[i]+q;
            cout<<arr[i]<<" ";
        }else{
            subarrytracker.push_back({ti,tii,q});
            ti=-1;
            q=0;
        }
    }
    cout<<endl;

    for(int i=0;i<subarrytracker.size();i++){
        cout<<subarrytracker[i].ti<< " " ;
           cout<<subarrytracker[i].tii<<" ";
              cout<<subarrytracker[i].q<<" ";
              cout<<endl;
    }
    return 0;
}
/**

int best = 0, sum = 0;
for (int k = 0; k < n; k++) {
sum = max(array[k],sum+array[k]);
best = max(best,sum);
}
cout << best << "\n";

*/
