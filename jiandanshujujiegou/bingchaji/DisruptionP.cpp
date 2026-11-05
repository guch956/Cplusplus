#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50003;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
int fa[N][17];
int f[N];
int ans[N];
int e[N][2];
int deep[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
struct node{
    int u;
    int v;
    int len;
}p[N];
bool bijiao(node n1,node n2){
    return n1.len<n2.len;
}
void dfs(int s,int f){
    int i,v;
    fa[s][0]=f;
    deep[s]=deep[f]+1;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs(v,s);
    }
}
int lca(int u,int v){
    int i;
    if(deep[u]<deep[v]){
        swap(u,v);
    }
    for(i=16;i>=0;i--){
        if(deep[fa[u][i]]>=deep[v]){
            u = fa[u][i];
        }
    }
    for(i=16;i>=0;i--){
        if(fa[u][i]!=fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    if(u!=v){
        return fa[u][0];
    }
    return u;
}
int find(int x){
    if(f[x]!=x){
        f[x] = find(f[x]);
    }
    return f[x];
}
int main(){
    int n,i,a,b,m,j,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        e[i][0]=a;
        e[i][1]=b;
        adde(a,b);
        adde(b,a);
        f[i]=i;
    }
    f[n]=n;
    dfs(1,1);
    for(j=1;j<=16;j++){
        for(i=1;i<=n;i++){
            fa[i][j]=fa[fa[i][j-1]][j-1];
        }
    }
    for(i=0;i<m;i++){
        scanf("%d %d %d",&p[i].u,&p[i].v,&p[i].len);
    }
    sort(p,p+m,bijiao);
    for(i=0;i<m;i++){
        a = lca(p[i].u,p[i].v);
        b = find(a);
        c = p[i].u;
        while(c!=b){
            if(c==f[c]){
                ans[c]=p[i].len;
                f[c]=fa[f[c]][0];
            }
            c = find(c);
        }
        c = p[i].v;
        while(c!=b){
            if(c==f[c]){
                ans[c]=p[i].len;
                f[c]=fa[f[c]][0];
            }
            c = find(c);
        }
    }
    for(i=1;i<n;i++){
        if(fa[e[i][0]][0]==e[i][1]){
            a = ans[e[i][0]]?ans[e[i][0]]:-1;
            printf("%d\n",a);
        }
        else{
            a = ans[e[i][1]]?ans[e[i][1]]:-1;
            printf("%d\n",a);
        }
    }
    return 0;
}