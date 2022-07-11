/*
https://www.careercup.com/question?id=5740719907012608
https://stackoverflow.com/questions/39673898/divide-array-into-k-contiguos-partitions-such-that-sum-of-maximum-partition-is-m/39675396
http://ideone.com/r60yH4 - Sameer Code
https://www.careercup.com/question?id=5730470801702912
*/

/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil
mines adjacent to each other and not in between of each others.After distributing them compute the
difference of oil mines from the company getting highest and company getting lowest. This number
should be minimum.(then only the distribution can be termed as fair).
Input
2
2 4
6 13 10 2
2 4
6 10 13 2
output
5
1
*/

#include <iostream>
#include <climits>
using namespace std;

int companies, mines, ans;
int oilMines[50],vis[50];

void func(int pos,int mnV,int mxV,int sum,int cnt){

       if(vis[pos]){
       int nwMin = min(sum,mnV);
       int nwMax = max(sum,mxV);
       if(cnt==companies-1){
        ans=min(ans,nwMax-nwMin);
       }
        return;
       }
       vis[pos]=1;
       int nxtPos=(pos+1)%mines;

       func(nxtPos,mnV,mxV,sum+oilMines[pos],cnt);

       int nwMin = min(sum,mnV);
       int nwMax = max(sum,mxV);

       func(nxtPos,nwMin,nwMax,oilMines[pos],cnt+1);

       vis[pos]=0;

       return;
}

int main() {

	int t;
	cin >> t;
	while(t--){
        cin>>companies>>mines;

        for(int i=0;i<mines;i++){
            cin>>oilMines[i];
            vis[i]=0;
        }
        ans=INT_MAX;
        for(int i=0;i<mines;i++){
            func(i,INT_MAX,INT_MIN,0,0);
        }
        cout<<ans<<endl;

	}
}
