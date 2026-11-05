#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=50003;
ll sc1[N],L;
int q[N],head,tail;
ll dp[N];
inline ll X(int a){
    return 2*(sc1[a]+L);
}
inline ll Y(int a){
    return dp[a]+(sc1[a]+L)*(sc1[a]+L);
}
int main(){
    int n,i;
    ll a;
    scanf("%d %lld",&n,&L);
    L++;
    for(i=1;i<=n;i++){
        scanf("%lld",&a);
        sc1[i]=sc1[i-1]+a+1;
    }
    head=tail=1;q[tail]=0;
    for(i=1;i<=n;i++){
        while(head<tail && (Y(q[head+1])-Y(q[head]))<=sc1[i]*(X(q[head+1])-X(q[head]))){head++;}
        dp[i]=Y(q[head])-X(q[head])*sc1[i]+sc1[i]*sc1[i];
        while(head<tail && (Y(i)-Y(q[tail]))*(X(q[tail])-X(q[tail-1]))<=(Y(q[tail])-Y(q[tail-1]))*(X(i)-X(q[tail]))){tail--;}
        q[++tail]=i;
    }
    printf("%lld",dp[n]);
    return 0;
}