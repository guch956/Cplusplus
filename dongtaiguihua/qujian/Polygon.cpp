#include<iostream>
#include<cstdio>
using namespace std;
const int N=105;
const int INF=0x3f3f3f3f;
int dp_max[N][N];int dp_min[N][N];
int fuhao[N];
int main(){
    int n,i,j,k,a,b;
    char c;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s %d",&c,&a);
        if(c=='t'){
            fuhao[i-1]=fuhao[i+n-1]=0;
        }
        else{
            fuhao[i-1]=fuhao[i+n-1]=1;
        }
        dp_max[i][i]=dp_max[i+n][i+n]=dp_min[i][i]=dp_min[i+n][i+n]=a;
    }
    for(k=1;k<=n-1;k++){
        for(i=1;i<=2*n-k;i++){
            dp_max[i][i+k]=-INF;
            dp_min[i][i+k]=INF;
            a = i+k;
            for(j=i;j<a;j++){
                if(fuhao[j]==0){
                    dp_max[i][a]=max(dp_max[i][j]+dp_max[j+1][a],dp_max[i][a]);
                    dp_min[i][a]=min(dp_min[i][j]+dp_min[j+1][a],dp_min[i][a]);
                }
                else{
                    dp_max[i][a]=max(max(max(max(dp_min[i][j]*dp_min[j+1][a],dp_min[i][j]*dp_max[j+1][a]),dp_max[i][j]*dp_min[j+1][a]),dp_max[i][j]*dp_max[j+1][a]),dp_max[i][a]);
                    dp_min[i][a]=min(min(min(min(dp_min[i][j]*dp_min[j+1][a],dp_min[i][j]*dp_max[j+1][a]),dp_max[i][j]*dp_min[j+1][a]),dp_max[i][j]*dp_max[j+1][a]),dp_min[i][a]);
                }
            }
        }
    }
    a = -INF;
    for(i=1;i<=n;i++){
        a = max(a,dp_max[i][i+n-1]);
    }
    printf("%d\n",a);
    for(i=1;i<=n;i++){
        if(a==dp_max[i][i+n-1]){
            printf("%d ",i);
        }
    }
    return 0;
}
