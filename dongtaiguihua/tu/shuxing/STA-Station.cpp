#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000002;
#define ll long long
struct{
    int to;
    int next;
}g[N<<1];
int n;
int head[N],ent;
ll siz[N];
ll deep[N];
ll ans[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int v,i;
    deep[s]=deep[f]+1;
    ans[1]+=deep[s];
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs1(v,s);
            siz[s]+=siz[v];
        }
    }
    siz[s]++;
}
void dfs2(int s,int f){
    int v,i;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            ans[v]=ans[s]+n-2*siz[v];
            siz[s]=n-siz[v];
            siz[v]=n;
            dfs2(v,s);
            siz[s]=n;
        }
    }
}
int main(){
    int i,a,b,gen=1;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    deep[0]=-1;
    dfs1(1,0);
    dfs2(1,1);
    for(i=1;i<=n;i++){
        if(ans[i]>ans[gen]){
            gen =i;
        }
    }
    cout<<gen;
    return 0;
}