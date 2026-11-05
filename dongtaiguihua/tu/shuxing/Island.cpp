#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=1000002;
struct {
    int to;
    int next;
    ll len;
}g[N<<1];
int head[N],ent=-1,e1;
void adde(int a,int b,ll c){
    ent++;
    g[ent].to=b;
    g[ent].next=head[a];
    g[ent].len=c;
    head[a]=ent;
}
ll dp[N],zj;
void zhijing(int s,int f){
    int v,i;
    ll ma=0;
    for(i=head[s];i!=-1;i=g[i].next){
        v = g[i].to;
        if(v==f || i==e1){
            continue;
        }
        zhijing(v,s);
        zj=max(zj,ma+dp[v]+g[i].len);
        ma=max(ma,dp[v]+g[i].len);
    }
    dp[s]=ma;
}
bool finish[N];
ll zhan1[N];
int top1;
int zhan2[N],top2;
void dfs(int s,int f){
    int v,i;
    if(finish[s]==1){
        if(top2==0){
            i = top1-1;
            top2=1;
            zhan2[1]=zhan1[top1];
            while(g[zhan1[i]].to!=s && i>=1){
                top2++;
                zhan2[top2]=zhan1[i];
                i--;
            }
        }
        return ;
    }
    finish[s]=1;
    for(i=head[s];i!=-1;i=g[i].next){
        v = g[i].to;
        if(i== (f^1)){continue;}
        top1++;
        zhan1[top1]=i;
        dfs(v,i);
        top1--;
    }
}
ll totol,ans;
void jisuan(){
    ans=0;
    int i;ll ma=0,sum=0;
    e1=zhan2[1]^1;
    zj=0;
    zhijing(g[zhan2[1]].to,g[zhan2[top2]].to);
    ans = max(ans,zj);
    for(i=2;i<=top2;i++){
        e1=(zhan2[i]^1);
        zj=0;
        zhijing(g[zhan2[i]].to,g[zhan2[i-1]].to);
        ans=max(ans,zj);
    }
    zhan1[1]=0;ma=dp[g[zhan2[1]].to];
    for(i=2;i<=top2;i++){
        zhan1[i]=zhan1[i-1]+g[zhan2[i-1]].len;
        ans = max(ans,dp[g[zhan2[i]].to]+zhan1[i]+ma);
        ma=max(ma,dp[g[zhan2[i]].to]-zhan1[i]);
    }
    zhan1[1]=dp[g[zhan2[1]].to];
    ma=0;
    for(i=2;i<=top2-1;i++){
        zhan1[i]=max(zhan1[i-1],zhan1[i]+dp[g[zhan2[i]].to]);
    }
    for(i=top2;i>=2;i--){
        sum+=g[zhan2[i]].len;
        ma = max(ma,sum+dp[g[zhan2[i]].to]+zhan1[i-1]);
    }
    ans = max(ans,ma);
}
int main(){
    int n,i,a;
    ll c;
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %lld",&a,&c);
        adde(i,a,c);
        adde(a,i,c);
    }
    for(i=1;i<=n;i++){
        if(finish[i]==0){
            top1=0;top2=0;
            dfs(i,2*n+2);
            ans=0;
            jisuan();
            totol+=ans;
        }
    }
    printf("%lld",totol);
    return 0;
}
