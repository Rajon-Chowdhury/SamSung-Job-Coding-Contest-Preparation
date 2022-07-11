#include<iostream>
#include<stdio.h>
using namespace std;
struct R{
    int dead;
    int profit;
};
R arr[100];
int n;
void bubble_sort(){
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j].profit>arr[i].profit){
            R tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            }
        }
     }

}
int flag[100];
void job_schdule(){

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>=1;j--){
            if(flag[j]==0){
                flag[j]=1;
                ans+=arr[i].profit;
                break;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&arr[i].dead,&arr[i].profit);
    }
    bubble_sort();
    job_schdule();

}
