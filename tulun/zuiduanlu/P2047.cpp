#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
ll num[103][103];
int g[103][103];
int main(){
    int n,m,i,j,k,d;
    double ans,a;
    scanf("%d %d",&n,&m);
    memset(g,0x3f,sizeof(g));
    while(m--){
        scanf("%d %d %d",&i,&j,&k);
        g[i][j]=g[j][i]=k;
        num[i][j]=num[j][i]=1;
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                d = g[i][k]+g[k][j];
                if(d<g[i][j]){
                    g[i][j]=d;
                    num[i][j]=num[i][k]*num[k][j];
                }
                else if(d==g[i][j]){
                    num[i][j]+=num[i][k]*num[k][j];
                }
            }
        }
    }
    for(k=1;k<=n;k++){
        ans=0;
        for(i=1;i<=n;i++){
            if(i==k){continue;}
            for(j=1;j<=n;j++){
                if(j==k || i==j){continue;}
                if(g[i][k]+g[k][j]!=g[i][j]){continue;}
                a = num[i][k];
                a = a/num[i][j];
                a = a*num[k][j];
                ans+=a;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}