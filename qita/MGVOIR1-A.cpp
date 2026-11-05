#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll num[15];
ll mi[15];
ll dfs(int l,bool need){
    if(l==1){
        if(need){return 11-num[1];}
        return 1-(num[1]&1);
    }
    ll ans;
    if(need){
        ans = mi[l-1]*(10-num[l]);
        return ans+dfs(l-1,1);
    }
    else{
        return dfs(l-1,!(num[l]&1));
    }
} 
ll solve(ll x){
    int len=0;
    while(x){
        num[++len]=x%10;
        x = x/10;
    }
    return dfs(len,0);
}
int main(){
    int T,i;
    ll n;
    //freopen("5.in","r",stdin);
    mi[0]=1;
    for(i=1;i<=15;i++){mi[i]=mi[i-1]*10;}
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        printf("%lld\n",solve(n));
    }
    return 0;
}