#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=2003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dp[N][N];
ll AP[N],BP[N],AS[N],BS[N];
int q[N],head,tail;
int main(){
    int t,maxp,w,i,j,i1;
    scanf("%d %d %d",&t,&maxp,&w);
    for(i=1;i<=t;i++){
        scanf("%lld %lld %lld %lld",&AP[i],&BP[i],&AS[i],&BS[i]);
    }
    for(j=1;j<=maxp;j++){
        dp[0][j]=-INF;
    }
    for(i=1;i<=w+1;i++){
        for(j=1;j<=AS[i];j++){
            dp[i][j]=max(dp[i-1][j],-j*AP[i]);
        }
        for(j=AS[i]+1;j<=maxp;j++){
            dp[i][j]=dp[i-1][j];
        }
    }
    for(i=w+2;i<=t;i++){
        head=1;tail=1;
        i1=i-1-w;
        q[1]=0;
        dp[i][0]=dp[i-1][0];
        for(j=1;j<=maxp;j++){
             while(q[head]<j-AS[i]){head++;}
             dp[i][j]=max(dp[i-1][j],dp[i1][q[head]]+q[head]*AP[i]-j*AP[i]);
             while(head<=tail && dp[i1][q[tail]]+q[tail]*AP[i]<=dp[i1][j]+j*AP[i]){tail--;}
             q[++tail]=j;
        }
        head=1;tail=1;q[1]=maxp;
        for(j=maxp-1;j>=0;j--){
            while(q[head]>j+BS[i]){head++;}
            dp[i][j]=max(dp[i][j],dp[i1][q[head]]+q[head]*BP[i]-j*BP[i]);
            while(head<=tail && dp[i1][q[tail]]+q[tail]*BP[i]<=dp[i1][j]+j*BP[i]){tail--;}
            q[++tail]=j;
        }
    }
    printf("%lld",dp[t][0]);
    return 0;
}