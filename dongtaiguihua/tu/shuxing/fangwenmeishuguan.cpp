#include<iostream>
#include<cstdio>
using namespace std;
int dp[250][6010];
int p[250];
int q[250];
int jisuan(int n,int t){
    if(q[n]==0){
        int a=t-2*p[n];
        int c=jisuan(n+1,a),b,i,j;
        b = jisuan(c+1,a);
        for(i=2*p[n];i<=t;i++){
            for(j=0;j<=i-2*p[n];j++){
                dp[n][i]=max(dp[n][i],dp[n+1][j]+dp[c+1][i-2*p[n]-j]);
            }
        }
        return b;
    }
    else{
        int a=t-2*p[n],i,b,j;
        for(i=0,b=0;b<=a;i++,b=b+5){
            for(j=0;j<=4 && b+j<=a;j++){
                dp[n][2*p[n]+b+j]=min(i,q[n]);
            }
        }
        return n;
    }
}
int main(){
    int n,i=0,a,b;
    scanf("%d",&n);
    while(scanf("%d %d",&a,&b)==2){
        i++;
        p[i]=a;
        q[i]=b;
    }
    jisuan(1,n-1);
    printf("%d",dp[1][n-1]);
    return 0;
}