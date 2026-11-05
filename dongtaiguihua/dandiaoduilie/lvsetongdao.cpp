#include<iostream>
#include<cstdio>
using namespace std;
const int N=50003;
int A[N];
int q[N],head,tail;
int tim,n;
int dp[N];
bool check(int t){
    t++;
    int i,ans=0x3f3f3f3f;
    head=1;tail=1;
    q[1]=0;
    for(i=1;i<=n;i++){
        while(q[head]<i-t){head++;}
        dp[i] = dp[q[head]]+A[i];
        while(head<=tail && dp[q[tail]]>=dp[i]){tail--;}
        tail++;
        q[tail]=i;
    }
    for(i=n-t;i<=n;i++){
        ans = min(ans,dp[i]);
    }
    return ans<=tim;
}
int erfen(){
    int l=0,r=n,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l
}
int main(){
    int i;
    scanf("%d %d",&n,&tim);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    printf("%d",erfen());
    return 0;
}