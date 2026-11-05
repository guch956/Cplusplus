#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=300004;
ll dnum[N];
ll sdep[N];
ll deep[N],ans;
ll siz[N];
int head[N],to[N<<1],nex[N<<1],ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    deep[s]=deep[f]+1;
    sdep[s]=siz[s]=0;
    dnum[deep[s]]++;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        ans+=(sdep[to[i]]+siz[to[i]])*siz[s];
        ans+=sdep[s]*siz[to[i]];
        ans-=siz[s]*siz[to[i]];
        sdep[s]+=sdep[to[i]];
        sdep[s]+=siz[to[i]];
        siz[s]+=siz[to[i]];
    }
    siz[s]++;
    ans+=sdep[s];
}
int main(){
    int T,n,i,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans = 0;
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        dfs(1,0);
        for(i=1;i<=n;i++){
            sdep[i]=sdep[i-1]+dnum[i];
        }
        for(i=1;i<=n;i++){
            ans = ans-i*dnum[i]*(sdep[i-1]-sdep[n]+sdep[i]);
        }
        printf("%lld\n",ans);
        for(i=1;i<=n;i++){
            dnum[i]=0;
            sdep[i]=0;
            head[i]=0;
        }
        ent=0;
    }
    return 0;
}