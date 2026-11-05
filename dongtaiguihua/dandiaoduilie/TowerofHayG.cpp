#include<iostream>
#include<cstdio>
const int N=100003;
int sum[N],dp[N];
int q[N];
int num[N];
inline int f(int j){return 2*sum[j]-sum[dp[j]];}
int main(){
    int n,i,a,head,tail;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        sum[i]=sum[i-1]+a;
    }
    dp[n]=n;num[n]=0;
    head=tail=1;
    q[head]=n;
    for(i=n-1;i>=0;i--){
        while(head<tail && f(q[head+1])>=sum[i]){head++;}
        dp[i]=q[head];
        num[i]=num[dp[i]]+1;
        while(head<=tail && f(i)>=f(q[tail])){tail--;}
        q[++tail]=i;
    }
    printf("%d",num[0]);
    return 0;
}