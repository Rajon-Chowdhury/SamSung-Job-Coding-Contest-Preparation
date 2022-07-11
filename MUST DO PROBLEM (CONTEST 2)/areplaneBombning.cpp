#include<iostream>
using namespace std;
#define sz 100
int graph[sz][5],n,ans=0;
int a[sz][5];

void init(){
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<5;j++)
        {
            graph[i][j]=0;
            a[i][j]=0;
        }
    }
}

void dfs(int row,int col,int temp){
      if(row<0) return;
      ans=max(ans,temp);

      for(int i=-1;i<=1;i++){
         if(col+i>=0&&col+i<5 && a[row-1][col+i]!=2)
            dfs(row-1,col+i,temp+a[row-1][col+i]);
      }
}

int func(int b){
      for(int i=0;i<n;i++){
        for(int j=0;j<5;j++)
            a[i][j]=graph[i][j];
      }
      for(int i=b;i<b+5;i++){
        for(int j=0;j<5;j++){
            if(graph[i][j]==2){
                a[i][j]=0;
            }
        }
      }
      ans=0;
      dfs(n,2,0);

      return ans;

}
int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        init();
        int result=0;
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++)
                cin>>graph[i][j];
        }
        for(int i=0;i<n;i++){
            result=max(result,func(i));
        }
        cout<<"#"<<test<<" "<<result<<endl;

    }
}
