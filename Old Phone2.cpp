///......................................///
///......... Name : Misu Dey  ...........///
///......... University: CUET ...........///
///......... Id : 1404108     ...........///
///......................................///


/*

1
5 3 5
1 2 4 6 0
1 2 3
5

ans: 4




3
6 4 5
1 2 4 6 9 8
1 2 3 4
91
6 3 6
0 1 3 5 7 9
1 2 4
28
5 2 10
1 2 6 7 8
2 3
981

Ans:
2
5
9

*/
#include<iostream>
#define ll long long int
using namespace std;
ll n,m,lim,x,make;
ll ope[10],a[110], dist[10010];
void calc(ll num,ll op,ll prev)
{
    if(num==992 || num==62) cout<<dist[num]<<' '<<num<<' '<<op<<' '<<prev<<endl;
    if(num>10000 || op>lim) return;
    if(dist[num]<=op) return;
    if(num==make)
    {
        //cout<<"Yo ! "<<dist[num]<<endl;
        if(prev!=-1) op++;
        if(dist[num]>op) dist[num]=op;
        return;
    }
    ll cr=num;
    dist[num]=op;

    if(num==0) return;

    if(prev==-1) for(ll i=0;i<n;i++) calc(cr*10+a[i],dist[cr]+1,prev);
    //cout<<"Found"<<cr<<endl;
    for(ll i=0;i<n;i++)
    {
        if(!a[i]) continue;
        if(ope[1]==1)
        {
            ll tmp=a[i], cnt=2;
            while(1)
            {
                if(tmp+cr>10000) break;
                calc(tmp+cr,op+cnt,1);
                cnt++; tmp*=10; tmp+=a[i];
            }
        }
        if(ope[2]==1)
        {
            ll tmp=a[i], cnt=2;
            while(1)
            {
                if(tmp>=cr)
                {
                if(tmp-cr<0 || (tmp-cr)>10000) break;
                calc(tmp-cr,op+cnt,4);
                }
                else
                {
                if(cr-tmp<0 || (cr-tmp)>10000) break;
                calc(cr-tmp,op+cnt,4);
                }
                cnt++; tmp*=10; tmp+=a[i];
            }
        }
        if(ope[3]==1)
        {
            if(prev==1 || prev==2) return;
            ll tmp=a[i], cnt=2;
            while(1)
            {
                if(tmp*cr>10000) break;
                calc(tmp*cr,op+cnt,3);
                cnt++; tmp*=10; tmp+=a[i];
            }
        }
        if(ope[4]==1)
        {
            if(prev==1 || prev==2) return;
            ll tmp=a[i], cnt=2;
            while(1)
            {
                if(tmp>=cr)
                {
                if(tmp%cr || (tmp/cr)>10000) break;
                calc(tmp/cr,op+cnt,4);
                }
                else
                {
                if(cr/tmp || (cr/tmp)>10000) break;
                calc(cr/tmp,op+cnt,4);
                }
                cnt++; tmp*=10; tmp+=a[i];
            }
        }
    }

}

int main()
{
    ll t; cin>>t;
    while(t--)
    {
        cin>>n>>m>>lim;
        for(int i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<=10000;i++) dist[i]=1e9;
        for(ll i=1;i<=4;i++) ope[i]=0;
        for(int i=0;i<m;i++)
        {
            cin>>x;
            ope[x]++;
        }
        cin>>make;
        ll tm=make, ck=0, real=0;
        while(tm)
        {
            ll rem=tm%10;
            real++;
            for(ll j=0;j<n;j++)
            {
                if(rem==a[j]) ck++;
            }
            tm/=10;
        }
        if(real==ck) dist[make]=ck;
        for(ll i=0;i<n;i++) calc(a[i],1,-1);
        cout<<dist[make]<<endl;


    }

}
