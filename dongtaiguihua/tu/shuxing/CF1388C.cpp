#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
int nex[N<<1],to[N<<1],head[N],ent;
ll renshu[N],jiance[N],sum[N];
bool xing;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    ll r=renshu[s];
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        renshu[s]+=renshu[to[i]];
        sum[s]+=sum[to[i]];
    }
    jiance[s]=renshu[s]-jiance[s];
    if(jiance[s]%2!=0){xing=0;return;}
    jiance[s]=jiance[s]/2;
    if(jiance[s]>r+sum[s] || jiance[s]<0){xing=0;return;}
    sum[s]=jiance[s];
}
int main(){
    int T,i,n,m,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        ent=0;xing=1;
        for(i=1;i<=n;i++){scanf("%lld",&renshu[i]);sum[i]=0;}
        for(i=1;i<=n;i++){scanf("%lld",&jiance[i]);head[i]=0;}
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        dfs(1,1);
        if(xing){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}