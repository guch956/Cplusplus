#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=55;
bool p[N][N][34];
int mp[N][N];
int main(){
    memset(mp,0x3f,sizeof(mp));
    int n,m,i,t,k,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&j,&k);
        mp[j][k]=1;
        p[j][k][0]=1;
    }
    for(t=1;t<=32;t++){
        for(k=1;k<=n;k++){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(p[i][k][t-1] && p[k][j][t-1]){
                        p[i][j][t]=1;
                        mp[i][j]=1;
                    }
                }
            }
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
            }
        }
    }
    printf("%d\n",mp[1][n]);
    return 0;
} 