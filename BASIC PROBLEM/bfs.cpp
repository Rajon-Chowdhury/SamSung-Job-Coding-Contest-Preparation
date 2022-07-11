#include<iostream>
#include<stdio.h>
using namespace std;
int adj[105][105];
int ans[100];
int q[100],f=0,r=-1;
int vis[100];


int main(){
      int n,k=1;
      scanf("%d",&n);
      for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&adj[i][j]);
        }
      }
      q[++r]=1;

      while(f<=r){
        int cur = q[f++];
        ans[k++]=cur;
        vis[cur]=1;
        for(int i=1;i<=n;i++){
            if(adj[cur][i]==1&&vis[i]==0){
                q[++r]=i;
            }
        }
      }
      for(int i=1;i<k;i++)
        printf("%d ",ans[i]);

}

