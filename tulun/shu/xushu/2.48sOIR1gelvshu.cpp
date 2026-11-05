#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500003;
const ll P=1e9+7;
ll dp[N][4][4];
int deep[N],fa[N],top[N],siz[N],son[N],dfm[N],dfn;
int nex[N<<1],to[N<<1],head[N],ent;
ll dp2[N][4];
int duil[N],pz[N],num;
int zhan[N],topp;
int heads[N],tos[N],nexs[N],ents;
ll mi[N];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void adds(int u,int v){
    ents++;
    nexs[ents]=heads[u];
    tos[ents]=v;
    heads[u]=ents;
}
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    deep[s]=deep[f]+1;
    fa[s]=f;
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        siz[s]+=siz[to[i]];
        if(siz[son[s]]<siz[to[i]]){
            son[s]=to[i];
        }
    }
    siz[s]++;
}
void dfs2(int s,int topx){
    int i;
    top[s]=topx;
    dfm[s]=++dfn;
    if(son[s]){dfs2(son[s],s);}
    for(i=head[s];i;i=nex[i]){
        if(to[i]==fa[s] || to[i]==son[s]){continue;}
        dfs2(to[i],to[i]);
    }
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]){swap(x,y);}
    return x;
}
bool bijiao(int a,int b){
    return dfm[a]<dfm[b];
}
int dfs(int s){
    int i,v,j,nu=1,l,k;
    ll a;
    dp2[s][0]=dp2[s][1]=dp2[s][2]=dp2[s][3]=1;
    if(pz[s]!=-1){
        dp2[s][pz[s]]=dp2[s][pz[s]+2]=0;
    }
    for(i=heads[s];i;i=nexs[i]){
        v = tos[i];
        l = deep[v]-deep[s]+2;
        nu+=dfs(v)+l-3;
        for(j=0;j<4;j++){
            a = 0;
            for(k=0;k<4;k++){
                a+=dp2[v][k]*dp[l][j][k];
            }
            a = a%P;
            dp2[s][j]=(dp2[s][j]*a)%P;
        }
    }
    return nu;
}
ll solve(int n){
    int i,y,x;
    ll an;
    sort(duil+1,duil+num+1,bijiao);
    heads[1]=0;
    ents=0;
    topp=1;
    zhan[1]=1;
    i=duil[1]==1?2:1;
    for(;i<=num;i++){
        x = 0;
        heads[duil[i]]=0;
        while(1){
            y = lca(duil[i],zhan[topp]);
            if(x){adds(zhan[topp],x);}
            if(y==zhan[topp]){
                zhan[++topp]=duil[i];break;
            }
            x = zhan[topp];
            topp--;
            if(dfm[zhan[topp]]<=dfm[y]){
                if(y!=zhan[topp]){
                    heads[y]=0;
                    adds(y,x);
                    zhan[++topp]=y;
                }
                else{
                    adds(zhan[topp],x);
                }
                zhan[++topp]=duil[i];
                break;
            }
        }
    }
    for(i=1;i<topp;i++){
        adds(zhan[i],zhan[i+1]);
    }
    x = dfs(1);
    x = n-x;
    an = (dp2[1][0]+dp2[1][1])%P*mi[x]%P;
    return an;
}
int main(){
    int n,q,i,j,a,b,t,k;
    ll ans=0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        a = read();
        b = read();
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    pz[1]=pz[2]=-1;
    mi[0]=1;mi[1]=2;mi[2]=4;
    for(i=0;i<4;i++){dp[2][i][i]=1;}
    for(i=3;i<=n+1;i++){
        for(j=0;j<4;j++){
            dp[i][0][j]=(dp[i-1][0][j]+dp[i-1][1][j])%P;
            dp[i][1][j]=(dp[i-1][2][j]+dp[i-1][3][j])%P;
            dp[i][2][j]=dp[i-1][0][j];
            dp[i][3][j]=(dp[i-1][2][j]+dp[i-1][3][j])%P;
        }
        pz[i]=-1;
        mi[i]=2*mi[i-1]%P;
    }
    scanf("%d %d",&q,&t);
    for(j=1;j<=q;j++){
        k = read
        num=0;
        for(i=1;i<=k;i++){
            scanf("%d %d",&a,&b);
            b = b^1;
            duil[++num]=a;
            pz[a]=b;
        }
        ans = ans^solve(n);
        for(i=1;i<=k;i++){pz[duil[i]]=-1;}
        if(j%t==0){
            printf("%lld\n",ans);
            ans = 0;
        }
    }
    return 0;
}
