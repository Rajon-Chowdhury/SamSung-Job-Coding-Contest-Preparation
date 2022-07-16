#include<iostream>
using namespace std;
int wt[50],val[50];
int dp[60][60];

int func(int n,int w){

    if(w<=0 || n<=0)
      return 0;

    if(dp[n][w]!=-1)
        return dp[n][w];

    if(wt[n-1]>w){
        dp[n][w]=func(n-1,w);
    }
    else
        dp[n][w]=max(func(n-1,w),func(n-1,w-wt[n-1])+val[n-1]);


    return dp[n][w];

}


int main()
{
    for(int i=0;i<55;i++)
        for(int j=0;j<55;j++)
          dp[i][j]=-1;
    int n,w;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    cin>>w;

    cout<<func(n,w)<<endl;

}
/*
#include<bits/stdc++.h>
using namespace std;
int weight[110],profit[110],dp[110][110*10];
bool taken[110];
int main(){
    //freopen("in.txt","r",stdin);
    int cap,n,i,j;
    scanf("%d %d",&n,&cap);
    for(i=1;i<=n;i++)scanf("%d %d",weight+i,profit+i);
    for(i=0;i<=cap;i++)dp[0][i]=0;
    for(i=1;i<=n;i++)dp[i][0]=0;
    for(i=1;i<=n;i++){
        for(j=0;j<=cap;j++){
            if(weight[i]<=j){
                if(profit[i]+dp[i-1][j-weight[i]]>dp[i-1][j])dp[i][j]=profit[i]+dp[i-1][j-weight[i]];
                else dp[i][j]=dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    printf("%d\n",dp[n][cap]);
    int k=cap;
    while(i>0&&k>0){
        if(dp[i][k]!=dp[i-1][k]){
            taken[i]=true;
            k-=weight[i],i--;
        }
        else i--;
    }
    printf("Taken items are : \n");
    for(i=0;i<=n;i++){
        if(taken[i])printf("%d %d\n",weight[i],profit[i]);
    }
    return 0;
}
*/

