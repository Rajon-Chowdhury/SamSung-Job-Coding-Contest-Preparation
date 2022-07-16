
/// This problem is based on profit so we will try to maximize but if price is given than we will try to minimize


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



vector<pair<int,int>>v;
typedef pair<int,int> pr;

bool cmp(pr a,pr b){

    return a.second*b.first > b.second * a.first;
}

int main(){
      int weight,n,profit;
      cin>>n;

      for(int i=1;i<=n;i++){
        cin>>weight>>profit;
        v.push_back({weight,profit});
      }
      sort(v.begin(),v.end(),cmp);

      for(int i=0;i<n;i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;

      int w,z;
      cin>>w;
      double ans=0;
      for(int i=0;i<n;i++){
            //cout<<v[i].first<<" "<<w<<endl;
            if(w>=v[i].first){
                ans+=v[i].second;
                w-=v[i].first;
                continue;
            }
            double vw=(double)v[i].second/v[i].first;
            ans+=vw*w;
            w=0;
            break;
      }
      cout<<ans<<endl;
}

