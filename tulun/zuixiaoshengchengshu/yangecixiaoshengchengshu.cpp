#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=100003;
int fa[N][18];
int f[N];
ll zuida[N][18],cida[N][18];
struct {
    int to;
    int next;
    ll len;
}g1[N<<1];
int head[N],ent;
int deep[N];
int n;
void adde(int u,int v,ll l){
    ent++;
    g1[ent].to=v;
    g1[ent].next=head[u];
    g1[ent].len=l;
    head[u] = ent;
}
void dfs(int s,int f){
    int v,i;
    fa[s][0] = f;
    deep[s] = deep[f]+1;
    for(i=head[s];i;i=g1[i].next){
        v = g1[i].to;
        if(v==f){continue;}
        zuida[v][0] = g1[i].len;
        cida[v][0] = -INF;
        dfs(v,s);
    }
}
inline void hebing(ll & x,ll & y,ll a,ll b,ll c,ll d){
    x = max(a,c);
    y = max(b,d);
    if(a!=c){
        y = max(y,min(a,c));
    }
}
void beizeng(){
    int i,j;
    for(i=1;i<=17;i++){
        for(j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
            hebing(zuida[j][i],cida[j][i],zuida[j][i-1],cida[j][i-1],zuida[fa[j][i-1]][i-1],cida[fa[j][i-1]][i-1]);
        }
    }
}
void chaxun(int x,int y,ll & z,ll & c){
    int i;
    if(deep[x]>deep[y]){
        swap(x,y);
    }
    for(i=17;i>=0;i--){
        if(deep[x]+(1<<i)<=deep[y]){
            hebing(z,c,z,c,zuida[y][i],cida[y][i]);
            y = fa[y][i];
        }
    }
    for(i=17;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            hebing(z,c,z,c,zuida[x][i],cida[x][i]);
            hebing(z,c,z,c,zuida[y][i],cida[y][i]);
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x!=y){
        hebing(z,c,z,c,zuida[x][0],cida[x][0]);
        hebing(z,c,z,c,zuida[y][0],cida[y][0]);
    }
}
struct e{
    int u1;
    int u2;
    ll w;
}g[N*3];
bool bijiao(e & a, e & b){
    return a.w<b.w;
}
int find_set(int x){
    if(f[x]!=x){
        f[x]=find_set(f[x]);
    }
    return f[x];
}
int main(){
    int m,i,a,b;
    ll ans=0,delta=INF,zuida0,cida0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %lld",&g[i].u1,&g[i].u2,&g[i].w);
    }
    sort(g+1,g+m+1,bijiao);
    for(i=1;i<=n;i++){
        f[i] = i;
    }
    for(i=1;i<=m;i++){
        a=find_set(g[i].u1);
        b=find_set(g[i].u2);
        if(a!=b){
            ans+=g[i].w;
            f[a] = b;
            adde(g[i].u1,g[i].u2,g[i].w);
            adde(g[i].u2,g[i].u1,g[i].w);
            g[i].w=-1;
        }
    }
    zuida[1][0]=-INF;
    cida[1][0]=-INF;
    dfs(1,1);
    beizeng();
    for(i=1;i<=m;i++){
        if(g[i].w!=-1){
            zuida0=cida0=-INF;
            chaxun(g[i].u1,g[i].u2,zuida0,cida0);
            if(g[i].w==zuida0){
                delta=min(delta,g[i].w-cida0);
            }
            else{
                delta=min(delta,g[i].w-zuida0);
            }
        }
    }
    printf("%lld",ans+delta);
    return 0;
}