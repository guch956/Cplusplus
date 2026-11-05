#include<iostream>
#include<vector>
using namespace std;
const int N=5003;
struct {
    int to;
    int next;
}g[N<<2];
int head[N],ent=-1;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int n,dfn;
int num[N],low[N],degree[N],ans;
void dfs(int u,int e){
    int v,i;dfn++;
    num[u] = dfn;low[u] = dfn;
    for(i=head[u];i!=-1;i=g[i].next){
        v = g[i].to;
        if(i==(e^1)){continue;}
        if(!num[v]){
            dfs(v,i);
            low[u] = min(low[u],low[v]);
        }
        else {
            low[u] = min(low[u],low[v]);
        }
    }
}
void jisuan(){
    dfs(1,1000000);
    int i,v,a;
    for(i=1;i<=n;i++){
        for(a=head[i];a!=-1;a=g[a].next){
            v = g[a].to;
            if(low[i]!=low[v]){
                degree[low[i]]++;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(degree[i]==1){
            ans++;
        }
    }
    cout<<(ans+1)/2;
}
int main(){
    int m,a,b,i;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        head[i]=-1;
    }
    for(i=0;i<m;i++){
        cin>>a>>b;
        adde(a,b);
        adde(b,a);
    }
    jisuan();
    return 0;
}
