#include<algorithm>
#include<utility>
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> pr;

vector<pr>v;

bool compare(pr a,pr b)
{
    return a.second*b.first>b.second*a.first;
}

void knapsack()
{
    int weight, n ,price;
    cout<<"Number of items : ";
    cin>>n;

    for(int i=1;i<=n;i++){
            cout<<i<<"th items weight and price are: ";
        cin>>weight>>price;
        v.push_back(pr(weight,price));
    }

    sort(v.begin(),v.end(),compare);

    int w,z;
    cout<<"Remaining space in knapsack : ";
    cin>>w;
    int ans=0;
    for(int i=1;i<=n;i++){
        z=min(w,v[i].first);
        w-=z;
        ans+=z*(v[i].second)/v[i].first;
    }

    cout<<"Minimum cost: "<<ans<<endl;

}

int main()
{
    knapsack();
    return 0;

}

