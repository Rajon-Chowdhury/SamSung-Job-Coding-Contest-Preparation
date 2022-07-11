#include<iostream>
using namespace std;

int main()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    int cnt=-1,ans=0,cur=0,n;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='('){
          cnt++;
          cur=0;
        }
        else if(s[i]==')'){
            cnt--;
            cur=0;
        }
        else{
            cur+=(s[i]-'0');
            if(cnt==k&&(s[i+1]=='(' || s[i+1]==')')){
                ans+=cur;
            }
            cur*=10;
        }
    }
    cout<<ans<<endl;

}
