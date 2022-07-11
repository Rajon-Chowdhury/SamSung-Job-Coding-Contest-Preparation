#include<iostream>
using namespace std;
int a[110], num[110]; int n;
void permuta(int pos, bool vis[], int nodes)
{
    if(nodes==n) { for(int i=1;i<=n;i++) cout<<num[i]<<' '; cout<<endl; return; }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            num[nodes+1]=a[i];
            permuta(i, vis, nodes+1);
            vis[i]=false;
        }
    }
}
int main()
{
    int t; cin>>t;
    while(t--)
    {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool vis[110];
    for(int i=1;i<=100;i++) vis[i]=false, num[i]=0;
    permuta(0,vis,0);
    }


}
