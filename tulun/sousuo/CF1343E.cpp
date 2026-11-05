#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200003;
const ll INF=0x3f3f3f3f3f3f3f3f;
int dis[3][N];
int head[N],nex[N<<1],to[N<<1],ent;
ll val[N];
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void bfs(int s,int n,int di[]){
    int i,u;
    queue<int> q;
    for(i=1;i<=n;i++){di[i]=0x3f3f3f3f;}
    di[s]=0;
    q.push(s);
    while(q.size()){
        u = q.front();
        q.pop();
        for(i=head[u];i;i=nex[i]){
            if(di[u]+1<di[to[i]]){
                di[to[i]]=di[u]+1;
                q.push(to[i]);
            }
        }
    }
}
int main(){
    int T,n,i,a,b,m,x,y,z;
    ll ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d %d",&n,&m,&x,&y,&z);
        ans = INF;
        for(i=1;i<=m;i++){scanf("%lld",&val[i]);}
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        sort(val+1,val+m+1);
        for(i=1;i<=m;i++){val[i]=val[i]+val[i-1];}
        bfs(x,n,dis[0]);
        bfs(y,n,dis[1]);
        bfs(z,n,dis[2]);
        val[m+1]=INF;
        for(i=1;i<=n;i++){
            ans = min(ans,val[min(dis[0][i]+dis[1][i]+dis[2][i],m+1)]+val[dis[1][i]]);
        }
        for(i=1;i<=n;i++){head[i]=0;}
        ent=0;
        printf("%lld\n",ans);
    }
    return 0;
}