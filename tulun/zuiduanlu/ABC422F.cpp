#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=5003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dis[N][2];
int head[N],nex[N<<1],to[N<<1],ent;
ll val[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int main(){
    int n,m,i,a,b,now=1,old=0,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&val[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    for(i=2;i<=n;i++){dis[i][0]=INF;}
    dis[1][0]=val[1]*(n-1);
    for(j=n-2;j>=0;j--){
        dis[1][now]=val[1]*j;
        for(i=2;i<=n;i++){
            dis[i][now]=INF;
        }
        for(a=2;a<=n;a++){
            for(i=head[a];i;i=nex[i]){
                b = to[i];
                dis[a][now]=min(dis[a][now],dis[b][old]);
            }
            dis[a][now]+=val[a]*j;
        }
        swap(now,old);
    }
    for(i=1;i<=n;i++){
        printf("%lld\n",dis[i][old]);
    }
    return 0;
}