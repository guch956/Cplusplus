#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int ans=0;
int dp[N];
struct{
    int next;
    int to;
}g[N<<1];
int head[N],ent;
void adde(int a,int b){
    ent++;
    g[ent].next=head[a];
    g[ent].to=b;
    head[a]=ent;
    ent++;
    g[ent].next=head[b];
    g[ent].to=a;
    head[b]=ent;
}
void jisuan(int s,int f){
    int v,i,ma=0;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v==f){
            continue;
        }
        jisuan(v,s);
        ans=max(ans,dp[v]+1+ma);
        ma=max(ma,dp[v]+1);
    }
    dp[s]=ma;
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    jisuan(1,1);
    printf("%d",ans);
    return 0;
}