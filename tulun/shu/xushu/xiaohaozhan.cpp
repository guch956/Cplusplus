#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=250003;
struct {
    int to;
    int next;
    ll len;
}g[N<<1],gx[N];
int head[N],ent;
int headx[N],entx;
int deep[N],fa[N][18],mlen[N][18];
int dfm[N],dfn;
int sta[N<<1];
int top;
int q[N];
ll dp[N];
bool guanjian[N];
void adde(int u,int v,ll l){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    g[ent].len=l;
    head[u]=ent;
}
void addex(int u,int v,ll l){
    entx++;
    gx[entx].to=v;
    gx[entx].next=headx[u];
    gx[entx].len=l;
    headx[u]=entx;
}
int lca(int x,int y){
    int i;
    if(deep[x]<deep[y]){swap(x,y);}
    for(i=17;i>=0;i--){
        if(deep[fa[x][i]]>=deep[y]){
            x = fa[x][i];
        }
    }
    for(i=17;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x==y){return x;}
    return fa[x][0];
}
ll dis(int x,int y){
    int i,l=0x3f3f3f3f;
    for(i=17;i>=0;i--){
        if(deep[fa[y][i]]>=deep[x]){
            l = min(l,mlen[y][i]);
            y = fa[y][i];
        }
    }
    return l;
}
void dfs(int s,int f){
    int i,v;
    deep[s]=deep[f]+1;
    dfm[s]=++dfn;
    fa[s][0]=f;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        mlen[v][0]=g[i].len;
        dfs(v,s);
    }
}
bool bijiao(int a,int b){
    return dfm[a]<dfm[b];
}
void dfsx(int s){
    int i,v;
    dp[s]=0;
    for(i=headx[s];i;i=gx[i].next){
        v = gx[i].to;
        dfsx(v);
        if(guanjian[v]){
            dp[s]+=gx[i].len;
        }
        else{
            dp[s]+=min(gx[i].len,dp[v]);
        }
    }
}
void build(int m){
    int i,x,y;
    sort(q,q+m+1,bijiao);
    sta[1]=1;
    top=1;
    entx=0;
    headx[1]=0;
    for(i=1;i<=m;i++){
        x = q[i];
        if(guanjian[x]){continue;}
        guanjian[x]=1;
        y = lca(x,sta[top]);
        if(y!=sta[top]){
            while(dfm[y]<dfm[sta[top-1]]){
                addex(sta[top-1],sta[top],dis(sta[top-1],sta[top]));
                top--;
            }
            if(dfm[y]>dfm[sta[top-1]]){
                headx[y]=0;
                addex(y,sta[top],dis(y,sta[top]));
                sta[top]=y;
            }
            else{
                addex(y,sta[top],dis(y,sta[top]));
                top--;
            }
        }
        headx[x]=0;
        sta[++top]=x;
    }
    for(i=1;i<top;i++){
        addex(sta[i],sta[i+1],dis(sta[i],sta[i+1]));
    }
    dfsx(1);
    for(i=1;i<=m;i++){
        guanjian[q[i]]=0;
    }
    printf("%lld\n",dp[1]);
}
int main(){
    int n,q1,i,a,b,m;
    ll c;
    q[0]=1;
    mlen[1][0]=0x3f3f3f3f;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    dfs(1,1);
    for(m=1;m<=17;m++){
        for(i=1;i<=n;i++){
            fa[i][m]=fa[fa[i][m-1]][m-1];
            mlen[i][m]=min(mlen[i][m-1],mlen[fa[i][m-1]][m-1]);
        }
    }
    scanf("%d",&q1);
    while(q1--){
        scanf("%d",&m);
        for(i=1;i<=m;i++){
            scanf("%d",&q[i]);
        }
        build(m);
    }
    return 0;
}

