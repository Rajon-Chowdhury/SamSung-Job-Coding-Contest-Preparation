#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+4][m+4],dis[n+4][m+4],dx=0,dy=0,sx,sy;
    sx=n-1,sy=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            dis[i][j]=1e9;

            if(a[i][j]==3){
                dx=i,dy=j;

            }
        }
    }

    queue<pair<int,int>>q;
    q.push({dx,dy});
    dis[dx][dy]=0;
    while(q.size()){
        auto it=q.front();
        q.pop();
        int curx=it.first;
        int cury=it.second;


        ///left
        for(int i=cury-1;i>=0;i++){
            if(a[curx][i]==0){
                break;
            }
            if(dis[curx][i]>dis[curx][cury])
              q.push({curx,i});
            dis[curx][i]=min(dis[curx][i],dis[curx][cury]);

         }
        ///right
        for(int i=cury+1;i<m;i++){
            if(a[curx][i]==0){
                break;
            }
           if(dis[curx][i]>dis[curx][cury])
              q.push({curx,i});

            dis[curx][i]=min(dis[curx][i],dis[curx][cury]);
        }

        ///down
        for(int i=curx+1;i<n;i++){
            if(a[i][cury]!=1) continue;
            int d=i-curx;
            int curmx=max(d,dis[curx][cury]);
            if(dis[i][cury]>curmx)
            q.push({i,cury});
            dis[i][cury]=min(dis[i][cury],curmx);

        }
        ///up
        for(int i=curx-1;i>=0;i--){
            if(a[i][cury]!=1) continue;
            int d=curx-i;
            int curmx=max(d,dis[curx][cury]);
            if(dis[i][cury]>curmx)
            q.push({i,cury});
            dis[i][cury]=min(dis[i][cury],curmx);
        }
    }

    cout<<dis[sx][sy]<<endl;


}
/*
int main()
{
    cin >> n >> m;
    int arr[n + 1][m + 1];
    map<pll, ll>mp;
    pair<ll, ll> idx;

    for (int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < m; j++)
        {
            cin >> arr[i][j];
            mp[ {i, j}] = inf;
            if (arr[i][j] == 3)
            {
                idx = {i, j};
            }
        }
    }
    counT = inf;

    queue<pll>Q;
    Q.push(idx);
    mp[idx] = 0;
    while (Q.size())
    {
        pll p = Q.front();
        Q.pop();

        /// left
        for (int i = p.S - 1 ; i >= 0; i--)
        {
            if (arr[p.F][i] == 0) break;
            if ( mp[ {p.F, i}] > mp[p] )
                Q.push({p.F, i});
            mp[ {p.F, i}] = min(mp[ {p.F, i}] , mp[p]);
        }
        /// right
        for (int i = p.S + 1 ; i < m; i++)
        {
            if (arr[p.F][i] == 0) break;
            if ( mp[ {p.F, i}] > mp[p]  )
                Q.push({p.F, i});
            mp[ {p.F, i}] = min(mp[ {p.F, i}] , mp[p] );
        }

        /// down
        for (int i = p.F + 1; i < n; i++)
        {
            d = abs(p.F - i);
            if (arr[i][p.S] != 1 ) continue;

            if (mp[ {i, p.S}] >  max(d, mp[p])  )
                Q.push({i, p.S});
            mp[ {i, p.S}] = min(mp[ {i, p.S}] , max(d, mp[p]) );
        }

        /// Up
        for (int i = p.F - 1; i >= 0; i--)
        {
            d = abs(p.F - i);
            if (arr[i][p.S] != 1 ) continue;

            if (mp[ {i, p.S}] >  max(d, mp[p])  )
                Q.push({i, p.S});
            mp[ {i, p.S}] = min(mp[ {i, p.S}] , max(d, mp[p]) );

        }



    }

    cout << mp[ {n - 1 , 0}] << endl;



}
*/
