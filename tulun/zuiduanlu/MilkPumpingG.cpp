#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1003;
const int INF=0x3f3f3f3f;
int vis[N][N];
struct {
    int next;
    int to;
    int f;
    int len;
}g[N<<1];
int head[N],ent;
int n;
void adde(int u,int v,int a,int b){
    ent++;
    g[ent].f=b;
    g[ent].len=a;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
struct node{
    int id;
    int flow;
    int dis;
    node(int a,int b,int c){
        id=a;flow=b;dis=c;
    }
    bool operator<(const node a)const{
        return a.dis<dis;
    }
};
void dijstra(int s){
    int i,v,d,j;
    node x(s,1000,0);
    priority_queue<node> q;
    for(i=1;i<=n;i++){
        for(j=1;j<=1000;j++){
            vis[i][j]=INF;
        }
    }
    for(i=1;i<=1000;i++){
        vis[s][i]=0;
    }
    q.push(x);
    while(q.size()){
        x=q.top();
        q.pop();
        if(vis[x.id][x.flow]<x.dis){continue;}
        for(i=head[x.id];i;i=g[i].next){
            v=g[i].to;
            d=x.dis+g[i].len;
            j=min(g[i].f,x.flow);
            if(d<vis[v][j]){
                vis[v][j]=d;
                q.push(node(v,j,d));
            }
        }
    }
    d=0;
    for(i=1;i<=1000;i++){
        d=max(d,i*1000000/vis[n][i]);
    }
    cout<<d;
}
int main(){
    int m,i,a,b,c,d;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        adde(a,b,c,d);
        adde(b,a,c,d);
    }
    dijstra(1);
    return 0;
}