#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=10003;
const int INF=0x3f3f3f3f;
struct {
    int to;
    int next;
    int len[2];
    int cishu;
}g[N*5];
int head[N],ent;
int dis[N];
int n;
struct node{
    int id;
    int dist;
    node(int a,int b){id=a;dist=b;}
    bool operator <(const node & a)const{
        return dist>a.dist;
    }
};
void adde(int u,int v,int l1,int l2){
    ent++;
    g[ent].next=head[u];
    g[ent].to=v;
    g[ent].len[0]=l1;
    g[ent].len[1]=l2;
    head[u]=ent;
}
void dijkstra(int s,int k){
    int i,v,w;
    node x(0,0);
    priority_queue<node> q;
    for(i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push(node(s,0));
    while(q.size()){
        x = q.top();
        q.pop();
        if(dis[x.id]<x.dist){continue;}
        for(i=head[x.id];i;i=g[i].next){
            v = g[i].to;
            w = x.dist+g[i].len[k];
            if(w<dis[v]){
                dis[v]=w;
                q.push(node(v,w));
            }
        }
    }
    for(w=1;w<=n;w++){
        for(i=head[w];i;i=g[i].next){
            v = g[i].to;
            if(dis[v]!=dis[w]+g[i].len[k]){
                g[i].cishu++;
            }
        }
    }
}
void dijkstra(int s){
    int i,v,w;
    node x(0,0);
    priority_queue<node> q;
    for(i=1;i<=n;i++){
        dis[i]=INF;
    }
    dis[s]=0;
    q.push(node(s,0));
    while(q.size()){
        x = q.top();
        q.pop();
        if(dis[x.id]<x.dist){continue;}
        for(i=head[x.id];i;i=g[i].next){
            v = g[i].to;
            w = x.dist+g[i].cishu;
            if(w<dis[v]){
                dis[v]=w;
                q.push(node(v,w));
            }
        }
    }
    printf("%d",dis[1]);
}
int main(){
    int m,i,a,b,c,d;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        adde(b,a,c,d);
    }
    dijkstra(n,0);
    dijkstra(n,1);
    dijkstra(n);
    return 0;
}

