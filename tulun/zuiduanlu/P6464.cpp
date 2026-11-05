#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=103;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll g[N][N];
int main(){
    int i,n,m,j,k,i1,j1;
    ll ans=INF,sum,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            g[i][j]=INF;
        }
        g[i][i]=0;
    }
    while(m--){
        scanf("%d %d %lld",&i,&j,&w);
        g[i][j]=min(g[i][j],w);
        g[j][i]=min(g[j][i],w);
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            sum = 0;
            for(i1=1;i1<=n;i1++){
                for(j1=1;j1<i1;j1++){
                    sum+=min(g[i1][j1],min(g[i1][i]+g[j][j1],g[i1][j]+g[i][j1]));
                }
            }
            ans = min(ans,sum);
        }
    }
    printf("%lld",ans);
    return 0;
}
