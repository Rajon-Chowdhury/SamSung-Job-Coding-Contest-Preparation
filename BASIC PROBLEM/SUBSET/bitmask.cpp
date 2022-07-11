#include<iostream>
using namespace std;
void allposssiblesubset(int a[],int msk,int cur,int n){
          if(cur==n){
            for(int i=0;i<n;i++){
                if(msk&(1<<i)){
                    cout<<a[i]<<" ";
                }
            }
            cout<<endl;
            return;
          }
          allposssiblesubset(a,msk,cur+1,n);
          allposssiblesubset(a,msk|(1<<cur),cur+1,n);


}
int main(){
      int a[]={1,2,3};
      int n=sizeof(a)/sizeof(a[0]);
      allposssiblesubset(a,0,0,n);
}

