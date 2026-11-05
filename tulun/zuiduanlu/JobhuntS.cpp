#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct edge{
    int to;
    int w;
    edge(int a,int b){
        to=a;w=b;
    }
};
const int N=222;const int INF=0x3f3f3f3f;
vector<edge> g[N];
int times[N],vis[N];
bool inque[N];
int main(){
    int d,n,m,s,f,i,k,a,b;
    cin>>d>>m>>n>>f>>s;
    for(i=1;i<=m;i++){
        cin>>a>>b;
        g[a].push_back(edge(b,-d));
    }
    for(i=1;i<=f;i++){
        cin>>a>>b>>k;
        g[a].push_back(edge(b,k-d));
    }
    for(i=1;i<=n;i++){
        vis[i]=INF;
    }
    vis[s]=-d;
    queue<int> q;
    q.push(s);
    while(q.size()){
        a = q.front();q.pop();
        inque[a]=0;
        for(i=0;i<g[a].size();i++){
            b = g[a][i].to;
            d = vis[a]+g[a][i].w;
            if(d<vis[b]){
                vis[b]=d;
                if(inque[b]==0){
                    inque[b]=1;
                    times[b]++;
                    if(times[b]>n){
                        cout<<-1;
                        return 0;
                    }
                    q.push(b);
                }
            }
        }
    }
    k = INF;
    for(i=1;i<=n;i++){
        k = min(k,vis[i]);
    }
    cout<<-k;
    return 0;
}