#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=252;const long long INF = 0x3f3f3f3f3f3f3f3f;
struct edge{
    int to;
    long long w;
};
struct node{
    int id;
    long long dis;
    bool operator <(node const n1)const{
        return n1.dis<dis;
    }
    node(int a,long long b){
        id = a;dis = b;
    }
};
long long dianw[N];
long long vis[N];
long long ans[N][N];
int n;
vector<edge> g[N];
void dij(int s){
    int i,j,v;
    long long d;
    node x(s,0);
    priority_queue <node> q;
    for(i=1;i<=n;i++){
        vis[i] = INF;
    }
    vis[s]=0;
    q.push(x);
    while(q.size()){
        x = q.top();
        q.pop();
        if(x.dis>vis[x.id]){
            continue;
        }
        for(i=0;i<g[x.id].size();i++){
            v = g[x.id][i].to;
            if(dianw[v]<=dianw[s]){
                d = x.dis+g[x.id][i].w;
                if(d<vis[v]){
                    vis[v] = d;
                    q.push(node(v,d));
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        if(vis[i]<INF){
            for(j=1;j<i;j++){
                if(vis[j]<INF){
                    ans[i][j] = min(ans[i][j],vis[i]+vis[j]+dianw[s]);
                    ans[j][i] = ans[i][j];
                }
            }
        }
    }
}
int main(){
    int m,q;
    int a,b,i,j;
    long long c;edge e;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++){
        cin>>dianw[i];
    }
    for(i=1;i<=m;i++){
        cin>>a>>b>>c;
        e.to=a;e.w=c;
        g[b].push_back(e);
        e.to=b;
        g[a].push_back(e);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            ans[i][j] = INF;
        }
    }
    for(i=1;i<=n;i++){
        dij(i);
    }
    for(i=1;i<=n;i++){
        ans[i][i] = dianw[i];
    }
    for(i=1;i<=q;i++){
        cin>>a>>b;
        cout<<ans[a][b]<<endl;
    }
    return 0;
}