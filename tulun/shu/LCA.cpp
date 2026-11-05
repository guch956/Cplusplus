#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=500002;
struct {
    int to;
    int next;
}g[N<<2];
int head[N];int ent=1;int n,d;
void add(int u,int v){
    g[ent].to=u;
    g[ent].next=head[v];
    head[v]=ent;
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
int fa[N][20];int deep[N];
void bfs(int s){
    int i,v,u;
    queue<int> q;
    fa[s][0]=s;deep[s]=0;
    q.push(s);
    while(q.size()){
        u = q.front();q.pop();
        for(i=head[u];i!=0;i=g[i].next){
            v = g[i].to;
            if(fa[v][0]==0){
                fa[v][0]=u;
                deep[v]=deep[u]+1;
                q.push(v);
            }
        }
    }
}
void beizeng(){
    int i,j;
    for(i=1;i<=19;i++){
        for(j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
}
int LCA(int a,int b){
    int i;
    if(deep[a]<deep[b]){swap(a,b);}
    for(i=19;i>=0;i--){
        if(deep[a]-deep[b]>=(1<<i)){
            a = fa[a][i];
        }
    }
    for(i=19;i>=0;i--){
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
int main(){
    int i,a,b,s;
    scanf("%d %d %d",&n,&d,&s);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        add(a,b);
    }
    bfs(s);
    beizeng();
    while(d){
        scanf("%d %d",&a,&b);
        printf("%d\n",LCA(a,b));
        d--;
    }
    return 0;
}