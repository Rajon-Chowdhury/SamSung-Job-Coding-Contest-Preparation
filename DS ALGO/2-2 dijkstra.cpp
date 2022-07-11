#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define inf 1000000001
#define mx 100005
int d[mx] ,parent[mx], n , m  ;
vector < pii > adjlist[mx];
void dijkstra( int start ){
    int u , v , w , i , c ;
    priority_queue < pii , vector < pii > , greater < pii > > q;
    d[start] = 0 ;
    q.push( pii( 0 , start ) );
    while( !q.empty() ){
        u = q.top().second;
        c  = q.top().first;
        q.pop();
        for(i = 0 ; i < adjlist[u].size() ; i++ ){
            v = adjlist[u][i].first;
            w = adjlist[u][i].second;
            if( d[u] + w < d[v] ){
                d[v] = d[u] + w;
                parent[v] = u;
                q.push(pii(d[v],v));
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    int i,x  ;
    scanf("%d %d",&n,&m);
    for( i = 1 ; i<= n ; i++ )d[i] = inf;
    for( i = 0 ; i < m ; i++ ){
        int y, w;
        scanf("%d %d %d",&x,&y,&w);
        adjlist[x].push_back(pii(y,w));
        //adjlist[y].push_back(pii(x,w));
    }
    int st=1;
    dijkstra(st);
    for(int j=1;j<=n;j++){
        x=j;
        if(x==st)continue;
        vector<int>ans;
        ans.push_back(x);
        while(x){
            ans.push_back(parent[x]);
            x=parent[x];
        }
        printf("Path from %d to %d is : ",st,j);
        for(i=(int)ans.size()-2;i>0;i--)cout<<ans[i]<<" ";
        printf("%d\n",ans[0]);
        printf("Cost : %d\n",d[j]);
    }
    /*for(i = 1 ; i <= n ;i++ ){
        if(d[i] == inf ){
            printf("Can not reach \n");
        }
        else{
            printf("Shortest Distance from %d to %d is %d\n" , st , i , d[i] ) ;
        }
    }*/

    return 0;
}




