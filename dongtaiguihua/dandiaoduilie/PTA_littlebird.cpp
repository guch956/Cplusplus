#include<iostream>
#include<cstdio>
using namespace std;
const int N= 1000004;
int h[N],dp[N],que[N],tail,head;
int main(){
    int n,m,i,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    h[0]=0x3f3f3f3f;
    scanf("%d",&m);
    while(m){
        for(i=1;i<=n;i++){
            dp[i]=0;
        }
        head=0;
        tail=1;que[0]=1;
        scanf("%d",&k);
        for(i=2;i<=n;i++){
            dp[i]=h[i]>=h[que[head]]?dp[que[head]]+1:dp[que[head]];
            while(dp[i]<dp[que[tail-1]]){tail--;}
            while(dp[i]==dp[que[tail-1]] && h[i]>=h[que[tail-1]]){tail--;}
            que[tail]=i;
            tail++;
            while(que[head]<=i-k){
                head++;
            }
        }
        printf("%d\n",dp[n]);
        m--;
    }
    return 0;
}