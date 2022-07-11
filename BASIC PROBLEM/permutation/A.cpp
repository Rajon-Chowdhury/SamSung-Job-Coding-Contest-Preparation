#include<iostream>
using namespace std;


void swap(int &x ,int &y){
   int tmp=x;
   x=y;
   y=tmp;
}
void permutation(int a[],int l,int r){
   if(l==r){
    for(int i=0;i<=r;i++)
        cout<<a[i]<<" ";
        cout<<endl;
   }
   else{
   for(int i=l;i<=r;i++){
      swap(a[l],a[i]);
      permutation(a,l+1,r);
      swap(a[l],a[i]);
   }
   }
}

int main(){
      int a[]={1,2,3,4,5};
      int n = sizeof(a)/sizeof(a[0]);
      permutation(a,0,n-1);

}
