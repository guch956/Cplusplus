#include<iostream>
#include<cstdio>
using namespace std;
const int N=254;
int xue[N];
int boot[N][2];
int dp[N];
int main(){
    int n,i,j,k,m;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&xue[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&boot[i][0],&boot[i][1]);
    }
    for(i=2;i<=n;i++){
        for(j=0;j<m;j++){
            if(xue[i]>boot[j][0]){continue;}
            for(k=max(1,i-boot[j][1]);k<i;k++){
                if(xue[k]<=boot[j][0] && j>=dp[k]){break;}
            }
            if(k<i){break;}
        }
        dp[i]=j;
    }
    printf("%d",dp[n]);
    return 0;
}