#include<iostream>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[201][20001];
int dplast[201][20001];
int geshu[201];
int jiazhi[201];
int q[20004],head,tail;
inline int jisuan(int i,int j,int r){
    return dp[i-1][j*jiazhi[i]+r]-j;
}
int main(){
    int n,i,e,r,j,m,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&jiazhi[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&geshu[i]);
    }
    scanf("%d",&e);
    dp[0][0]=0;
    for(i=1;i<=e;i++){
        dp[0][i] = INF;
    }
    for(i=1;i<=n;i++){
        for(r=0;r<jiazhi[i];r++){
            head=1;tail=1;
            dp[i][r] = dp[i-1][r];
            dplast[i][r] = 0;
            q[1]=0;
            for(m=1;a=m*jiazhi[i]+r,a<=e;m++){
                while(q[head]<m-geshu[i]){head++;}
                dp[i][a]=dp[i-1][a];
                dplast[i][a]=0;
                b = jisuan(i,q[head],r)+m;
                if(b<dp[i][a]){
                    dp[i][a] = b;
                    dplast[i][a] = m-q[head];
                }
                while(head<=tail && jisuan(i,q[tail],r)>=jisuan(i,m,r)){tail--;}
                tail++;
                q[tail]=m;
            }
        }
    }
    printf("%d\n",dp[n][e]);
    tail=0;
    for(i=n;i>=1;i--){
        tail++;
        q[tail]=dplast[i][e];
        e = e-dplast[i][e]*jiazhi[i];
    }
    for(i=n;i>=1;i--){
        printf("%d ",q[i]);
    }
    return 0;
}