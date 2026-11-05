#include<iostream>
#include<cstdio>
using namespace std;
const int N=300003;
const int INF=0x3f3f3f3f;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
bool guanjian[N];
int dp1[N],dp2[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int n,m,ans,mid;
void dfs(int s,int f){
    int i,v;
    dp1[s]=-INF;
    dp2[s]=INF;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs(v,s);
            dp1[s]=max(dp1[s],dp1[v]+1);
            dp2[s]=min(dp2[s],dp2[v]+1);
        }
    }
    if(dp1[s]+dp2[s]<=mid){dp1[s]=-INF;}
    if(dp2[s]>mid && guanjian[s]){dp1[s]=max(dp1[s],0);}
    if(dp1[s]==mid){
        dp1[s]=-INF;
        dp2[s]=0;
        ans++;
    }
}
int check(){
    ans=0;
    dfs(1,0);
    if(dp1[1]>=0){
        ans++;
    }
}
int erfen(int l,int r){
    while(l<r){
        mid=(l+r)>>1;
        check();
        if(ans<=m){r = mid;}
        else{l = mid+1;}
    }
    return l;
}
int main(){
    int i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&guanjian[i]);
    }
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    printf("%d",erfen(0,n-1));
    return 0;
}