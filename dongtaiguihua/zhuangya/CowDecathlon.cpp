#include<iostream>
#include<cstdio>
using namespace std;
int shijian[21][21][2];
int dp[(1<<20)-1];
int p[21][21];
int main(){
    int n,m,i,a,b,c,j,ma;
    scanf("%d %d",&n,&m);
    ma = (1<<n)-1;
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        shijian[a][0][0]++;
        shijian[a][shijian[a][0][0]][0]=b;
        shijian[a][shijian[a][0][0]][1]=c;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&p[j][i]);
        }
        for(b=1;b<shijian[i][0][0];b++){
            for(c=shijian[i][0][0]-1;c>=1;c--){
                if(shijian[i][c][0]>shijian[i][c+1][0]){
                    swap(shijian[i][c][0],shijian[i][c+1][0]);
                    swap(shijian[i][c][1],shijian[i][c+1][1]);
                }
            }
        }
    }
    for(j=1;j<=ma;j++){
        a = 0;
        b = 1;
        while(b<=j){
            if(b&j){a++;}
            b = b<<1;
        }
        b = 1;
        c = 1;
        while(c<=j){
            if(c&j){
                dp[j]=max(dp[j],dp[j-c]+p[a][b]);
            }
            b++;
            c = c<<1;
        }
        for(b=1;b<=shijian[a][0][0];b++){
            if(dp[j]>=shijian[a][b][0]){
                dp[j]+=shijian[a][b][1];
            }
        }
    }
    printf("%d",dp[ma]);
    return 0;
}