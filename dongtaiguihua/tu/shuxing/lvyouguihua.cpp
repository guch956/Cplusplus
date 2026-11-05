#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int len[N],len2[N],xiabiao[N];
int zhijing;
bool ans[N];
void dfs1(int s,int f){
    int v,i,a;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
        a = len[v]+1;
        if(a>len[s]){
            len2[s] = len[s];
            len[s] = a;
            xiabiao[s] = v;
        }
        else if(a>len2[s]){
            len2[s] = a;
        }
    }
    zhijing = max(zhijing,len[s]+len2[s]);
}
void dfs2(int s,int f){
    int v,i,t;
    if(len[s]+len2[s]==zhijing){ans[s]=1;}
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        t = xiabiao[s]==v?len2[s]+1:len[s]+1;
        if(t>len[v]){
            len2[v] = len[v];
            len[v] = t;
            xiabiao[v] = s;
        }
        else if(t>len2[v]){
            len2[v] = t;
        }
        dfs2(v,s);
    }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a+1,b+1);
        adde(b+1,a+1);
    }
    dfs1(1,1);
    dfs2(1,1);
    for(i=1;i<=n;i++){
        if(ans[i]){
            printf("%d\n",i-1);
        }
    }
    return 0;
}