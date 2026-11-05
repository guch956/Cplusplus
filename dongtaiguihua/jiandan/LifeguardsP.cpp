#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
int dp[N][101][2];
struct qj{
    int l;
    int r;
}p[N];
bool bijiao(qj q1,qj q2){
    return q1.l==q2.l?q1.r>q2.r:q1.l<q2.l;
}
int main(){
    int n,i,j,a=-1,t=0,kk,u;
    scanf("%d %d",&n,&kk);
    for(i=1;i<=n;i++){
        scanf("%d %d",&p[i].l,&p[i].r);
    }
    sort(p+1,p+n+1,bijiao);
    p[0].r=0;
    for(i=1;i<=n;i++){
        if(a<p[i].r){
            a = p[i].r;
            p[++t]=p[i];
        }
    }
    kk = kk-n+t;
    n = t;
    for(i=1;i<=n;i++){
        dp[i][0][0]=dp[i-1][0][0]-max(p[i].l,p[i-1].r)+p[i].r;
        dp[i][0][1]=dp[i][0][0];
    }
    if(kk<=0){
        printf("%d",dp[n][0][0]);
    }
    else{
        for(j=1;j<=kk;j++){
            u = 0;
            dp[0][j][0]=dp[0][j][1]=-1;
            for(i=1;i<=n;i++){
                dp[i][j][0]=dp[i][j][1]=-1;
                while(p[u].r<=p[i].l){u++;}
                if(u<i){
                    if(dp[u][max(j-i+u+1,0)][1]!=-1){
                        dp[i][j][1]=dp[u][max(j-i+u+1,0)][1]+p[i].r-p[u].r;
                    }
                }
                if(dp[u-1][max(0,j-i+u)][0]!=-1){
                    dp[i][j][1]=max(dp[i][j][1],dp[u-1][max(0,j-i+u)][0]+p[i].r-p[i].l);
                }
                dp[i][j][0]=max(dp[i-1][j-1][0],dp[i][j][1]);
            }
        }
        printf("%d",dp[n][kk][0]);
    }
    return 0;
}

