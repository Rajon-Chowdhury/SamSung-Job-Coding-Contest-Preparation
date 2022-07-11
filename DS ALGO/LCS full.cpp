#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int main(){
    int n,m,i,j;
    string s1,s2;
    cin>>s1>>s2;
    n=s1.length(),m=s2.length();
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0)dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    printf("%d\n",dp[n][m]);
    string s3;
    while(i>0&&j>0){///ei line theke bujtesinah
        if(s1[i-1]==s2[j-1]){
            s3+=s1[i-1];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])i--;
        else j--;
    }
    reverse(s3.begin(),s3.end());
    cout<<s3<<endl;
    return 0;
}

