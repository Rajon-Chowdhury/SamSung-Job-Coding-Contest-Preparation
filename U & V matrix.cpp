///26

/* 8

1 1 1 0 1 0 1 0
0 0 1 0 1 0 1 0
1 1 1 0 1 1 1 0
0 0 0 0 0 0 0 0
1 1 1 0 1 1 1 0
1 0 0 0 1 0 1 0
1 1 1 0 1 0 1 0
0 0 0 0 0 0 0 0

8

1 1 0 0 1 0 1 0
0 0 1 0 1 0 1 0
1 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0
0 1 1 0 0 1 0 0
1 0 0 0 1 0 1 0
0 1 1 0 1 0 1 0
0 0 0 0 0 0 0 0


*/
#include<iostream>
#define ll long long int
using namespace std;
ll n,ans=0;
ll a[110][110];
ll u_0[]={1,0,1,1,0,1,1,1,1};
ll u_90[]={1,1,1,0,0,1,1,1,1};
ll u_180[]={1,1,1,1,0,1,1,0,1};
ll u_270[]={1,1,1,1,0,0,1,1,1};

ll v_0[]={1,0,1,1,0,1,0,1,0};
ll v_90[]={1,1,0,0,0,1,1,1,0};
ll v_180[]={0,1,0,1,0,1,1,0,1};
ll v_270[]={0,1,1,1,0,0,0,1,1};






bool check_u(ll st_row,ll en_row,ll st_col,ll en_col)
{
    ll ck=0, tm1=0, tm2=0, tm3=0, tm4=0;
    for(ll i=st_row;i<=en_row;i++)
    {
        for(ll j=st_col;j<=en_col;j++)
        {
            if(a[i][j]==u_0[ck]) tm1++;
            if(a[i][j]==u_90[ck]) tm2++;
            if(a[i][j]==u_180[ck]) tm3++;
            if(a[i][j]==u_270[ck]) tm4++;
            ck++;

        }
    }
    if(tm1==9 || tm2==9 || tm3==9 || tm4==9) return true;
    else return false;
}
bool check_v(ll st_row,ll en_row,ll st_col,ll en_col)
{
    ll ck=0, tm1=0, tm2=0, tm3=0, tm4=0;
    for(ll i=st_row;i<=en_row;i++)
    {
        for(ll j=st_col;j<=en_col;j++)
        {
            if(a[i][j]==v_0[ck]) tm1++;
            if(a[i][j]==v_90[ck]) tm2++;
            if(a[i][j]==v_180[ck]) tm3++;
            if(a[i][j]==v_270[ck]) tm4++;
            ck++;

        }
    }
    if(tm1==9 || tm2==9 || tm3==9 || tm4==9) return true;
    else return false;
}
bool check_col(ll j)
{
    for(ll i=0;i<n;i++)
    {
        if(a[i][j]==1) return false;
    }
    return true;
}
int main()
{
   ll n; cin>>n;
   for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) cin>>a[i][j];
   for(ll i=0;i<n-3;i++)
   {
       for(ll j=0;j<n-3;j++)
       {
           bool tmp1=check_u(i,i+2,j,j+2);
           bool tmp2=check_v(i,i+2,j,j+2);
           bool tmp=false;
           if(tmp1==true || tmp2==true) tmp=check_col(j+3);
           if(tmp==true) ans++;
           cout<<i<<' '<<j<<' '<<ans<<endl;
       }
   }
   cout<<ans;

}
