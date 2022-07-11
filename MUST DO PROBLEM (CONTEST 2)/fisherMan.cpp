#include<iostream>
#include<cmath>
using namespace std;

int ans=1e9;
int gate[4],people[4];

void permutate(int index[],int l,int r){
     if(l==r){
       int sum=0,cnta=0,cntb=0,cntc=0,vis[r+1]={0};
       for(int i=1;i<=r;i++){
         int j=index[i];
         if(vis[j]==0 && cnta<people[1]){
            sum+=abs(j-gate[1])+1;
            vis[j]=1;
            cnta++;
         }
       }
       for(int i=1;i<=r;i++){
         int j=index[i];
         if(vis[j]==0 && cntb<people[2]){
            sum+=abs(j-gate[2])+1;
            vis[j]=1;
            cntb++;
         }
       }
       for(int i=1;i<=r;i++){
         int j=index[i];
         if(vis[j]==0 && cntc<people[3]){
            sum+=abs(j-gate[3])+1;
            vis[j]=1;
            cntc++;
         }
       }
       ans=min(ans,sum);
       return;
     }
     for(int i=l;i<=r;i++){
        swap(index[l],index[i]);
        permutate(index,l+1,r);
        swap(index[l],index[i]);
     }


}

int main()
{
    int n;
    cin>>n;
    int index[n+5];
    for(int i=1;i<=n;i++) index[i]=i;
    for(int i=1;i<=3;i++) cin>>gate[i];

    for(int i=1;i<=3;i++) cin>>people[i];

    permutate(index,1,n);
    cout<<ans<<endl;


}
