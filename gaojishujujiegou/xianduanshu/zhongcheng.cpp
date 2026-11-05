#include<cstdio>
#include<iostream>
#define ll long long
const int N=100002;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
ll tree[N<<2];
ll q[N];
void build(int p,int pl,int pr){
    if(pl==pr){tree[p]=q[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    tree[p]=std::min(tree[ls(p)],tree[rs(p)]);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;ll ans=0x3f3f3f3f3f3f3f3f;
    if(l<=mid){ans=std::min(ans,chaxun(ls(p),pl,mid,l,r));}
    if(r>mid){ans=std::min(ans,chaxun(rs(p),mid+1,pr,l,r));}
    return ans;
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&q[i]);
    }
    build(1,1,n);
    while(m){
        scanf("%d %d",&a,&b);
        printf("%lld ",chaxun(1,1,n,a,b));
        m--;
    }
    return 0;
}