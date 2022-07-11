//https://www.geeksforgeeks.org/merge-sort/


#include<bits/stdc++.h>
#define ll long long
#define ios ios_base::sync_with_stdio(false)
#define pii pair<int, int>
#define fs first
#define sc second

using namespace std;

const ll INF=(1ll<<62)-1;
const int M=1e5+5;
int ar[M];

void merge(int ar[],int l,int m,int r)
{
    //int m=l+(r-l)/2;

    int n1=m-l+1;

    int n2=r-m;

    int L[n1],R[n2];

    int i=0,j=0,k=l;

    for(int i=0;i<n1;i++)L[i]=ar[i+l];

    for(int j=0;j<n2;j++)R[j]=ar[j+m+1];

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            ar[k]=L[i];
            i++;
        }

     else {

            ar[k]=R[j];
            j++;
    }
    k++;
}

 while(i<n1){
    ar[k]=L[i];
    i++;
    k++;
 }


 while(j<n2){
    ar[k]=R[j];
    j++;
    k++;
 }

}

void mergesort(int ar[],int l,int r)
{
    if(l<r){
    int m=l+(r-l)/2;
    mergesort(ar,l,m);
    mergesort(ar,m+1,r);

    merge(ar,l,m,r);

    }
}

 int main()
    {
        ios;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>ar[i];

        mergesort(ar,0,n-1);

        for(int i=0;i<n;i++)cout<<ar[i]<<" ";
    }



