#include<iostream>
using namespace std;


int main()
{
    int t,cs=1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int val[n+5];
        for(int i=0;i<n;i++) cin>>val[i];
         int ans[n+5];
        int adj[n+5][n+5];
        for(int i=0;i<n;i++){
             ans[i]=0;
            for(int j=0;j<n;j++){
                adj[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u][v]=1;
        }
        int mx=n*n+5;
        int q[mx],f=0,r=-1;
        q[++r]=0;
        ans[0]=val[0];
        while(f<=r){
            int cur=q[f++];
            for(int i=0;i<n;i++){
                if(adj[cur][i]==1){
                    ans[i]=max(ans[i],ans[cur]+val[i]);
                    q[r++]=i;
                }
            }
        }

        int nd,res=0;
        for(int i=0;i<n;i++){
             if(ans[i]>res){
                res=ans[i];
                nd=i;
             }
        }
       cout<<"case "<<cs++<<": "<<res<<" "<<nd<<endl;
    }
}

