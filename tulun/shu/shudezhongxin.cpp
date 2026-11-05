#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=300003;
ll tree1[N];
ll tree2[N];
ll n,ans;
ll num[N];
inline int lowbit(int x){return x&(-x);}
ll chaxun(int x,ll *t){
    ll a=0;
    while(x>0){
        a+=t[x];
        x-=lowbit(x);
    }
    return a;
}
void update(int x,ll *t,ll d){
    while(x<=n){
        t[x]+=d;
        x+=lowbit(x);
    }
}
int g;
ll siz[N];
ll cida;
int son[N];
int nex[N<<1],to[N<<1];
int head[N],ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int i;
    siz[s]=1;
    son[s]=0;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        siz[s]+=siz[to[i]];
        if(siz[to[i]]>siz[son[s]]){
            son[s]=to[i];
        }
    }
    if(max(siz[son[s]],n-siz[s])<max(siz[son[g]],n-siz[g])){
        g = s;
    }
}
void dfs2(int s,int f){
    int i;
    update(siz[s],tree1,1);
    ans+=s*(chaxun(2*siz[s],tree1)-chaxun(2*siz[son[s]]-1,tree1));
    ans-=s*(chaxun(n-2*siz[son[s]],tree1)-chaxun(n-2*siz[s]-1,tree1));
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs2(to[i],s);
    }
    update(siz[s],tree1,-1);
}
void dfs3(int s,int f){
    int i;
    ans-=chaxun(siz[s],tree2);
    update(n-2*siz[son[s]]+1,tree2,-s);
    update(n-2*siz[s],tree2,s);
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs3(to[i],s);
    }
    update(n-2*siz[son[s]]+1,tree2,s);
    update(n-2*siz[s],tree2,-s);
}
void dfs4(int s,int f,bool is){
    int i;
    if(is){
        if(n-siz[s]>=2*siz[son[g]]){ans+=g;}
    }
    else{
        if(n-siz[s]>=2*cida && n+siz[s]>=2*siz[son[g]]){ans+=g;}
    }
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs4(to[i],s,is);
    }
}
int main(){
    int T,i,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        ent=0;ans=0;cida=0;g=0;
        memset(head,0,sizeof(head));
        memset(num,0,sizeof(num));
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        dfs1(1,0);
        dfs1(g,0);
        for(i=1;i<=n;i++){num[siz[i]]++;}
        num[n]--;
        for(i=1;i<=n;i++){num[i]=num[i-1]+num[i];}
        for(i=1;i<=n;i++){
            if(i!=g){ans+=i*(num[n-2*siz[son[i]]]-num[n-2*siz[i]-1]);}
        }
        for(i=head[g];i;i=nex[i]){
            dfs2(to[i],g);
            if(to[i]!=son[g] && siz[to[i]]>cida){cida=siz[to[i]];}
        }
        for(i=head[g];i;i=nex[i]){
            dfs3(to[i],g);
        }
        for(i=head[g];i;i=nex[i]){
            if(to[i]==son[g]){dfs4(to[i],g,0);}
            else{dfs4(to[i],g,1);}
        }
        printf("%lld\n",ans);
    }
    return 0;
}