#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=3002;const long long INF=0x3f3f3f3f3f3f3f3f;
struct edge{
    int to;
    long long w;
    edge(int a,long long b){
        to=a;w = b;
    }
};
struct node{
    int id;
    long long dis;
    bool operator <(node const n1) const{
        return n1.dis<dis;
    }
    node (int a,long long b){
        id=a;dis=b;
    }
};
vector<edge> g1[N];vector <int> g2[N];
long long vis[N];int rudu[N];
int n;
void dij(int s){
    int i,v;
    long long d;
    node x(s,0);
    for(i=1;i<=n;i++){
        vis[i]=INF;
    }
    vis[s]=0;
    priority_queue<node> q;
    q.push(x);
    while(q.size()){
        x = q.top();
        q.pop();
        if(x.dis>vis[x.id]){
            continue;
        }
        for(i=0;i<g2[x.id].size();i++){
            v = g2[x.id][i];
            rudu[v]--;
            if(rudu[v]==0 && vis[v]<INF){
                vis[v]=max(x.dis,vis[v]);
                q.push(node(v,vis[v]));
            }
        }
        for(i=0;i<g1[x.id].size();i++){
            v = g1[x.id][i].to;
            d = x.dis+g1[x.id][i].w;
            if(d<vis[v] ){
                vis[v]=d;
                if(rudu[v]==0){
                q.push(node(v,d));}
            }
        }
    }
}
int main(){
    int m,l,i,j,a,b;
    long long c;
    cin>>n>>m;
    for(i=1;i<=m;i++){
        cin>>a>>b>>c;
        g1[a].push_back(edge(b,c));
    }
    for(i=1;i<=n;i++){
        cin>>l;
        rudu[i]=l;
        for(j=1;j<=l;j++){
            cin>>a;
            g2[a].push_back(i);
        }
    }
    dij(1);
    cout<<vis[n];
    return 0;
}