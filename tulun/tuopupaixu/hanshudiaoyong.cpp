#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
const ll P=998244353;
int head[N],to[N],nex[N],ent;
int paixu[N],top;
ll chuzhi[N];
ll chengji[N];
int caozuo[N];
int xiabiao[N];
ll shu[N];
ll sum[N];
ll pre[N];
int type[N];
bool vis[N];
void add(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s){
    int i;
    chengji[s]=1;
    vis[s]=1;
    if(type[s]==2){chengji[s]=shu[s];}
    for(i=head[s];i;i=nex[i]){
        if(vis[to[i]]==0){dfs(to[i]);}
        chengji[s]=chengji[s]*chengji[to[i]]%P;
    }
    paixu[++top]=s;
}
int main(){
    int n,m,i,t,a,b,q;
    ll pai,total=1;
    /*freopen("10.in","r",stdin);
    freopen("10.out","w",stdout);*/
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&chuzhi[i]);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d",&t);
        type[i]=t;
        if(t==1){
            scanf("%d %lld",&xiabiao[i],&shu[i]);
        }
        else if(t==2){
            scanf("%lld",&shu[i]);
        }
        else{
            scanf("%d",&a);
            while(a--){
                scanf("%d",&b);
                add(i,b);
                pre[b]++;
            }
        }
    }
    scanf("%d",&q);
    for(i=1;i<=m;i++){
        if(pre[i]==0){
            dfs(i);
        }
    }
    for(i=1;i<=m;i++){pre[i]=0;}
    for(i=1;i<=q;i++){
        scanf("%d",&caozuo[i]);
        total=total*chengji[caozuo[i]]%P;
    }
    pai=1;
    for(i=q;i>=1;i--){
        pre[caozuo[i]]+=pai;
        pre[caozuo[i]]%=P;
        pai=pai*chengji[caozuo[i]]%P;
    }
    for(i=m;i>=1;i--){
        sum[paixu[i]]+=pre[paixu[i]];
        pai=1;
        for(a=head[paixu[i]];a;a=nex[a]){
            sum[to[a]]+=(sum[paixu[i]]*pai)%P;
            sum[to[a]]%=P;
            pai=pai*chengji[to[a]]%P;
        }
    }
    pai=1;
    for(i=1;i<=n;i++){
        chuzhi[i]=chuzhi[i]*total%P;
    }
    for(i=1;i<=m;i++){
        if(type[i]==1){
            chuzhi[xiabiao[i]]+=(sum[i]*shu[i])%P;
            chuzhi[xiabiao[i]]%=P;
        }
    }
    for(i=1;i<=n;i++){
        printf("%lld ",chuzhi[i]);
    }
    return 0;
}