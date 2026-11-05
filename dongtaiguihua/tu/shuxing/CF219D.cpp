#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
struct {
    int next;
    int to;
    bool y;
}g[N<<1];
int head[N],ans[N],ma,ent;
void adde(int a,int b){
    ent++;
    g[ent].next=head[a];
    g[ent].to=b;
    g[ent].y=0;
    head[a]=ent;
    ent++;
    g[ent].next=head[b];
    g[ent].to=a;
    g[ent].y=1;
    head[b]=ent;
}
void dfs1(int s,int f){
    int i,v;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            ans[1]+=g[i].y;
            dfs1(v,s);
        }
    }
}
void dfs2(int s,int f){
    int i,v;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            ans[v]=ans[s]+1-2*g[i].y;
            dfs2(v,s);
        }
    }
}
int main(){
    int n,i,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    dfs1(1,1);
    dfs2(1,1);
    ma=0x3f3f3f3f;
    for(i=1;i<=n;i++){
        ma = min(ma,ans[i]);
    }
    printf("%d\n",ma);
    for(i=1;i<=n;i++){
        if(ans[i]==ma){
            printf("%d ",i);
        }
    }
    return 0;
}
