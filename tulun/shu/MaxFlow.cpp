#include<iostream>
#include<queue>
using namespace std;
const int N=50002;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent=1;
int fa[N][17];int cha[N];int sum[N];
int deep[N];
int n;
void addedge(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
void dfs(int s,int f){
    int i,v;
    fa[s][0]=f;
    deep[s]=deep[f]+1;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs(v,s);
        }
    }
}
void jisuan(){
    int i,j;
    for(i=1;i<=16;i++){
        for(j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
}
int LCA(int a,int b){
    int i,c;
    if(deep[a]<deep[b]){swap(a,b);}
    for(i=16;i>=0;i--){
        if((1<<i)<=deep[a]-deep[b]){
            a = fa[a][i];
        }
    }
    for(i=16;i>=0;i--){
        if(fa[a][i]!=fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    if(a!=b){
        return fa[a][0];
    }
    return a;
}
void dfs2(int s,int f){
    int i,v;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs2(v,s);
            sum[s]+=sum[v];
        }
    }
    sum[s]+=cha[s];
}
int main(){
    int i,a,b,k,c;
    scanf("%d %d",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    dfs(1,1);
    jisuan();
    for(i=1;i<=k;i++){
        scanf("%d %d",&a,&b);
        c = LCA(a,b);
        cha[a]++;cha[b]++;
        cha[c]--;
        if(fa[c][0]!=c){
            cha[fa[c][0]]--;
        }
    }
    dfs2(1,1);
    c = 0;
    for(i=1;i<=n;i++){
        c = max(c,sum[i]);
    }
    printf("%d",c);
    return 0;
}