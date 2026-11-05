#include<iostream>
#include<cstdio>
#include<utility>
#define ll long long
using namespace std;
const int N=400003;
const ll P=1e9+7;
struct {
    ll tag;
    ll pi;
    ll sushu;
    ll fugai;
}t[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
ll A[N];
ll sushu[N];
ll pri[65];
ll ni[65],ent;
ll pi[320];
ll quick(ll a,int b){
    ll an=1;
    while(b){
        if(b&1)an = an*a%P;
        a = a*a%P;
        b = b>>1;
    }
    return an;
}
void init(){
    int i,j,k;
    for(i=2;i<=300;i++){
        if(!pi[i]){pri[ent++]=i;}
        for(j=0;j<ent;j++){
            k = pri[j]*i;
            if(k>300)break;
            pi[k]=pri[j];
            if(i%pri[j]==0)break;
        }
    }
    for(i=0;i<ent;i++){
        ni[i]=quick(pri[i],P-2);
    }
}
inline void push_up(int p){
    t[p].sushu=t[ls(p)].sushu|t[rs(p)].sushu;
    t[p].pi=t[ls(p)].pi*t[rs(p)].pi%P;
}
void addtag(int p,ll x,ll s,int l){
    t[p].sushu=t[p].sushu|s;
    t[p].fugai=t[p].fugai|s;
    t[p].pi=t[p].pi*quick(x,l)%P;
    t[p].tag=t[p].tag*x%P;
}
void push_down(int p,int l){
    addtag(ls(p),t[p].tag,t[p].fugai,(l+1)>>1);
    addtag(rs(p),t[p].tag,t[p].fugai,l>>1);
    t[p].tag=1;
    t[p].fugai=0;
}
void build(int p,int pl,int pr){
    t[p].tag=1;
    t[p].fugai=0;
    if(pl==pr){
        int i;
        ll c=0;
        for(i=0;i<ent;i++){
            if(A[pl]%pri[i]==0){c+=(ll)1<<i;}
        }
        t[p].pi=A[pl];
        t[p].sushu=c;
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r,ll x,ll s){
    if(l<=pl && r>=pr){
        addtag(p,x,s,pr-pl+1);
        return ;
    }
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid)update(ls(p),pl,mid,l,r,x,s);
    if(r>mid)update(rs(p),mid+1,pr,l,r,x,s);
    push_up(p);
}
pair<ll,ll> chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){
        return make_pair(t[p].pi,t[p].sushu);
    }
    int mid=(pl+pr)>>1;
    pair<ll,ll> ans,a;
    ans.first=1;ans.second=0;
    push_down(p,pr-pl+1);
    if(l<=mid){
        a = chaxun(ls(p),pl,mid,l,r);
        ans.first=ans.first*a.first%P;
        ans.second=ans.second|a.second;
    }
    if(r>mid){
        a = chaxun(rs(p),mid+1,pr,l,r);
        ans.first=ans.first*a.first%P;
        ans.second=ans.second|a.second;
    }
    return ans;
}
int main(){
    int n,q,i,l,r;
    char s[10];
    pair<ll,ll> ans;
    ll c,d;
    scanf("%d %d",&n,&q);
    init();
    for(i=1;i<=n;i++)scanf("%lld",&A[i]);
    build(1,1,n);
    while(q--){
        scanf("%s",s);
        if(s[0]=='T'){
            scanf("%d %d",&l,&r);
            ans = chaxun(1,1,n,l,r);
            for(i=0;i<ent;i++){
                if(ans.second&((ll)1<<i)){
                    ans.first=ans.first*ni[i]%P*(pri[i]-1)%P;
                }
            }
            printf("%lld\n",ans.first);
        }
        else{
            scanf("%d %d %lld",&l,&r,&c);
            d = 0;
            for(i=0;i<ent;i++){
                if(c%pri[i]==0){d+=((ll)1<<i);}
            }
            update(1,1,n,l,r,c,d);
        }
    }
    return 0;
}