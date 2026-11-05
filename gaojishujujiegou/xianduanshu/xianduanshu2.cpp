#include<iostream>
#include<cstdio>
#define ll long long
const int N=100002;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
ll tree[N<<2];
ll q[N];
ll tag1[N<<2],tag2[N<<2];
ll m;
void push_up(int p){
    tree[p]=(tree[ls(p)]+tree[rs(p)])%m;
}
void build(int p,int pl,int pr){
    tag1[p]=1;tag2[p]=0;
    if(pl==pr){
        tree[p]=q[pl];
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void addtag1(int p,ll d){
    tag1[p] = (tag1[p]*d)%m;
    tree[p]= (tree[p]*d)%m;
    tag2[p]= (tag2[p]*d)%m;
}
void addtag2(int p,int len,ll d){
    tag2[p]= (tag2[p]+d)%m;
    tree[p]= (tree[p]+len*d)%m;
}
void push_down(int p,int pl,int pr){
    int mid=(pl+pr)>>1;
    addtag1(ls(p),tag1[p]);
    addtag1(rs(p),tag1[p]);
    addtag2(ls(p),mid-pl+1,tag2[p]);
    addtag2(rs(p),pr-mid,tag2[p]);
    tag1[p]=1;
    tag2[p]=0;
}
void update1(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag1(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pl,pr);
    if(l<=mid){update1(ls(p),pl,mid,l,r,d);}
    if(r>mid){update1(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
void update2(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag2(p,pr-pl+1,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pl,pr);
    if(l<=mid){update2(ls(p),pl,mid,l,r,d);}
    if(r>mid){update2(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;ll ans=0;
    push_down(p,pl,pr);
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans%m;
}
int main(){
    int n,c,a,b,k;
    ll d;
    scanf("%d %d %lld",&n,&c,&m);
    for(k=1;k<=n;k++){
        scanf("%lld",&q[k]);
    }
    build(1,1,n);
    while(c){
        scanf("%d",&k);
        if(k==1){
            scanf("%d %d %lld",&a,&b,&d);
            update1(1,1,n,a,b,d);
        }
        else if(k==2){
            scanf("%d %d %lld",&a,&b,&d);
            update2(1,1,n,a,b,d);
        }
        else{
            scanf("%d %d",&a,&b);
            printf("%lld\n",chaxun(1,1,n,a,b));
        }
        c--;
    }
    return 0;
}
