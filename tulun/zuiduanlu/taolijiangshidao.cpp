#include<iostream>
#include<queue>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100002;const int M=400003;
const ll INF=0x3f3f3f3f3f3f3f3f;
int ent=1;
int head[N];bool weixian[N],jiangshi[N];
struct edge{
    int to;
    int next;
};
edge g[M];
int n,S;
ll P,Q;
ll dist[N];
struct node{
    int id;
    ll dis;
    bool operator <(const node & n1)const{
        return n1.dis<dis;
    }
    node(int a,ll b){
        id=a;dis=b;
    }
};
void adde(int a,int b){
    g[ent].next=head[a];
    g[ent].to=b;
    head[a] = ent;
    ent++;
}
void bfs(){
    int i,v,u;
    queue<int> q;
    for(i=1;i<=n;i++){
        dist[i]=INF;
        if(weixian[i]){
            q.push(i);
            dist[i]=0;
        }
    }
    while(q.size()){
        u=q.front();
        q.pop();
        if(dist[u]==S){
            continue;
        }
        for(i=head[u];i;i=g[i].next){
            v = g[i].to;
            if(dist[v]==INF){
                dist[v]=dist[u]+1;
                q.push(v);
                weixian[v]=1;
            }
        }
    }
}
void dijkstra(int s){
    int i,v;
    ll d;
    node x(s,0);
    priority_queue<node> q;
    for(i=1;i<=n;i++){
        dist[i]=INF;
    }
    dist[s]=0;
    q.push(x);
    while(q.size()){
        x=q.top();
        q.pop();
        if(x.dis>dist[x.id]){continue;}
        for(i=head[x.id];i;i=g[i].next){
            v=g[i].to;
            if(jiangshi[v]){continue;}
            d=x.dis+(weixian[v]?Q:P);
            if(d<dist[v]){
                dist[v]=d;
                q.push(node(v,d));
            }
        }
    }
    dist[n]-=weixian[n]?Q:P;
    printf("%lld",dist[n]);
}
int main(){
    int m,a,b,k;
    scanf("%d %d %d %d",&n,&m,&k,&S);
    scanf("%lld %lld",&P,&Q);
    while(k--){
        scanf("%d",&a);
        weixian[a]=1;
        jiangshi[a]=1;
    }
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    bfs();
    dijkstra(1);
    return 0;
}