//https://www.hackerearth.com/problem/algorithm/question-7-4/

#include<iostream>
using namespace std;

int qt[1000001][3];// Sum of NxM over all the test cases does not exceed 1000000. 10^6 er kom dile kintu run time khaba
int pipe[8][4]={{0,0,0,0},{1,1,1,1},{0,1,0,1},{1,0,1,0},{0,1,1,0},{0,0,1,1},{1,0,0,1},{1,1,0,0}};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int b,c;
        cin>>b>>c;
        int l;
        cin>>l;

        int front=0,rear=0;
        int ar[n+1][m+1];
        int vis[n+1][m+1];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>ar[i][j];
                vis[i][j]=0;
            }
        }

        int dir1[4]={0,-1,0,1};
        int dir2[4]={-1,0,1,0};

        qt[rear][0]=b;
        qt[rear][1]=c;
        qt[rear][2]=1;
        vis[b][c]=1;
        rear++;
        int ans=0;
        while(front != rear )
        {
            int x=qt[front][0];
            int y=qt[front][1];
            int z=qt[front][2];

            front++;

            if(ar[x][y]==0)continue;
            ans++;

            if(z==l)continue;

            for(int i=0;i<4;i++)
            {
                int ux=x+dir1[i];
                int uy=y+dir2[i];

                if(ux>=0 && uy>=0 && ux<n && uy<m && vis[ux][uy]==0
                   && pipe[ar[x][y]][i]==1 && pipe[ar[ux][uy]][(i+2)%4]==1){
                      //ans++;
                      vis[ux][uy]=1;
                      qt[rear][0]=ux;
                      qt[rear][1]=uy;
                      qt[rear][2]=z+1;

                      rear++;
                   }
            }
        }

        cout<<ans<<endl;
    }
}
