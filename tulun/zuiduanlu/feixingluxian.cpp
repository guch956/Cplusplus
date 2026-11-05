#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=10002;
struct edge{
    int to;
    long long w;
    edge(int t,long long b){
        to = t;w = b;
    }
};
vector<edge> g[N];
struct node{
    int id;
    int kk;
    long long dis;
    bool operator <(node const n1)const{
        return n1.dis<dis;
    }
};
long long vis[N][11];
int n,k;
const long long INF=0x3f3f3f3f3f3f3f3f;
void dij(int s){
    int i,j,v;
    node x,y;
    for(i=0;i<n;i++){
        for(j=0;j<=k;j++){
            vis[i][j] = INF;
        }
    }
    vis[s][k]=0;
    x.id=s;x.kk=k;x.dis=0;
    priority_queue<node> q;
    q.push(x);
    while(q.size()){
        x = q.top();
        q.pop();
        if(x.dis>vis[x.id][x.kk]){
            continue;
        }
        for(i=0;i<g[x.id].size();i++){
            v = g[x.id][i].to;
            if(x.kk>=1){
                y.id=v;
                y.dis = x.dis;
                y.kk = x.kk-1;
                if(y.dis<vis[v][y.kk]){
                    vis[v][y.kk]=y.dis;
                    q.push(y);
                }
            }
            y.dis = x.dis+g[x.id][i].w;
            y.kk=x.kk;
            y.id = v;
            if(y.dis<vis[v][y.kk]){
                vis[v][y.kk]=y.dis;
                q.push(y);
            }
        }
    }
}
int main(){
    int m,s1,t1,i,a,b;
    long long c,ans;
    cin>>n>>m>>k;
    cin>>s1>>t1;
    for(i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a].push_back(edge(b,c));
        g[b].push_back(edge(a,c));
    }
    dij(s1);
    ans = INF;
    for(i=0;i<=k;i++){
        ans = min(ans,vis[t1][i]);
    }
    cout<<ans;
    return 0;
}