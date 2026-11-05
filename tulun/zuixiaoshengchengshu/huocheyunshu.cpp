#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10003;
const int INF=0x3f3f3f3f;
struct {
    int to;
    int next;
    int len;
}g[N<<1];
int head[N],ent=0;
int fa[N][15];
int minl[N][15];
int n;
int deep[N];
void adde(int u,int v,int l){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].len = l;
    head[u] = ent;
}
void dfs(int s,int f){
    int v,i;
    deep[s] = deep[f]+1;
    fa[s][0]=f;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        minl[v][0] = g[i].len;
        dfs(v,s);
    }
}
void beizeng(){
    int i,j;
    for(i=1;i<=14;i++){
        for(j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
            minl[j][i]=min(minl[j][i-1],minl[fa[j][i-1]][i-1]);
        }
    }
}
struct e{
    int u1;
    int u2;
    int w;
}g1[N*5];
bool bijiao(e & a,e & b){
    return a.w>b.w;
}
int f[N];
int find_set(int x){
    if(f[x]!=x){
        f[x] = find_set(f[x]);
    }
    return f[x];
}
int query(int x,int y){
    int ans=INF,i;
    if(deep[x]>deep[y]){
        swap(x,y);
    }
    for(i=14;i>=0;i--){
        if(deep[x]+(1<<i)<=deep[y]){
            ans = min(ans,minl[y][i]);
            y = fa[y][i];
        }
    }
    for(i=14;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            ans = min(ans,min(minl[y][i],minl[x][i]));
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x!=y){
        ans = min(ans,min(minl[x][0],minl[y][0]));
    }
    return ans;
}
int main(){
    int m,i,q,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        f[i] = i;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&g1[i].u1,&g1[i].u2,&g1[i].w);
    }
    sort(g1+1,g1+m+1,bijiao);
    for(i=1;i<=m;i++){
        a = find_set(g1[i].u1);
        b = find_set(g1[i].u2);
        if(a!=b){
            adde(g1[i].u1,g1[i].u2,g1[i].w);
            adde(g1[i].u2,g1[i].u1,g1[i].w);
            f[a] = b;
        }
    }
    for(i=1;i<=n;i++){
        if(f[i]==i){
            dfs(i,i);
            minl[i][0] = INF;
        }
    }
    beizeng();
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        if(find_set(a)!=find_set(b)){
            printf("-1\n");
        }
        else{
            printf("%d\n",query(a,b));
        }
    }
    return 0;
}
