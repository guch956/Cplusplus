#include<iostream>
#include<cstdio>
using namespace std;
const int N=300003;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
int dp[N];
int k;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int v,i,num=0;
    dp[s]=0;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs(v,s);
            num++;
            dp[s]+=dp[v];
        }
    }
    dp[s]+=num;
    dp[s]-=k;
    dp[s] = max(0,dp[s]);
}
int erfen(int l,int r){
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    k = mid;
    dfs(1,1);
    if(dp[1]==0){
        return erfen(l,mid);
    }
    else{
        return erfen(mid+1,r);
    }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    cout<<erfen(0,n);
    return 0;
}