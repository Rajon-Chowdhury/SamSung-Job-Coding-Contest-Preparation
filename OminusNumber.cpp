#include<iostream>
using namespace std;
int del[20];

int omnious(int l,int r,int k,int n) {
    int ans=0;
    for(int num=l;num<=r;num++){
        int cur;
        int arr[10]={0},tt=0;
        while(cur>0){
            int r=cur%10;
            arr[r]++;
            cur/=10;
        }
        for(int i=0;i<n;i++){
            tt+=arr[del[i]];
        }
        if(tt<k){
            ans++;
        }
    }
    return ans;
}
int main()
{
   int testcase;
    cin>>testcase;
    while (testcase--)
    {
        int a,b,k,n;
        cin>>a>>b>>k;
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>del[i];
        }
      cout<<omnious(a,b,k,n);


    }

}
