#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
const int N=4000005;const ll INF=0x3f3f3f3f3f3f3f3f;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
ll tree[N];
ll tag1[N];
ll tag2[N];
ll q[N];
void push_up(int p){
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void addtag1(int p,ll x){
    tag1[p]=x;
    tree[p]=x;
    tag2[p]=0;
}
void addtag2(int p,ll x){
    tag2[p]+=x;
    tree[p]+=x;
}
void push_down(int p){
    if(tag1[p]!=-INF){
        addtag1(ls(p),tag1[p]);
        addtag1(rs(p),tag1[p]);
        tag1[p]=-INF;
    }
    addtag2(ls(p),tag2[p]);
    addtag2(rs(p),tag2[p]);
    tag2[p]=0;
}
void build(int p,int pl,int pr){
    tag1[p]=-INF;
    tag2[p]=0;
    if(pl==pr){tree[p]=q[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update1(int p,int pl,int pr,int l,int r,ll x){
    if(l<=pl && r>=pr){addtag1(p,x);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid)update1(ls(p),pl,mid,l,r,x);
    if(r>mid)update1(rs(p),mid+1,pr,l,r,x);
    push_up(p);
}
void update2(int p,int pl,int pr,int l,int r,ll x){
    if(l<=pl && r>=pr){addtag2(p,x);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid)update2(ls(p),pl,mid,l,r,x);
    if(r>mid)update2(rs(p),mid+1,pr,l,r,x);
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;ll ans=-INF;
    push_down(p);
    if(l<=mid){ans=max(ans,chaxun(ls(p),pl,mid,l,r));}
    if(r>mid){ans=max(ans,chaxun(rs(p),mid+1,pr,l,r));}
    return ans;
}
int main(){
    int n,m,a,b,k,i;
    ll d;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        scanf("%lld",&q[i]);
    }
    build(1,1,n);
    for(i=1;i<=m;i++){
        scanf("%d",&k);
        switch (k)
        {
        case 1:
            scanf("%d %d %lld",&a,&b,&d);
            update1(1,1,n,a,b,d);
            break;
        case 2:
            scanf("%d %d %lld",&a,&b,&d);
            update2(1,1,n,a,b,d);
            break;
        case 3:
            scanf("%d %d",&a,&b);
            printf("%lld\n",chaxun(1,1,n,a,b));
            break;
        }
    }
    return 0;
}