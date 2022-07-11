///  Ex: input - 1,2,3,4,6 Output -
///  The maximum length possible is 8. Pipe1 - 2,6 Pipe2 - 1,3,4

/*
Given number of pipes 1..n, Find two largest pipes of maximum length possible.
Ex: input - 1,2,3,4,6
Output - The maximum length possible is 8.
Pipe1 - 2,6
Pipe2 - 1,3,4

*/

#include<bits/stdc++.h>
using namespace std;

const int mx=100005;
int n,pipe[mx],tot=0,mn=INT_MAX,ans=0;

void func(int pos,int cur){
     if(pos==n+1){

        int fst=tot-cur;
        int sec=cur;
        int x=abs(fst-sec);
        if(x<mn){
            mn=x;
            ans=max(fst,sec);
        }
        return;
     }

     func(pos+1,cur+pipe[pos]);
     func(pos+1,cur);

}

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>pipe[i],tot+=pipe[i];
    func(1,0);
    cout<<ans<<endl;

}

/*
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int A[1000];
int mini,ans,tot;

int ABS(int x)
{
    if(x<;0)
        x=-1*x;
    return x;
}

int MAX(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int solve(int i,int curr,int n)
{
    if(i==n)
    {
        int x=ABS(tot-2*curr);
        if(x<mini)
        {
            mini=x;
            ans=MAX(curr,tot-curr);
        }
        return 1;
    }
    if(dp[i][curr]!=-1)
        return dp[i][curr];
    return dp[i][curr]=solve(i+1,curr+A[i],n)+solve(i+1,curr,n);
}

int main()
{
	int n;
    cin>>n;
    mini=INT_MAX;
    ans=tot=0;
    for(int i=0;i<n;i++){
        cin>>A[i];
        tot+=A[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }
    solve(0,0,n);
    cout<<ans;
}
*/

