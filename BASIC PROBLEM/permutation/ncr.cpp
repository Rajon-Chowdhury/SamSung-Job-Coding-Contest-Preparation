#include<iostream>
using namespace std;
const int N =1000;
const int mod=1e9+7;
#define ll long long
ll fact[N+5];

ll modMul(ll a,ll b){
   return (a%mod * b%mod)%mod;
}
ll modPow(ll b,ll p){
  ll r=1;
  while(p){
     if(p&1LL) r=modMul(r,b);
     b=modMul(b,b);
     p>>=1LL;
  }
  return r;

}
ll modInverse(ll b){
   return modPow(b,mod-2);
}
ll modDiv(ll a,ll b){
   return modMul(a,modInverse(b));
}


void calc(){
     fact[0]=1;
     for(ll i=1;i<N;i++){
        fact[i] = modMul(fact[i-1],i);
     }

}
ll ncr(ll n,ll r){
     ll ans=modMul(fact[r],fact[n-r]);
      ans= modDiv(fact[n],ans);
      return ans;
}
int main(){
     calc();
     cout<<ncr(1,2)<<endl;
     cout<<ncr(5,5)<<endl;
     cout<<ncr(5,4)<<endl;
     cout<<ncr(5,3)<<endl;

}
