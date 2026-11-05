#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dis[N][N];
struct {
    int next;
    int to;
}g[N*10];
int n,head[N],ent;
ll dp[N];
struct node{
    ll zhil;
    int id;
}p[N];
bool bijiao(node & n1,node & n2){
    return n1.zhil<n2.zhil;
}
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void bfs(int s){
    int i,u,v;
    queue<int> q;
    for(i=1;i<=n;i++){
        dis[s][i]=INF;
    }
    dis[s][s]=0;
    q.push(s);
    while(q.size()){
        u = q.front();
        q.pop();
        for(i=head[u];i;i=g[i].next){
            v = g[i].to;
            if(dis[s][v]>dis[s][u]+1){
                dis[s][v]=dis[s][u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    int i,m,a,j;
    ll e,ans=0;
    scanf("%d %lld",&n,&e);
    for(i=1;i<=n;i++){
        scanf("%lld %d",&p[i].zhil,&m);
        p[i].id=i;
        for(j=1;j<=m;j++){
            scanf("%d",&a);
            adde(i,a);
        }
    }
    for(i=1;i<=n;i++){
        bfs(i);
    }
    sort(p+1,p+n+1,bijiao);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            if(p[j].zhil<p[i].zhil && dis[p[j].id][p[i].id]<INF){
                dp[i]=max(dp[i],dp[j]-e*dis[p[j].id][p[i].id]);
            }
        }
        dp[i]+=p[i].zhil;
        ans=max(dp[i],ans);
    }
    printf("%lld",ans);
    return 0;
}