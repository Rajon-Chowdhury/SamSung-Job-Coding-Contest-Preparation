#include<iostream>
#include<cmath>
using namespace std;
int n,a[20][3];
int ox,oy,hx,hy;
int dis(int a,int b,int c,int d){
   return abs(a-c)+abs(b-d);
}

int func(int msk,int lstx,int lsty,int sum){
    if(__builtin_popcount(msk)==n){
        return sum+dis(hx,hy,lstx,lsty);
    }
    int cur=1e9;
    for(int i=0;i<n;i++){
        if(!(msk&(1<<i))){
            cur=min(cur,func(msk|(1<<i),a[i][0],a[i][1],sum+dis(lstx,lsty,a[i][0],a[i][1])));
        }
    }
    return cur;
}

int main(){
      for(int cs=1;cs<=10;cs++){

          cin>>n;

          cin>>ox>>oy>>hx>>hy;

          for(int i=0;i<n;i++){
              cin>>a[i][0]>>a[i][1];
          }
          int ans=func(0,ox,oy,0);

          cout<<"# "<<cs<<" "<<ans<<endl;

      }
}
