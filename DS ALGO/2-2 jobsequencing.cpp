#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct JOB
{
    char id;
    int dead;
    int profit;
};
bool comparison(JOB a,JOB b)
{
    return(a.profit > b.profit);
}
void printJobscheduling(JOB arr[],int n)
{
    sort(arr,arr +n,comparison);

    int result[n];
    bool slot[n];

    for(int i=0;i<n;i++)
        {
            slot[i]=false;
        }
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].dead)-1;j>=0;j--)
        {
            if(slot[j]==false)
                {
                    result[j]=i;
                    slot[j]=true;
                    break;
                }
        }
    }
    for(int i=0;i<n;i++)
       {
            if(slot[i])
            cout<<arr[result[i]].id<<" ";
       }

}
int main()
{
    int n;
    scanf("%d",&n);
    JOB arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].id;
        cin>>arr[i].dead;
        cin>>arr[i].profit;
    }
    printJobscheduling(arr,n);
    return 0;
}

