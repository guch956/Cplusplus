#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=10002;
int n;
struct edge{
    int to;
    int w;
    edge(int a,int b){
        to=a;w=b;
    }
};
vector<edge> g[N];
bool vis[N];int s,t;
bool check(int a){
    int i,u,v;
    for(i=1;i<=n;i++){
        vis[i]=0;
    }
    vis[s]=1;
    queue<int> q;
    q.push(s);
    while(q.size()){
        u = q.front();
        q.pop();
        for(i=0;i<g[u].size();i++){
            v = g[u][i].to;
            if(vis[v]==0 && g[u][i].w<=a){
                vis[v]=1;
                q.push(v);
            }
        }
    }
    return vis[t];
}
int erfen(int l,int r){
    if(l==r){
        return l;
    }
    int mid =(l+r)/2;
    if(check(mid)){
        return erfen(l,mid);
    }
    else{
        return erfen(mid+1,r);
    }
}
int main(){
    int m,i,a,b,c;
    cin>>n>>m>>s>>t;
    for(i=1;i<=m;i++){
        cin>>a>>b>>c;
        g[a].push_back(edge(b,c));
        g[b].push_back(edge(a,c));
    }
    cout<<erfen(1,10000);
    return 0;
}