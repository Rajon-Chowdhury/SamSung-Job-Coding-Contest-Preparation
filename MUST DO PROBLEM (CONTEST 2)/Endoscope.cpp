#include<iostream>
using namespace std;
#include<queue>
int xx[]={0,0,1,-1};
int yy[]={-1,1,0,0};
int n,m;
struct R{
    int up,down,left,right;
};
R pipe[10];
void faka(){
      pipe[1].down=1,pipe[1].up=1,pipe[1].left=1,pipe[1].right=1;
      pipe[2].down=1,pipe[2].up=1;
      pipe[3].left=1,pipe[3].right=1;
      pipe[4].up=1,pipe[4].right=1;
      pipe[5].down=1,pipe[5].right=1;
      pipe[6].down=1,pipe[6].left=1;
      pipe[7].up=1,pipe[7].left=1;

}
int dis[55][55];
int a[55][55];
int vis[55][55];

bool func(int first_pipe ,int second_pipe,int type){

       if(first_pipe==0 || second_pipe==0) return 0;
       else if(type==0){
           if(pipe[first_pipe].left==1 && pipe[second_pipe].right==1){

                return 1;
           }
           return 0;
       }
       else if(type==1){
           if(pipe[first_pipe].right==1 && pipe[second_pipe].left==1)
            return 1;
           return 0;
       }
       else if(type==2){
             if(pipe[first_pipe].down==1 && pipe[second_pipe].up==1)
                return 1;
             return 0;
       }
       else{
              if(pipe[first_pipe].up==1 && pipe[second_pipe].down==1)
                return 1;
              return 0;
       }
}

void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
       auto it=q.front();
       x=it.first,y=it.second;
       q.pop();
   for(int i=0;i<4;i++){
       int nx=xx[i]+x,ny=yy[i]+y;
       if((nx<n && ny<m && nx>=0 && ny>=0) && vis[nx][ny]==0 && func(a[x][y],a[nx][ny],i)){
             dis[nx][ny]=min(dis[nx][ny],dis[x][y]+1);
             vis[nx][ny]=1;
             q.push({nx,ny});
       }
   }
    }
}
int main()
{
       faka();
       int t;
       cin>>t;
       while(t--){
           int x,y,l;
           cin>>n>>m>>x>>y>>l;

           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                dis[i][j]=1e5;
                vis[i][j]=0;
            }
           }
           int ans=0;
           dis[x][y]=1;
           vis[x][y]=1;
           bfs(x,y);
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dis[i][j]<=l){
                    ans++;
                }
            }
           }
           cout<<ans<<endl;

       }
}
