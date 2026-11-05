#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct node{
    int id;
    long long dis;
    bool operator < (const node & a) const{
        return dis>a.dis;
    }
    node(int a,long long c){
        id=a;dis = c;
    }
};
struct edge{
    long long w;
    int to;
    int next;
};
const int N=5002;const int M=200002;
edge g[M];
long long vis[N];
long long vis2[N];
int n,m;
int ent=1;int head[N];const long long INF = 0x3f3f3f3f3f3f3f3f;
void addedge(int u,int to,long long w){
    g[ent].next = head[u];
    g[ent].to = to;
    g[ent].w = w;
    head[u] = ent;
    ent++;
}
void dij(int s){
    int i,v;
    long long l;
    node x(s,0);
    for(i=1;i<=n;i++){
        vis[i] = INF;
    }
    vis[s] = 0;
    priority_queue<node> q;
    q.push(x);
    while(q.size()){
        x = q.top();
        q.pop();
        if(x.dis>vis[x.id]){
            continue;
        }
        for(i=head[x.id];i!=0;i = g[i].next){
            l = x.dis+g[i].w;
            v = g[i].to;
            if(l<vis[v]){
                vis[v] = l;
                q.push(node(v,l));
            }
        }
    }
}
void dij2(int s){
    int i,v;
    long long d;
    node x(s,INF);
    priority_queue<node> q;
    q.push(x);
    for(i=1;i<=n;i++){
        vis2[i] = INF;
    }
    while(q.size()){
        x = q.top();
        q.pop();
        if(x.dis>vis2[x.id]){
            continue;
        }
        for(i=head[x.id];i!=0;i=g[i].next){
            v = g[i].to;
            d = vis[x.id]+g[i].w;
            if(d>vis[v]){
                if(d<vis2[v]){
                    vis2[v]=d;
                    q.push(node(v,vis2[v]));
                }
                continue;
            }
            d = vis2[x.id]+g[i].w;
            if(d<vis2[v]){
                vis2[v]=d;
            }
            q.push(node(v,vis2[v]));
        }
    }
}
int main(){
    int i,a,b,s=1;
    long long c;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>a>>b>>c;
        addedge(a,b,c);
        addedge(b,a,c);
    }
    dij(s);
    dij2(s);
    cout<<vis2[n];
    return 0;
}