#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=10003;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct {
    int to;
    int next;
    ll len;
}g[N*10];
int head[N],ent;
int n,k;
ll dis[N][21];
void adde(int u,int v,ll l){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].len=l;
    head[u]=ent;
}
struct node{
    int id;
    ll vis;
    int kk;
    node(int a,int b,ll c){id=a;kk=b;vis=c;}
    bool operator < (const node& a)const{
        return vis>a.vis;
    }
};
void dij(int s){
    int i,j,v;
    ll w;
    node x(s,k,0);
    priority_queue<node> q;
    for(i=1;i<=n;i++){
        for(j=0;j<=k;j++){
            dis[i][j]=INF;
        }
    }
    for(j=0;j<=k;j++){
        dis[s][j]=0;
    }
    q.push(x);
    while(q.size()){
        x = q.top();
        q.pop();
        if(x.vis>dis[x.id][x.kk]){continue;}
        for(i=head[x.id];i;i=g[i].next){
            v = g[i].to;
            w = x.vis+g[i].len;
            if(x.kk && x.vis<dis[v][x.kk-1]){
                dis[v][x.kk-1]=x.vis;
                q.push(node(v,x.kk-1,x.vis));
            }
            if(w<dis[v][x.kk]){
                dis[v][x.kk]=w;
                q.push(node(v,x.kk,w));
            }
        }
    }
}
int main(){
    int m,a,b;
    ll c;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    dij(1);
    printf("%lld",dis[n][0]);
    return 0;
}