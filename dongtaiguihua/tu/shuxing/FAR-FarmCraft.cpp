#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500003;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
int dp[N],p[N],w[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
bool check(int nu,int a){
    int i;
    for(i=0;i<nu;i++){
        if(((a+1-p[i])>>1) <= i){
            return 0;
        }
    }
    return 1;
}
void dfs(int s,int f){
    int v,i,num=0;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f)continue;
        dfs(v,s);
    }
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f)continue;
        p[num]=dp[v];
        num++;
    }
    if(num){
        sort(p,p+num,greater<int>());
        int l=p[0]+1,r=p[0]+2*num-1,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(check(num,mid)){r = mid;}
            else{l = mid+1;}
        }
        dp[s] = l;
    }
    dp[s] = max(dp[s],w[s]);
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,0);
    printf("%d",max(dp[1],w[1]+2*(n-1)));
    return 0;
}


 