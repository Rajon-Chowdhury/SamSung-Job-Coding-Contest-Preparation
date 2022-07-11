#include<iostream>
#include<cmath>
using namespace std;

struct R{
    int stx,sty,enx,eny,cost;
};
R arr[20];
int n;
int sx,sy,dx,dy;

int dis(int a,int b,int c,int d){
   return abs(a-c)+abs(b-d);
}


int func(int msk,int lstx,int lsty,int sum){
    if(__builtin_popcount(msk)==n){
        return sum+dis(dx,dy,lstx,lsty);
    }
    int cur=1e9;
    for(int i=0;i<n;i++){
        if(!(msk&(1<<i))){
            cur=min(cur,func(msk|(1<<i),arr[i].enx,arr[i].eny,sum+dis(lstx,lsty,arr[i].stx,arr[i].sty)+arr[i].cost));
            cur=min(cur,func(msk|(1<<i),arr[i].stx,arr[i].sty,sum+dis(lstx,lsty,arr[i].enx,arr[i].eny)+arr[i].cost));
        }
    }
    cur=min(cur,sum+dis(lstx,lsty,dx,dy));
    return cur;
}

int main()
{

    int t;
    cin>>t;
    while(t--){
           cin>>n;

           cin>>sx>>sy>>dx>>dy;
           for(int i=0;i<n;i++){
               cin>>arr[i].stx>>arr[i].sty>>arr[i].enx>>arr[i].eny>>arr[i].cost;
           }
           cout<<func(0,sx,sy,0)<<endl;

    }
}

