#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll P;
ll p[2][45003];
ll sum[302][45003];
ll f[2][45003];
ll ans[302];
int main(){
    int n,k,now=1,old=0,i,j,no=1,ol=0,m;
    scanf("%d %d %lld",&n,&k,&P);
    p[old][0]=1;
    for(i=1;i<=n;i++){
        m = i*(i-1)/2;
        p[now][0]=p[old][0];
        sum[i][0]=sum[i-1][0];
        for(j=1;j<i;j++){
            p[now][j]=p[now][j-1]+p[old][j];
            p[now][j]%=P;
            sum[i][j]=sum[i][j-1]+sum[i-1][j];
            sum[i][j]%=P;
        }
        sum[i][i-1]+=p[old][0];
        sum[i][i-1]%=P;
        for(j=i;j<=m;j++){
            p[now][j]=p[now][j-1]+p[old][j]-p[old][j-i]+P;
            p[now][j]%=P;
            sum[i][j]=sum[i][j-1]-p[old][j-i]+sum[i-1][j]-sum[i-1][j-i]+2*P+p[old][j-i+1];
            sum[i][j]%=P;
        }
        swap(now,old);
    }
    f[ol][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=k;j++){
            ans[i]+=f[ol][j]*sum[n-i+1][k-j];
            ans[i]%=P;
            m = (n-i)*(n-i+1)/2-k+j;
            if(m>=0){
                ans[n-i+1]+=f[ol][j]*sum[n-i+1][m];
                ans[n-i+1]%=P;
            }
        }
        f[no][0]=f[ol][0];
        for(j=1;j<=n-i;j++){
            f[no][j]=f[no][j-1]+f[ol][j];
            f[no][j]%=P;
        }
        for(j=n-i+1;j<=k;j++){
            f[no][j]=f[no][j-1]+f[ol][j]-f[ol][j-n+i-1]+P;
            f[no][j]%=P;
        }
        swap(ol,no);
    }
    for(i=1;i<=n;i++){
        ans[i]=ans[i]-p[old][k]+P;
        ans[i]%=P;
        printf("%lld ",ans[i]);
    }
    return 0;
}
