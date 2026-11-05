#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll tsum[N<<2],tmin[N<<2],tag[N<<2];
ll A[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tsum[p]=tsum[ls(p)]+tsum[rs(p)];
    tmin[p]=min(tmin[ls(p)],tmin[rs(p)]);
}
void addtag(int p,ll len,ll d){
    tag[p]+=d;
    tsum[p]+=len*d;
    tmin[p]+=d;
}
void push_down(int p,ll len){
    addtag(ls(p),(len+1)>>1,tag[p]);
    addtag(rs(p),len>>1,tag[p]);
    tag[p]=0;
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tsum[p]=tmin[p]=A[pl];
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
ll chaxun1(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tmin[p];}
    int mid=(pl+pr)>>1;
    ll ans=INF;
    push_down(p,pr-pl+1);
    if(l<=mid){ans=min(ans,chaxun1(ls(p),pl,mid,l,r));}
    if(r>mid){ans=min(ans,chaxun1(rs(p),mid+1,pr,l,r));}
    return ans;
}
ll chaxun2(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tsum[p];}
    int mid=(pl+pr)>>1;
    ll ans=0;
    push_down(p,pr-pl+1);
    if(l<=mid){ans+=chaxun2(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun2(rs(p),mid+1,pr,l,r);}
    return ans;
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag(p,pr-pl+1,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
int main(){
    int n,q,i,a,b;
    ll d;
    char c;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%lld",&A[i]);
    }
    build(1,1,n);
    while(q--){
        cin>>c;
        if(c=='M'){
            scanf("%d %d",&a,&b);
            printf("%lld\n",chaxun1(1,1,n,a,b));
        }
        else if(c=='P'){
            scanf("%d %d %lld",&a,&b,&d);
            update(1,1,n,a,b,d);
        }
        else{
            scanf("%d %d",&a,&b);
            printf("%lld\n",chaxun2(1,1,n,a,b));
        }
    }
    return 0;
}