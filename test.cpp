#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
float arrival[n],departure[n];
for(int i=0;i<n;i++){
    cout<<"arrival departure"<<endl;
    cin>>arrival[i]>>departure[i];
}
sort(arrival,arrival+n);
sort(departure,departure+n);
int t=0,p=0;
for(int i=0,j=0;i<n;i++){
//    cout<<"arrival departure"<<endl;
//    cout<<arrival[i]<<" "<<departure[i]<<endl;
if(arrival[i]<departure[j]){
   t++;
   p=max(t,p);

}else{
t--;
j++;
}

}
cout<<p<<endl;
}
