#include<iostream>
using namespace std;
#define ll long long

ll n,dp[20][1<<15],point[15];
ll setbit(int n,int i){
    n=n|(1LL<<i);
    return n;
}
ll checkbit(int n,int i){
    n=n&(1LL<<i);
    return n;
}
ll find_ans(int msk,int idx){
    if(msk==(1<<n)-1){
        return 0;
    }
    if(dp[idx][msk]!=-1){
        return dp[idx][msk];
    }
    ll rt,lt,mx=0LL;
    for(int i=0;i<n;i++){
        if(checkbit(msk,i)){
            continue;
        }
        rt=-1,lt=-1;
        for(int l=i-1;l>=0;l--){
            if(checkbit(msk,l)==0){
                lt=l;
                break;
            }
        }
        for(int r=i+1;r<n;r++){
            if(checkbit(msk,r)==0){
                rt=r;
                break;
            }
        }
        int temp;
        if(rt==-1&&lt==-1){ temp=point[i];}
        else if(rt==-1){ temp=point[lt];}
        else if(lt==-1){ temp=point[rt];}
        else { temp=point[lt]*point[rt];}
        mx=max(mx,temp+find_ans(setbit(msk,i),idx+1));
    }
    dp[idx][msk]=mx;
    return mx;
}
int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        for(int i=0;i<15;i++){
            for(int j=0;j<(1<<12);++j){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            cin>>point[i];
        }
        int ans=find_ans(0,0);
        cout<<ans<<endl;
    }
}

/*
#include<iostream>
using namespace std;
int n;
int a[15];
int ans=0;
void permutate(int index[],int l){
   if(l==n+1){
     int vis[n+1]={0};
     int sum=0;
     for(int i=1;i<=n;i++){
        int j=index[i];
        vis[j]=1;
        int lft=j-1,r=j+1,lv=0,rv=0;
          while(r<=n){
               if(vis[r]==0){
                   rv=a[r];
                   break;
               }
               r++;
          }
          while(lft>=1){
             if(vis[lft]==0){
                lv=a[lft];
                break;
             }
             lft--;
          }
          if(lv==0 && rv==0){
             sum+=a[j];
          }
          else{
            if(lv==0) sum+=rv;
            else if(rv==0) sum+=lv;
            else sum+=(lv*rv);
          }

     }
     ans=max(ans,sum);
     return;

   }
   for(int i=l;i<=n;i++){
        swap(index[l],index[i]);
        permutate(index,l+1);
        swap(index[l],index[i]);
   }
}

int main()
{
    cin>>n;
    int index[n+4];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        index[i]=i;
    }

    permutate(index,1);
    cout<<ans<<endl;


}
*/
