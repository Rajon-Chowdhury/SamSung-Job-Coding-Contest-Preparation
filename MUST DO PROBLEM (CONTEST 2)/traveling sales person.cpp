
#include<iostream>
using namespace std;
int M[15][15];
int n;
int func(int pos,int msk,int lst,int sum){
      if(pos==n-1){
         return sum+M[lst][0];
      }
      int cur=1e9;
      for(int i=1;i<n;i++){
          if(!(msk&(1<<i))){
              cur=min(func(pos+1,msk|(1<<i),i,sum+M[lst][i]),cur);
          }
      }
      return cur;
}

int main(){
        int t;
        cin>>t;
        while(t--){
              cin>>n;
              for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cin>>M[i][j];
                }
              }
              cout<<func(0,0,0,0)<<endl;

        }

}
