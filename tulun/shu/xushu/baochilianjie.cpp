#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
int fa[N][17];
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
int p[N<<1];
int dfm[N],dfn;
int deep[N];
int sta[N],top;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i,v;
    fa[s][0]=f;
    dfm[s]=++dfn;
    deep[s]=deep[f]+1;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs(v,s);
    }
}
bool bijiao(int x,int y){
    return dfm[x]<dfm[y];
}
int lca(int x,int y){
    int i;
    if(deep[x]<deep[y]){swap(x,y);}
    for(i=16;i>=0;i--){
        if(deep[fa[x][i]]>=deep[y]){
            x = fa[x][i];
        }
    }
    for(i=16;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x!=y){
        return fa[x][0];
    }
    return x;
}
int main(){
    int n,i,a,b,j,q,m,ans,z;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    for(j=1;j<=16;j++){
        for(i=1;i<=n;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&m);
        ans=0;
        for(i=0;i<m;i++){
            scanf("%d",&p[i]);
        }
        sort(p,p+m,bijiao);
        top=1;
        sta[top]=p[0];
        for(i=1;i<m;i++){
            z = lca(sta[top],p[i]);
            while(dfm[sta[top]]>dfm[z]){top--;}
            if(top==0){
                ans+=deep[sta[1]]-deep[z];
                sta[++top]=z;
            }
            sta[++top]=p[i];
            ans+=deep[p[i]]-deep[z];
        }
        printf("%d\n",ans);
    }
    return 0;
}