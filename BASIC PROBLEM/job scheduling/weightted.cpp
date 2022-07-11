#include<iostream>
#include<stdio.h>
using namespace std;
struct R{
    int start;
    int endd;
    int profit;
};
R arr[100];
int n;
void bubble_sort(){
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j].endd<arr[i].endd){
            R tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            }
        }
     }

}


int find_pos(int index){
         int lo=0,hi=index-1,ans=-1;
         while(lo<=hi){
             int mid=(lo+hi)/2;
             if(arr[mid].endd<=arr[index].start){
                   lo=mid+1;
                   ans=mid;
             }
             else{
                hi=mid-1;
             }
         }
         return ans;

 }

void job_schdule(){

    int ans=0;
    int res[100]={0};
    res[0] = arr[0].profit;
    for(int i=1;i<n;i++){
          int in = find_pos(i);
          int cur = arr[i].profit;
          if(in!=-1){
            cur+=res[in];
          }
          res[i]=max(res[i-1],cur);
    }
    cout<<res[n-1]<<endl;
}

int main()
{

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].start,&arr[i].endd,&arr[i].profit);
    }
    bubble_sort();
    job_schdule();

}
