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
};
struct edge{
    long long w;
    int to;
    int next;
};
edge g[200003];
long long vis[100003];
int n,m;
bool done[100003];
int ent=1;int head[100003];const long long INF = 0x3f3f3f3f3f3f3f3f;
void addedge(int u,int to,long long w){
    g[ent].next = head[u];
    g[ent].to = to;
    g[ent].w = w;
    head[u] = ent;
    ent++;
}
void dij(int s){
    int i;
    long long l;
    node x,y;
    for(i=1;i<=n;i++){
        vis[i] = INF;
    }
    x.dis = 0;
    vis[s] = 0;
    x.id = s;
    priority_queue<node> q;
    q.push(x);
    while(q.size()){
        x = q.top();
        q.pop();
        if(done[x.id]){
            continue;
        }
        done[x.id] = 1;
        for(i=head[x.id];i!=0;i = g[i].next){
            l = x.dis+g[i].w;
            if(l<vis[g[i].to]){
                y.id = g[i].to;
                y.dis = l;
                vis[y.id] = y.dis;
                q.push(y);
            }
        }
    }

}
int main(){
    int s,i,a,b;
    long long c;
    cin>>n>>m>>s;
    for(i=0;i<m;i++){
        cin>>a>>b>>c;
        addedge(a,b,c);
    }
    dij(s);
    for(i=1;i<=n;i++){
        cout<<vis[i]<<' ';
    }
    return 0;
}