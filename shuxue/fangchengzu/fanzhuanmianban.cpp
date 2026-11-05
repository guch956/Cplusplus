#include<iostream>
#include<cstdio>
using namespace std;
const int N=303;
const int P=998244353;
int zengguang[N][N];
int main(){
    int n,m,i,j,k,t,a;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&j);
            zengguang[j][i]=1;
        }
    }
    n++;t=0;
    for(i=1;i<=m;i++){
        scanf("%d",&j);
        zengguang[i][n]=j;
    }
    for(i=1;i<n;i++){
        k = 0;
        for(j=t+1;j<=m;j++){
            if(zengguang[j][i]){k=j;}
        }
         if(!k){continue;}
        t++;
        for(j=1;j<=n;j++){swap(zengguang[t][j],zengguang[k][j]);}
        /*for(j=1;j<=m;j++){
            for(k=1;k<=n;k++){
                cout<<zengguang[j][k]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;*/
        for(j=1;j<=m;j++){
            if(j==t){continue;}
            if(zengguang[j][i]){
                for(k=1;k<=n;k++){
                    zengguang[j][k]=zengguang[j][k]^zengguang[t][k];
                }
            }
        }
        /*for(j=1;j<=m;j++){
            for(k=1;k<=n;k++){
                cout<<zengguang[j][k]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;*/
    }
    k = 1;
    for(i=t+1;i<=m;i++){
        if(zengguang[i][n]){
            printf("0");
            return 0;
        }
    }
    for(i=t+1;i<n;i++){
        k = (k<<1)%P;
    }
    printf("%d",k);
    return 0;
}