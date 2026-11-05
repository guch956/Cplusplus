#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
ll dp[15][15];
int num[15],shuzi;
ll dfs(int pos,ll sum,bool lead,bool limit){
    if(!pos){return sum;}
    if(!lead && !limit && dp[sum][pos]!=-1){return dp[sum][pos];}
    int i,now = limit?num[pos]:9;
    ll ans=0;
    for(i=0;i<=now;i++){
        if(i==0 && lead){ans+=dfs(pos-1,sum,true,limit && i==num[pos]);}
        else if(i==shuzi){ans+=dfs(pos-1,sum+1,false,limit && i==num[pos]);}
        else{ans+=dfs(pos-1,sum,false,limit && i==num[pos]);}
    }
    if(!lead && !limit){
        dp[sum][pos]=ans;
    }
    return ans;
}
ll jisuan(ll x){
    int len=0;
    while(x){
        len++;
        num[len]=x%10;
        x = x/10;
    }
    return dfs(len,0,1,1);
}
int main(){
    ll a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    for(shuzi=0;shuzi<=9;shuzi++){
        cout<<jisuan(b)-jisuan(a-1)<<' ';
    }
    return 0;
}
