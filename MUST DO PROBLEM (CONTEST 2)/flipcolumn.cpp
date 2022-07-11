#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,m,k;
        cin>>n>>m>>k;
        int a[n+5][m+5];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        int ans=0;
        for(int msk=0;msk<(1<<m);msk++){
            int x=__builtin_popcount(msk);

            if(x>k || (k-x)%2==1) continue;
            int cur=0;
            for(int i=0;i<n;i++){
             int cnt=0;
            for(int j=0;j<m;j++){
                 bool val=(msk&(1<<j));
                 int xx;
                 if(val==1){
                    xx=1-a[i][j];
                 }
                 else{
                     xx=a[i][j];
                 }
                 cnt+=xx;
            }
            if(cnt==m) cur++;
        }
          ans=max(ans,cur);
        }
        cout<<ans<<endl;

}
