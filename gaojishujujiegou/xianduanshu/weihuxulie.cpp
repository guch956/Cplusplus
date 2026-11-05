#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
ll P;
ll sum[N<<2],tag1[N<<2],tag2[N<<2];/*先乘后加*/
ll A[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int x){
    sum[x]=(sum[ls(x)]+sum[rs(x)])%P;
}
void addtag1(int p,ll d){
    sum[p]=sum[p]*d%P;
    tag2[p]=tag2[p]*d%P;
    tag1[p]=tag1[p]*d%P;
}
void addtag2(int p,ll len,ll d){
    sum[p]=(sum[p]+len*d)%P;
    tag2[p]=(tag2[p]+d)%P;
}
void push_down(int p,ll len){
    addtag1(ls(p),tag1[p]);
    addtag1(rs(p),tag1[p]);
    tag1[p]=1;
    addtag2(ls(p),(len+1)>>1,tag2[p]);
    addtag2(rs(p),len>>1,tag2[p]);
    tag2[p]=0;
}
void update(int p,int pl,int pr,int l,int r,ll d,int k){
    if(l<=pl && r>=pr){
        if(k==1){addtag1(p,d);}
        else{addtag2(p,pr-pl+1,d);}
        return ;
    }
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){update(ls(p),pl,mid,l,r,d,k);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d,k);}
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return sum[p];}
    int mid=(pl+pr)>>1;
    ll ans=0;
    push_down(p,pr-pl+1);
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans%P;
}
void build(int p,int pl,int pr){
    tag1[p]=1;
    if(pl==pr){
        sum[p]=A[pl];return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
int main(){
    int n,q,i,a,b;
    ll d;
    scanf("%d %lld",&n,&P);
    for(i=1;i<=n;i++){scanf("%lld",&A[i]);}
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&i);
        if(i==3){
            scanf("%d %d",&a,&b);
            printf("%lld\n",chaxun(1,1,n,a,b));
        }
        else{
            scanf("%d %d %lld",&a,&b,&d);
            update(1,1,n,a,b,d,i);
        }
    }
    return 0;
}