#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int N=100002;
struct {
    ll ma;
    ll sum;
} tree[N<<2];
ll q[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p].ma=max(tree[ls(p)].ma,tree[rs(p)].ma);
    tree[p].sum=tree[ls(p)].sum+tree[rs(p)].sum;
}
void build(int p,int pl,int pr){
    if(pl==pr){tree[p].ma=tree[p].sum=q[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    ll ans=0;int mid=(pl+pr)>>1;
    if(l<=pl && r>=pr){return tree[p].sum;}
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans;
}
void update2(int p,int pl,int pr,int l,int r,ll x){
    int mid=(pl+pr)>>1;
    if(tree[p].ma<x){return ;}
    if(pl==pr){tree[p].ma=tree[p].sum=tree[p].sum%x;return ;}
    if(l<=mid){update2(ls(p),pl,mid,l,r,x);}
    if(r>mid){update2(rs(p),mid+1,pr,l,r,x);}
    push_up(p);
}
void update3(int p,int pl,int pr,int d,ll x){
    int mid=(pl+pr)>>1;
    if(pl==pr){tree[p].ma=tree[p].sum=x;return ;}
    if(d<=mid){update3(ls(p),pl,mid,d,x);}
    else{update3(rs(p),mid+1,pr,d,x);}
    push_up(p);
}
int main(){
    int n,m,i,k,a,b;
    ll d;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&q[i]);
    }
    build(1,1,n);
    while(m){
        scanf("%d",&k);
        if(k==2){
            scanf("%d %d %lld",&a,&b,&d);
            update2(1,1,n,a,b,d);
        }
        else if(k==3){
            scanf("%d %lld",&a,&d);
            update3(1,1,n,a,d);
        }
        else{
            scanf("%d %d",&a,&b);
            printf("%lld\n",chaxun(1,1,n,a,b));
        }
        m--;
    }
    return 0;
}