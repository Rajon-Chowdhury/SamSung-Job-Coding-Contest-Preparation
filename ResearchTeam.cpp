#include<iostream>
using namespace std;
struct node
{
    int x;
    int y;
};
struct node rare[6];


int dis[20][20][5],visit[20][20],graph[20][20];
int size,n;

void init(){
    for(int i=0;i<=20;i++){
        for(int j=0;j<=20;j++){
            graph[i][j]=0;
            visit[i][j]=0;
            for(int k=0;k<=5;k++)
                dis[i][j][k]=-1;

        }

    }
}

bool isValid(int x,int y){

    return x>=0&&y>=0&&y<size&&x<size&&graph[x][y];
}



void dfs(int x,int y,int cost,int rth){
    //check korte hobe valid && graph[x][y] na ki
    if(!isValid(x,y)) return;
    // jodi visit kora hoye jai kom cost e kinto er theke beshi cost asche
    if(dis[x][y][rth]<cost&&visit[x][y]) return;

    visit[x][y]=1;
    dis[x][y][rth]=cost;

    dfs(x+1,y,1+cost,rth);
    dfs(x-1,y,1+cost,rth);
    dfs(x,y+1,1+cost,rth);
    dfs(x,y-1,1+cost,rth);




}



int main(){
    int testcase,test;
    cin>>testcase;
    for(test=1;test<=testcase;test++)
    {
        init();
        cin>>size>>n;
        for(int i=0;i<n;i++){
            cin>>rare[i].x>>rare[i].y;
            --rare[i].x;
            --rare[i].y;


        }

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
                cin>>graph[i][j];
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<size;j++){
                for(int k=0;k<size;k++)
                    visit[j][k]=0;
            }

            dfs(rare[i].x,rare[i].y,0,i);

        }

        int mn = 9999999;
 ///max of (i,j) theke kth rare element distance. Na hole rare elemnt shob ghulu kobar hobe na
 // then min of max
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++){

                if(graph[i][j]==0)
                    continue;
                int mx=-1;

                for(int k=0;k<n;k++){

                        if(dis[i][j][k]>mx)
                            mx = dis[i][j][k];



                }
                if(mn>mx)
                    mn = mx;


            }

        }

        cout<<"test#"<<test<<" "<<mn<<endl;






    }


}
