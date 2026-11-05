#include<iostream>
#include<cstdio>
int g[103][103];
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(g[i][k] && g[k][j]){g[i][j]=1;}
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    return 0;    
}