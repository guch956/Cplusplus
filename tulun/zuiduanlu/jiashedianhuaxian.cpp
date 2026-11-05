#include<iostream>
#include<queue>
using namespace std;
const int N=1002;const int INF=0x3f3f3f3f;
struct edge{
    int to;
    int w;
    edge(int a,int b){
        to=a;w=b;
    }
};
vector<edge> g[N];int vis[N];
int n,k;
bool check(int c){
    int i,u,v;
    for(i=2;i<=n;i++){
        vis[i]=INF;
    }
    vis[1]=0;
    deque<int> q;
    q.push_front(1);
    while(q.size()){
        u=q.front();q.pop_front();
        for(i=0;i<g[u].size();i++){
            v = g[u][i].to;
            if(g[u][i].w>c){
                if(vis[u]+1<vis[v]){
                vis[v]=vis[u]+1;
                q.push_back(v);
                }
            }
            else{
                if(vis[u]<vis[v]){
                vis[v]=vis[u];
                q.push_front(v);
                }
            }
            
        }
    }
    if(vis[n]<=k){
        return 1;
    }
    return 0;
}
int erfen(int l,int r){
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(check(mid)){
        return erfen(l,mid);
    }
    else{
        return erfen(mid+1,r);
    }
}
int main(){
    int m,a,b,c;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c;
        g[a].push_back(edge(b,c));
        g[b].push_back(edge(a,c));
    }
    if(check(1000004)){
        a = erfen(0,1000001);
        cout<<a;
    }
    else{
        cout<<-1;
    }
    return 0;
}