#include<bits/stdc++.h>
using namespace std;
#define MAX 10010
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
vector<bool>taken;
priority_queue<iii>pq;
vector<ii>adjlist[MAX];
void process(int vtx){
    taken[vtx]=true;
    for(int j=0;j<(int)adjlist[vtx].size();j++){
        ii v=adjlist[vtx][j];
        if(!taken[v.first])pq.push(iii(ii(-v.second,-v.first),vtx));
    }
}
ii node[20];
int main(){
    //freopen("inP.txt","r",stdin);
    //freopen("outP.txt","w",stdout);
    int n,m,i,x,y,w,a=0;
    printf("Enter the number of nodes and edges : ");
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m);
    printf("Enter the edges and weight:\n");
    for(i=0;i<m;i++){
        scanf("%d %d %d",&x,&y,&w);
        printf("%d %d %d\n",x,y,w);
        adjlist[x].push_back(ii(y,w));
        adjlist[y].push_back(ii(x,w));
    }
    taken.assign(n,false);
    process(1);
    int p;
    int mst_cost=0;
    while(!pq.empty()){
        iii front=pq.top();
        pq.pop();
        p=front.second;
        int u=-front.first.second,w=-front.first.first;
        if(!taken[u]){
            mst_cost+=w;
            process(u);
            node[a++]=ii(p,u);
        }
    }
}

