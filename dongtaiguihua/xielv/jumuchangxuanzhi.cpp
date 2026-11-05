#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
ll d[N],s[N];
ll q[N];
int head,tail;
inline ll Y(ll a){
    return d[a]*s[a];
}
int main(){
    int n,i,j;
    ll ma=0,ss=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&q[i],&d[i]);
        s[i] = s[i-1]+q[i];
    }
    for(i=n;i>=1;i--){
        d[i] += d[i+1];
        ss += d[i]*q[i];
    }
    head=tail=1;q[tail]=0;
    for(j=1;j<=n;j++){
        while(head<tail && (Y(q[head+1])-Y(q[head]))>=d[j]*(s[q[head+1]]-s[q[head]])){head++;}
        ma = max(ma,Y(j)+Y(q[head])-d[j]*s[q[head]]);
        while(head<tail && (Y(q[tail])-Y(q[tail-1]))*(s[j]-s[q[tail]])<=(Y(j)-Y(q[tail]))*(s[q[tail]]-s[q[tail-1]])){tail--;}
        q[++tail]=j;
    }
    printf("%lld",ss-ma);
    return 0;
}
