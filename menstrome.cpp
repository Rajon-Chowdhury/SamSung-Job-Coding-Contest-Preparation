/*
Men's restroom problem: It is a well-researched fact that men in a restroom generally prefer
 to maximize their distance from already occupied stalls,
 by occupying the middle of the longest sequence of unoccupied places. For a detailed version, c
 heck the following link.

Link: https://stackoverflow.com/questions/32645046/urinal-algorithm-a-simple-optimization

Input:
1
10

Output:
_ _ _ _ X _ _ _ _ _

_ _ _ _ X _ _ X _ _

_ X _ _ X _ _ X _ _

_ X _ _ X _ _ X X _

_ X _ _ X X _ X X _

_ X X _ X X _ X X _

_ X X _ X X _ X X X

_ X X _ X X X X X X

_ X X X X X X X X X

X X X X X X X X X X

*/


#include<iostream>
using namespace std;
int a[100],n;

int findMid(){
   int cnt=0,mxcnt=0,index,mid;
   for(int i=0;i<n;i++){
       if(a[i]==1){
          if(cnt>mxcnt){
            mxcnt=cnt;
            index=i;
          }
          cnt=0;
       }
       else{
        cnt++;
       }
   }
   if(cnt>mxcnt){
      mxcnt=cnt;
      index=n;
   }

   mid=index+(index-mxcnt);


   return mid/2;

}


int main(){
    int testcase,test;
    cin>>testcase;
    for(test=1;test<=testcase;test++){
        cin>>n;

        for(int i=0;i<n;i++){
            a[i]=0;
        }
        for(int i=0;i<n;i++){
            int idx=findMid();
            a[idx]=1;
            for(int j=0;j<n;j++){
                if(a[j]==1)
                    cout<<"x";
                else
                    cout<<"-";
            }
            cout<<endl;
        }

    }
}

/*
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct s
{
    int distance;
    int start;
    int ending;
};
struct fn
{
    bool operator()(s const&a,s const &b)
    {
        if(a.distance!=b.distance)
        {
            return a.distance<b.distance;
        }
        return a.start<b.start;
    }
};
int main()
{
    int n;
    cin >> n;
    int mat[n] = {0};
    priority_queue<s,vector<s>,fn> q;
    struct s temp;
    int l=1,r=n,coun=1;
    q.push({n,l,r});
    while(!q.empty())
    {
        temp = q.top();
        q.pop();
        int left = temp.start;
        int right = temp.ending;
        int mid = (left+right)/2;
        if(temp.distance>0)
        {
            if(right>mid)
            {
                q.push({right-mid,mid+1,right}); // first push right child then left
            }
            if(left<mid)
            {
                q.push({mid-left,left,mid-1});
            }
        }
        mat[mid-1] = coun;
        coun++;
        for(int i=0; i<n; i++)
        {
            if(mat[i]==0)
            {
                cout << "_" << " ";
            }
            else
            {
                cout << "X" << " ";
            }

        }
        cout << endl;
    }

}


*/
