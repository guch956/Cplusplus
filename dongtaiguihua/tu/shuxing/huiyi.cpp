#include<iostream>
#include<cstdio>
using namespace std;
const int N=50002;
struct {
    int to;
    int next;
}g[N<<2];
int head[N],ans[N],subt[N];int ent=1;
int n;
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
int dfs1(int s,int fa){
    int i,u,v;
    int sum=0;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=fa){
            sum+=dfs1(v,s);
            subt[s]+=subt[v];
            sum+=subt[v];
        }
    }
    subt[s]++;
    return sum;
}
void dfs2(int s,int fa){
    int i,v;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=fa){
            ans[v]=ans[s]-2*subt[v]+n;
            dfs2(v,s);
        }
    }
}
int main(){
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        add(a,b);
    }
    ans[1]=dfs1(1,0);
    dfs2(1,0);
    a = 0,b = 0x3f3f3f3f;
    for(i=1;i<=n;i++){
        if(ans[i]<b){
            b = ans[i];
            a = i;
        }
    }
    printf("%d %d",a,b);
    return 0;
}