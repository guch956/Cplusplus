#include<iostream>
#include<cstdio>
using namespace std;
const double INF=0x3f3f3f3f3f3f3f;
double dp[1003];
double zhi[253];
int weight[253];
double caiyi[253];
int main(){
    int n,w,i,j,t;
    double l=0,r=0,mid;
    scanf("%d %d",&n,&w);
    for(i=1;i<=n;i++){
        scanf("%d %lf",&weight[i],&caiyi[i]);
        r = max(r,caiyi[i]);
    }
    for(t=0;t<50;t++){
        mid=(l+r)/2;
        for(i=1;i<=n;i++){zhi[i]=caiyi[i]-((double)weight[i])*mid;}
        for(j=1;j<=w;j++){dp[j]=-INF;}
        dp[0]=0;
        for(i=1;i<=n;i++){
            for(j=w;j>=max(0,w-weight[i]+1);j--){
                dp[w]=max(dp[w],dp[j]+zhi[i]);
            }
            for(j=w-weight[i];j>=0;j--){
                dp[j+weight[i]]=max(dp[j+weight[i]],dp[j]+zhi[i]);
            }
            

        }
        if(dp[w]>=0){l=mid;}
        else{r=mid;}
    }
    l = l+1e-8;
    printf("%d",(int)(1000*l));
    return 0;
}