#include<bits/stdc++.h>
using namespace std;
bool check(int val,int pos){
     return (val&(1<<pos));
}
int col[55];
vector<int>gr[12];
int sum=0,mn=INT_MAX,curmsk;

bool cycle(int u){
     col[u]=0;
     sum+=u;
     for(auto v:gr[u]){
        if(col[v]==-1){
            if(cycle(v)){
                return 1;
            }
        }
        else if(col[u]==col[v]){
            return 1;
        }
     }
     col[u]=1;
     return 0;


}

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+5][m+5];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=1;
    }

    for(int msk=1;msk<(1<<n);msk++){
        int flag=1,st=-1;

        for(int i=1;i<=n;i++)
              gr[i].clear(),col[i]=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if(i==j) continue;
                if(check(msk,i)&&check(msk,j)){

                    if(a[i+1][j+1]==1){
                        gr[i+1].push_back(j+1);
                        st=i+1;

                    }
                }
            }
        }
        if(st!=-1){

            bool isCycle = cycle(st);
            if(isCycle){
                if(sum<mn){
                    mn=sum;
                    curmsk=msk;

                }
            }

        }
        sum=0;


    }
    for(int i=0;i<n;i++){
        if(check(curmsk,i)){
            cout<<i+1<<" ";
        }
    }
}
