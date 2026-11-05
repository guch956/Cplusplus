#include<iostream>
#include<cstdio>
using namespace std;
bool xing[32][600];
int nex[32][600];
int gouzao[32];
int main(){
    int T,n,i,j,k,t,a,c;
    xing[0][0]=1;
    for(i=1;i<=30;i++){
        a = i*(i-1)/2;
        for(j=0;j<=a;j++){
            for(k=1,t=0;t<=j&&k<=i;k++,t=k*(k-1)/2){
                if(xing[i-k][j-t]){
                    xing[i][j]=1;
                    nex[i][j]=k;
                }
            }
        }
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        k = n*(n-1)/2-k;
        if(xing[n][k]){
            a = 0;c = n;
            while(n){
                i = nex[n][k];
                j = i*(i-1)/2;
                for(t=n-i+1;t<=n;t++){gouzao[t]=++a;}
                n-=i;k-=j;
            }
            for(i=1;i<=c;i++)printf("%d ",gouzao[i]);
        }
        else{printf("0");}
        printf("\n");
    }
    return 0;
}
