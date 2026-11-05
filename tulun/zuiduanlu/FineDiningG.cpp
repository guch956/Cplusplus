#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=50003;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct {
    int to;
    int next;
    ll len;
}g[4*N];
int head[N];
int ent;
int n;
ll vis[N];
ll vis2[N];
ll pre[N];
void adde(int u,int v,ll l){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].len=l;
    head[u]=ent;
}
struct node{
    int id;
    ll dis;
    node(int a,ll b){
        id=a;dis=b;
    }
    bool operator <(const node a)const{
        return a.dis<dis;
    }
};
void dijstra(int s){
    int i,v;
    ll d;
    node x(s,0);
    priority_queue<node> q;
    for(i=1;i<=n;i++){
        vis[i]=INF;
    }
    vis[s]=0;
    q.push(x);
    while(q.size()){
        x=q.top();
        q.pop();
        if(x.dis>vis[x.id]){continue;}
        for(i=head[x.id];i;i=g[i].next){
            v=g[i].to;
            d=vis[x.id]+g[i].len;
            if(d<vis[v]){
                vis[v]=d;
                q.push(node(v,d));
            }
        }
    }
}
void dijstra2(){
    int i,v;
    ll d;
    node x(0,0);
    priority_queue<node> q;
    for(i=1;i<=n;i++){
        if(pre[i]){
            q.push(node(i,vis[i]-pre[i]));
            vis2[i]=vis[i]-pre[i];
        }
        else{
            vis2[i]=INF;
        }
    }
    while(q.size()){
        x=q.top();
        q.pop();
        if(x.dis>vis2[x.id]){continue;}
        for(i=head[x.id];i;i=g[i].next){
            v=g[i].to;
            d=x.dis+g[i].len;
            if(d<vis2[v]){
                vis2[v]=d;
                q.push(node(v,d));
            }
        }
    }
}
int main(){
    int m,i,a,b,k;
    ll c;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=m;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    for(i=1;i<=k;i++){
        scanf("%d %lld",&a,&c);
        pre[a]=max(pre[a],c);
    }
    dijstra(n);
    dijstra2();
    for(i=1;i<n;i++){
        if(vis2[i]<=vis[i]){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}