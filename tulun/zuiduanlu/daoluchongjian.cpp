#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int N=102;const long long INF=0x3f3f3f3f3f3f3f3f;
struct edge{
    int to;
    long long w;
    bool h;
};
struct node{
    int id;
    long long dis;
    bool operator < (node const n1)const{
        return n1.dis<dis;
    }
    node(int a,long long b){
        id=a;dis = b;
    }
};
vector <edge> g[N];
long long vis[N];int n;
void dij(int s){
    int i;long long d;
    node x(s,0);int v;
    for(i=1;i<=n;i++){
        vis[i] = INF;
    }
    vis[s] = 0;
    priority_queue<node> q;
    q.push(x);
    while (q.size()){
        x = q.top();q.pop();
        if(x.dis>vis[x.id]){
            continue;
        }
        for(i=0;i<g[x.id].size();i++){
            v = g[x.id][i].to;
            d = x.dis+g[x.id][i].w;
            if(g[x.id][i].h){
                d = x.dis;
            }
            if(d<vis[v]){
                vis[v] = d;
                q.push(node(v,d));
            }
        }
    }
}
int main(){
    int m,i,a,b,k,j;
    edge e;
    long long c;
    cin>>n;
    cin>>m;
    for(i=0;i<m;i++){
        cin>>a>>b>>c;
        e.to=b;e.w=c;e.h=1;
        g[a].push_back(e);
        e.to=a;
        g[a].push_back(e);
    }
    cin>>k;
    for(i=0;i<k;i++){
        cin>>a>>b;
        for(j=0;j<g[a].size();j++){
            if(g[a][j].to==b){
                g[a][j].h=0;
            }
        }
        for(j=0;j<g[b].size();j++){
            if(g[b][j].to==a){
                g[b][j].h=0;
            }
        }
    }
    cin>>a>>b;
    dij(a);
    cout<<vis[b];
    return 0;
}