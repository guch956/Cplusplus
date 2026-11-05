#include<iostream>
#include<cstdio>
#include<algorithm>
const int N=100002;
inline int lowbit(int x){return x&(-x);}
struct node{
    int id;
    int neng;
}p[N];
struct {
    int next;
    int to;
}g[N<<1];
int q[N];int ans[N];
int n,tree[N];
int head[N],ent=1;
void update(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int chaxun(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void addedge(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
bool bijiao(node n1,node n2){
    return n1.neng>n2.neng;
}
void dfs(int s,int fa){
    int i,v;
    ans[s]=-chaxun(q[s]-1);
    update(q[s],1);
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v!=fa){
            dfs(v,s);
        }
    }
    ans[s]+=chaxun(q[s]-1);
}
int main(){
    int d,i,a;
    scanf("%d",&d);
    for(i=1;i<=d;i++){
        scanf("%d",&p[i].neng);
        p[i].id=i;
    }
    for(i=2;i<=d;i++){
        scanf("%d",&a);
        addedge(i,a);
        addedge(a,i);
    }
    std::sort(p+1,p+d+1,bijiao);
    for(i=1;i<=d;i++){
        q[p[i].id]=i;
    }
    n = d;
    dfs(1,-1);
    for(i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}