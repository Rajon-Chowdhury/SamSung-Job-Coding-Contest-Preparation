#include<iostream>
using namespace std;
void allposssiblesubset(int a[],int cur,int sum,int n){
          if(cur==n){
            cout<<sum<<endl;
            return;
          }
          allposssiblesubset(a,cur+1,sum,n);
          allposssiblesubset(a,cur+1,sum+a[cur],n);


}
int main(){
      int a[]={1,2,3};
      int n=sizeof(a)/sizeof(a[0]);
      allposssiblesubset(a,0,0,n);
}
