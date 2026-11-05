#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
const int N=100002;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
ll tree[N<<2];
ll q[N];
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
}
void build(int p,int pl,int pr){
    if(pl==pr){tree[p]=q[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r){
    if(tree[p]==pr-pl+1){return ;}
    if(pl==pr){
        tree[p]=sqrt(tree[p]);
        return ;
    }
    int mid=(pl+pr)>>1;
    if(l<=mid){update(ls(p),pl,mid,l,r);}
    if(r>mid){update(rs(p),mid+1,pr,l,r);}
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;ll ans=0;
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans;
}
int main(){
    int n,m,k,i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&q[i]);
    }
    scanf("%d",&m);
    build(1,1,n);
    while(m){
        scanf("%d %d %d",&k,&a,&b);
        if(a>b){std::swap(a,b);}
        if(k==0){
            update(1,1,n,a,b);
        }
        else{
            printf("%lld\n",chaxun(1,1,n,a,b));
        }
        m--;
    }
    return 0;
}
