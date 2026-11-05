#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int g[103][103];
int p[1000003];
int dp[1000003];
int pre[1000003];
int q[1000003];
int main(){
    int n,i,j,k,m,head,tail;
    char c;
    memset(g,0x3f,sizeof(g));
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            c = getchar();
            while(c!='0' && c!='1'){c = getchar();}
            if(c=='1'){g[j][i]=1;}
        }
        g[i][i]=0;
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(g[i][k]+g[k][j]<g[i][j])g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){scanf("%d",&p[m-i+1]);}
    dp[1]=1;j=1;
    head=tail=1;
    q[tail]=1;
    for(i=2;i<=m;i++){
        while(g[p[j]][p[i-1]]+g[p[i-1]][p[i]]>g[p[j]][p[i]]){
            if(q[head]==j++){head++;}
        }
        dp[i]=dp[q[head]]+1;
        pre[i]=q[head];
        while(head<=tail && dp[q[tail]]>=dp[i]){tail--;}
        q[++tail]=i;
    }
    printf("%d\n",dp[m]);
    for(i=m;i;i=pre[i]){printf("%d ",p[i]);}
    return 0;
}