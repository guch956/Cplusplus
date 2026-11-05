#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=103;
const int INF=0x3f3f3f3f;
int ditu[N][N];
int dp[N][N][N][2][2];
int jiagen[N];
int jiagem[N];
inline bool ch(int x){return x>=0;}
int main(){
    int T,n,m,i,j,k,ans;
    char c;
    //freopen("5.in","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        memset(dp,0x3f,sizeof(dp));
        dp[0][1][0][0][0]=0;
        dp[1][0][0][0][0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&jiagen[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d",&jiagem[i]);
        }
        dp[0][1][0][0][1]=jiagem[1];
        dp[1][0][0][1][0]=jiagen[1];
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                c = getchar();
                while(c!='X' && c!='L' && c!='R'){c = getchar();}
                if(c=='X'){ditu[i][j]=0;}
                else{
                    if(c=='L'){ditu[i][j]=1;}
                    else{ditu[i][j]=-1;}
                    for(k=0;k<=100;k++){
                        if(ch(k-ditu[i][j]))dp[i][j][k][0][0]=min(dp[i][j-1][k-ditu[i][j]][0][0],dp[i][j-1][k-ditu[i][j]][0][1]);
                        if(ch(k-ditu[i][j]))dp[i][j][k][0][0]=min(dp[i][j][k][0][0],min(dp[i-1][j][k-ditu[i][j]][0][0],dp[i-1][j][k-ditu[i][j]][1][0]));
                        if(ch(k+ditu[i][j]))dp[i][j][k][0][1]=min(dp[i][j][k][0][1],min(dp[i][j-1][k+ditu[i][j]][0][0],dp[i][j-1][k+ditu[i][j]][0][1])+jiagem[j]);
                        if(ch(k+ditu[i][j]))dp[i][j][k][0][1]=min(dp[i][j][k][0][1],min(dp[i-1][j][k+ditu[i][j]][0][1],dp[i-1][j][k+ditu[i][j]][1][1]));
                        if(ch(k+ditu[i][j]))dp[i][j][k][1][0]=min(dp[i][j-1][k+ditu[i][j]][1][0],dp[i][j-1][k+ditu[i][j]][1][1]);
                        if(ch(k+ditu[i][j]))dp[i][j][k][1][0]=min(dp[i][j][k][1][0],min(dp[i-1][j][k+ditu[i][j]][0][0],dp[i-1][j][k+ditu[i][j]][1][0])+jiagen[i]);
                        if(ch(k-ditu[i][j]))dp[i][j][k][1][1]=min(dp[i][j][k][1][1],min(dp[i][j-1][k-ditu[i][j]][1][0],dp[i][j-1][k-ditu[i][j]][1][1])+jiagem[j]);
                        if(ch(k-ditu[i][j]))dp[i][j][k][1][1]=min(dp[i][j][k][1][1],min(dp[i-1][j][k-ditu[i][j]][0][1],dp[i-1][j][k-ditu[i][j]][1][1])+jiagen[i]);
                    }
                }
            }
        }
        ans = min(dp[n][m][0][0][0],min(dp[n][m][0][0][1],min(dp[n][m][0][1][0],dp[n][m][0][1][1])));
        if(ans==INF){printf("-1\n");}
        else{printf("%d\n",ans);}
    }
    return 0;
}
