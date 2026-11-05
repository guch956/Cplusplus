#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
ll c[N],x[N],sp[N],sxp[N];
ll dp[N];
int q[N],tail,head;
inline ll Y(int a){
    return dp[a]+sxp[a];
}
int main(){
    int n,i;
    ll a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld %lld",&x[i],&a,&c[i]);
        sp[i] = sp[i-1]+a;
        sxp[i] = sxp[i-1]+x[i]*a;
    }
    head=tail=1;q[tail]=0;
    for(i=1;i<=n;i++){
        while(head<tail && (Y(q[head+1])-Y(q[head]))<=(sp[q[head+1]]-sp[q[head]])*x[i]){head++;}
        dp[i]=Y(q[head])-x[i]*sp[q[head]]+x[i]*sp[i]-sxp[i]+c[i];
        if(sp[i-1]==sp[i]){dp[i]=min(dp[i],dp[i-1]);}
        while(head<tail && (Y(i)-Y(q[tail]))*(sp[q[tail]]-sp[q[tail-1]])<=(Y(q[tail])-Y(q[tail-1]))*(sp[i]-sp[q[tail]])){tail--;}
        q[++tail]=i;
    }
    printf("%lld",dp[n]);
    return 0;
}
