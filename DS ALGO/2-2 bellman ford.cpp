#include<bits/stdc++.h>
#define ll long long int
#define inf 188888
using namespace std;

struct Edges{
    ll u , v , w;
};

Edges  adj[205];
ll dis[205] , n , m;
ll node[205];

void bellman(ll src)
{
    ll i , j;
    for(i=0;i<n;i++)dis[i]=inf;
    dis[src] = 0;
    for( i = 1 ; i <=n-1 ; i++ ){
        for( j = 0 ; j < m ; j++ ){
            ll x = adj[j].u;
            ll y = adj[j].v;
            ll z = adj[j].w;
            if( dis[x]!=inf&&(dis[x]+z<dis[y])){
                dis[y] = dis[x] + z ;
            }
        }
    }
    bool flag=true;//buji nai , 2 bar keno?
    for(i=0;i<m;i++){
        ll x=adj[i].u;
        ll y=adj[i].v;
        ll z=adj[i].w;
        if(dis[x]!=inf&&(dis[x]+z<dis[y])){
            flag=false;
            break;
        }
    }
    if(flag){
       int q,des;
        cin >> q;
        for( i = 1 ; i <= q;i++ ){
            cin >> des;
            cout << "Dis[des] = "<<dis[des] << endl;
        }
    }
    else printf("Negative cycle\n");
}
int main()
{
    //freopen("input.txt", "r" , stdin );
    ll i , t , cs , x , y , w, des , q ;
    cin >>n>> m;
    for( i = 0 ; i< m ; i++ ){
        cin >> x >> y>>w ;
        adj[i].u = x;
        adj[i].v = y;
        adj[i].w = w;
    }
    bellman(0);
    return 0;
}

