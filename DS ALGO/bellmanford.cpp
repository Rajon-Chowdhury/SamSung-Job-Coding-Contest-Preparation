///Bellman Ford
///Time Complexity : O(nm)
/* 5 7
   1 5 4
   1 3 5
   1 2 1
   2 4 1
   1 4 1
   4 3 1
   4 5 1
*/
#include<iostream>
#define ll long long int
using namespace std;
ll n,m,a[1010],b[1010],c[1010],ck=0;
ll dis[110];
ll ans=INT_MAX;
int main()
{
    cin>>n>>m;
    ll u,v,w;
    for(ll i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        a[ck]=u; b[ck]=v; c[ck]=w;
        ck++;
    }
    /// Bellman ford starts here
    dis[1]=0;
    for(ll i=2;i<=n;i++) dis[i]=INT_MAX;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<ck;j++)
        {
            u=a[j]; v=b[j]; w=c[j];
            if(dis[v]>dis[u]+w) dis[v]=dis[u]+w;
        }
    }
    for(ll i=1;i<=n;i++) cout<<dis[i]<<endl;
}
