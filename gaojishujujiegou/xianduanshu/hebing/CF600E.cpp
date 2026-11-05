#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int N=100003;
struct {
    int l;
    int r;
    int num;
    ll sum;
}tree[N<<5];
int gen[N];
int ent,n;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent_;
ll col[N];ll ans[N];
void adde(int u,int v){
    ent_++;
    g[ent_].to=v;
    g[ent_].next=head[u];
    head[u]=ent_;
}
void push_up(int p){
    if(tree[tree[p].l].num>tree[tree[p].r].num){
        tree[p].num=tree[tree[p].l].num;
        tree[p].sum=tree[tree[p].l].sum;
    }
    else if(tree[tree[p].l].num<tree[tree[p].r].num){
        tree[p].num=tree[tree[p].r].num;
        tree[p].sum=tree[tree[p].r].sum;
    }
    else{
        tree[p].num=tree[tree[p].l].num;
        tree[p].sum=tree[tree[p].l].sum+tree[tree[p].r].sum;
    }
}
int newnode(int s){
    ent++;
    tree[ent].l=tree[ent].r=0;
    tree[ent].num=1;
    tree[ent].sum=col[s];
    return ent;
}
int newtree(int s,int pl,int pr){
    if(pl==pr){
        return newnode(s);
    }
    int mid=(pl+pr)>>1;
    int p=newnode(s);
    if(col[s]<=mid){tree[p].l=newtree(s,pl,mid);}
    if(col[s]>mid){tree[p].r=newtree(s,mid+1,pr);}
    return p;
}
int hebing(int p1,int p2,int pl,int pr){
    if(p1==0 || p2==0){
        return p1+p2;
    }
    if(pl==pr){
        tree[p1].num+=tree[p2].num;
        return p1;
    }
    int mid=(pl+pr)>>1;
    tree[p1].l=hebing(tree[p1].l,tree[p2].l,pl,mid);
    tree[p1].r=hebing(tree[p1].r,tree[p2].r,mid+1,pr);
    push_up(p1);
    return p1;
}
void dfs(int s,int f){
    int v,i;
    gen[s]=newtree(s,1,n);
    for(i = head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=f){
            dfs(v,s);
            gen[s]=hebing(gen[s],gen[v],1,n);
        }
    }
    ans[s]=tree[gen[s]].sum;
}
int main(){
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&col[i]);
    }
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    for(i=1;i<=n;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}