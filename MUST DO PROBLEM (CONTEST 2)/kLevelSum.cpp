#include<iostream>
using namespace std;

int main()
{
    int k;
    string s;
    cin>>k>>s;
    int n=s.size();
    int lev=-1,sum=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            lev++;
           }
        else if(s[i]==')'){
            lev--;
        }
        else{
            if(lev==k){
                int cur=0;
                while(isdigit(s[i])){
                    cur=cur*10 + (s[i]-'0');
                    i++;
                }
                sum+=cur;
                i--;
            }
        }
    }
    cout<<sum<<endl;
}
