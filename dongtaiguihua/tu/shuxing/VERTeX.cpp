#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
int to[N<<1],nex[N<<1],head[N],ent;
ll w[N<<1];
void adde(int u,int v,ll ww){
    ent++;
    to[ent]=v;
    w[ent]=ww;
    nex[ent]=head[u];
    head[u]=ent;
}
ll val[N],fuhao[N],ma=0x3f3f3f3f3f3f3f3f,mi=1;
void dfs(int s,int f){
    int i,v;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        v = to[i];
        fuhao[v]=-fuhao[s];
        val[v]=w[i]-val[s];
        if(fuhao[v]==1){mi = max(mi,1-val[v]);}
        else{ma = min(ma,val[v]-1);}
        dfs(v,s);
    }
}
int main(){
    int n,i,a,b;
    ll c;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    val[1]=0;fuhao[1]=1;
    dfs(1,1);
    if(mi<=ma){
        printf("YES\n");
        for(i=1;i<=n;i++){
            printf("%lld ",val[i]+fuhao[i]*mi);
        }
    }
    else{printf("NO");}
    return 0;
}