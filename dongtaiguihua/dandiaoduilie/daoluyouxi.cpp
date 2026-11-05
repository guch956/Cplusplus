#include<iostream>
#include<cstdio>
using namespace std;
const int N=1003;
int s[N][N];
int p[N][N];
int q[N][N];
int head[N],tail[N];
int dj[N][N];
int dp[N];
int main(){
    int m,n,d,i,j,k,ma;
    scanf("%d %d %d",&n,&m,&d);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&p[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        scanf("%d",&dj[0][i]);
    }
    for(i=1;i<=n;i++){
        k = i;
        for(j=1;j<=m;j++){
            s[i][j]=s[i][j-1]+p[k][j];
            dj[i][j]=dj[0][k];
            k = k==n?1:k+1;
        }
    }
    for(i=1;i<=m;i++){
        ma=-0x3f3f3f3f;
        for(j=1;j<=n;j++){
            while(q[j][head[j]]+d<i){head[j]++;}
            ma = max(ma,dp[q[j][head[j]]]+s[j][i]-s[j][q[j][head[j]]]-dj[j][q[j][head[j]]+1]);
        }
        dp[i]=ma;
        for(j=1;j<=n;j++){
            while(head[j]<=tail[j] && (dp[q[j][tail[j]]]-s[j][q[j][tail[j]]]-dj[j][q[j][tail[j]]+1])<=
                (dp[i]-s[j][i]-dj[j][i+1])){
                    tail[j]--;
                }
            q[j][++tail[j]]=i;
        }
    }
    printf("%d",dp[m]);
    return 0;
}