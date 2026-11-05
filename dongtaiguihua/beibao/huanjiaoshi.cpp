#include<iostream>
#include<cstdio>
using namespace std;
const double INF = 9000000000000;
const int N=2003;
double g[303][303];
int jz[N][2];
double dp[N][2];
double p[N];
void floyed(int n){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
}
int main(){
    int n,m,e,v,i,j;
    double a;
    scanf("%d %d %d %d",&n,&m,&v,&e);
    for(i=1;i<=n;i++){
        scanf("%d",&jz[i][0]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&jz[i][1]);
    }
    for(i=1;i<=n;i++){
        scanf("%lf",&p[i]);
    }
    for(i=1;i<=v;i++){
        for(j=1;j<=v;j++){
            g[i][j]=i==j?0:INF;
        }
    }
    while(e--){
        scanf("%d %d %lf",&i,&j,&a);
        g[i][j]=min(g[i][j],a);
        g[j][i]=g[i][j];
    }
    floyed(v);
    dp[0][1]=INF;
    for(i=2;i<=n;i++){
        for(j=m;j>=1;j--){
            dp[j][0]=min(dp[j][0]+g[jz[i-1][0]][jz[i][0]],
                dp[j][1]+p[i-1]*g[jz[i-1][1]][jz[i][0]]+(1-p[i-1])*g[jz[i-1][0]][jz[i][0]]);
            dp[j][1]=min(dp[j-1][0]+p[i]*g[jz[i-1][0]][jz[i][1]]+(1-p[i])*g[jz[i-1][0]][jz[i][0]],
                dp[j-1][1]+p[i]*p[i-1]*g[jz[i-1][1]][jz[i][1]]
                +(1-p[i])*p[i-1]*g[jz[i-1][1]][jz[i][0]]
                +p[i]*(1-p[i-1])*g[jz[i-1][0]][jz[i][1]]
                +(1-p[i])*(1-p[i-1])*g[jz[i-1][0]][jz[i][0]]);   
        }
        dp[0][1]=INF;
        dp[0][0]=dp[0][0]+g[jz[i-1][0]][jz[i][0]];
    }
    printf("%.2f",min(dp[m][0],dp[m][1]));
    return 0;
}