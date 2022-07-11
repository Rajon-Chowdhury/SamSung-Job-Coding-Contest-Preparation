#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int beg,int end)
{
    int pindex=beg;
    int pivot=a[end];

   for(int i=beg;i<end;i++){
        if(a[i]<=pivot){
             swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex],a[end]);
    return pindex;

}

int quicksort(int a[],int beg,int end)
{
    if(beg<end){
   int  pindex=partition(a,beg,end);
    quicksort(a,beg,pindex-1);
     quicksort(a,pindex+1,end);
    }

}

int main()
{
    int n,a[100],beg,end;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    beg=0;
     end=n-1;

    quicksort(a,beg,end);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
