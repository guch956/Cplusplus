#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=502;const long long INF=0x3f3f3f3f3f3f3f3f;
struct edge{
    int to;
    long long w;
    edge (int a,long long b){
        to=a;w=b;
    }
};
vector<edge> g[N];
int n;
int times[N];bool inque[N];
long long vis[N];
void spfa(int s){
    int i,v,u;
    long long d;
    for(i=0;i<=n;i++){
        vis[i]=INF;
        times[i]=0;
        inque[i]=0;
    }
    vis[s]=0;
    queue<int> q;
    q.push(s);
    inque[s]=1;
    while(q.size()){
        u=q.front();
        q.pop();
        inque[u]=0;
        for(i=0;i<g[u].size();i++){
            v = g[u][i].to;
            d = vis[u]+g[u][i].w;
            if(d<vis[v]){
                vis[v]=d;
                if(!inque[v]){
                    times[v]++;
                    if(times[v]>n+1){
                        cout<<"YES"<<endl;
                        return ;
                    }
                    inque[v]=1;
                    q.push(v);
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    int m,w,i,a,c,t;
    long long b;
    cin>>t;
    while(t>0){
        t--;
        
    cin>>n>>m>>w;
    for(i=0;i<=n;i++){
        g[i].clear();
    }
    for(i=1;i<=m;i++){
        cin>>a>>c>>b;
        g[a].push_back(edge(c,b));
        g[c].push_back(edge(a,b));
    }
    for(i=1;i<=w;i++){
        cin>>a>>c>>b;
        g[a].push_back(edge(c,-b));
    }
    for(i=1;i<=n;i++){
        g[0].push_back(edge(i,0));
    }
    spfa(0);}
    return 0;
}