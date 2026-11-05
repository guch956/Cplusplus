#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=300003;
const ll INF=0x3f3f3f3f3f3f3f3f;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline int lowbit(int x){return x&(-x);}
ll A[N];
ll tmi[N<<2];
ll sum[N];
ll tag[N<<2];
int n;
inline void push_up(int p){
    tmi[p]=min(tmi[ls(p)],tmi[rs(p)]);
}
void addtag(int p,ll d){
    tag[p]+=d;
    tmi[p]+=d;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
void build(int p,int pl,int pr){
    if(pl==pr){tmi[p]=A[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update1(int x){
    while(x<=n){
        sum[x]++;
        x+=lowbit(x);
    }
}
ll chaxun1(int x){
    ll ans=0;
    while(x){
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
ll chuli(int p,int pl,int pr,ll d){
    if(pl==pr){
        ll a=tmi[p];
        tmi[p]=INF;
        update1(pl);
        return a;
    }
    int mid=(pl+pr)>>1;
    ll ans=0;
    push_down(p);
    if(tmi[ls(p)]<d){ans+=chuli(ls(p),pl,mid,d);}
    else{addtag(ls(p),-d);}
    if(tmi[rs(p)]<d){ans+=chuli(rs(p),mid+1,pr,d);}
    else{addtag(rs(p),-d);}
    push_up(p);
    return ans;
}
ll update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){
        if(tmi[p]>=d){addtag(p,-d);return 0;}
        else{return chuli(p,pl,pr,d);}
    }
    int mid=(pl+pr)>>1;
    ll ans=0;
    push_down(p);
    if(l<=mid){ans+=update(ls(p),pl,mid,l,r,d);}
    if(r>mid){ans+=update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
    return ans;
}
int main(){
    int i,q;
    ll ans,l,r,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){scanf("%lld",&A[i]);}
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%lld %lld %lld",&l,&r,&k);
        ans = update(1,1,n,l,r,k);
        l--;
        ans+=k*(r-l-chaxun1(r)+chaxun1(l));
        printf("%lld\n",ans);
    }
    return 0;
}