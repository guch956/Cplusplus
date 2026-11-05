#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1050000;
int dp[N];
int L;
int tim[21];
int showt[21][1002];
int shown[21];
int erfen(int x,int t){
    int l=0,r=shown[t],mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(showt[t][mid]<=x){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    return l;
}
int main(){
    int n,i,a,j,b,m,geshu,xing,ans=30;
    scanf("%d %d",&n,&L);
    for(i=1;i<=n;i++){
        scanf("%d %d",&tim[i],&shown[i]);
        showt[i][0]=-2;
        for(j=1;j<=shown[i];j++){
            scanf("%d",&showt[i][j]);
        }
    }
    m = (1<<n)-1;
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=m;i++){
        a = 1;
        geshu=0;
        xing=0;
        for(j=1;j<=n;j++){
            if(a&i){
                geshu++;
                b = erfen(dp[i-a]+1,j);
                if(b){
                    dp[i]=max(dp[i],showt[j][b]+tim[j]-1);
                    if(dp[i]>=L){
                        xing=1;
                    }
                }
            }
            a = a<<1;
        }
        if(xing){
            ans=min(ans,geshu);
        }
    }
    if(ans==30){printf("-1");}
    else{printf("%d",ans);}
    return 0;
}
