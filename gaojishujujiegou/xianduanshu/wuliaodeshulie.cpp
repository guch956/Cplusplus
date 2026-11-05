#include<iostream>
#include<cstdio>
const int N=100002;
#define ll long long
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
ll tree[N<<2],tag[N<<2];ll w[N<<2];
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
}
void addtag(int p,ll len,ll d){
    tag[p]+=d;
    tree[p]+=d*len;
}
void push_down(int p,ll len){
    addtag(ls(p),(len+1)>>1,tag[p]);
    addtag(rs(p),len>>1,tag[p]);
    tag[p]=0;
}
void build(int p,int pl,int pr){
    if(pl==pr){tree[p]=w[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag(p,pr-pl+1,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;ll ans=0;
    push_down(p,pr-pl+1);
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans;
}
int main(){
    int n,m,i,e,c,k;
    ll d,b=0,a;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a);
        w[i]=a-b;
        b = a;
    }
    build(1,1,n);
    while(m){
        scanf("%d",&k);
        if(k==1){
            scanf("%d %d %lld %lld",&e,&c,&a,&d);
            update(1,1,n,e,e,a);
            if(e<c){
                update(1,1,n,e+1,c,d);
            }
            if(c<n){
                update(1,1,n,c+1,c+1,-a-(c-e)*d);
            }
        }
        else{
            scanf("%d",&c);
            printf("%lld\n",chaxun(1,1,n,1,c));
        }
        m--;
    }
    return 0;
}