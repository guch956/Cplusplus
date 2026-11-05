#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int N=100003;
int n,m;
ll sum[N];
int dp[N<<2];
ll coin[20];
ll subs[N<<2];
int erfen(ll s){
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(sum[mid]<=s){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    return l;
}
void jisuan(){
    int i,k,j,a=(1<<m)-1,b;
    ll c;
    for(i=1;i<=a;i++){
        b = 1;
        for(j=1;j<=m;j++){
            if((b&i)>0){
                dp[i]=max(dp[i],erfen(sum[dp[i-b]]+coin[j]));
                subs[i]=subs[i-b]+coin[j];
            }
            b = b<<1;
        }
    }
    c = 0x3f3f3f3f3f3f3f3f;
    for(i=1;i<=a;i++){
        if(dp[i]==n){
            if(subs[i]<c){
                c = subs[i];
            }
        }
    }
    if(c==0x3f3f3f3f3f3f3f3f){
        cout<<-1;
    }
    else{
        cout<<subs[a]-c;
    }
}
int main(){
    int i;
    ll s;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++){
        scanf("%lld",&coin[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%lld",&s);
        sum[i]=sum[i-1]+s;
    }
    jisuan();
    return 0;
}
