#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll P=1000000007;
const int N=100003;
struct node{
    ll a;
    ll b;
    int xiabiao;
}p[N];
ll mi2[N];
ll ans;
ll kuansu(ll x,ll a){
    ll an=1;
    while(x){
        if(x&1){an = (an*a)%P;}
        a = (a*a)%P;
        x = x>>1;
    }
    return an;
}
bool bijiao1(node & n1,node & n2){
    return n1.a<n2.a;
}
bool bijiao2(node & n1,node & n2){
    return n1.b<n2.b;
}
ll sum1[N<<2];
int tag[N<<2];
int geshu[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline void push_up(int p){
    sum1[p] = (sum1[ls(p)]+sum1[rs(p)])%P;
    geshu[p] = geshu[ls(p)]+geshu[rs(p)];
}
inline void addtag(int p,int d){
    tag[p]+=d;
    sum1[p] = (mi2[d]*sum1[p])%P;
}
inline void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
int chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return geshu[p];}
    int mid=(pl+pr)>>1,ans=0;
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans;
}
void update1(int p,int pl,int pr,ll x,int d,int xb){
    if(pl==pr){
        sum1[p] = (mi2[xb]*x)%P;
        geshu[p]=1;
        return ;
    }
    int mid=(pl+pr)>>1;
    push_down(p);
    if(d<=mid){update1(ls(p),pl,mid,x,d,xb);}
    else{update1(rs(p),mid+1,pr,x,d,xb);}
    push_up(p);
}
ll update2(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){
        addtag(p,1);
        return sum1[p];
    }
    int mid=(pl+pr)>>1;
    ll ans=0;
    push_down(p);
    if(l<=mid){ans+=update2(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=update2(rs(p),mid+1,pr,l,r);}
    push_up(p);
    return ans;
}
int main(){
    int n,nmax=0,i,c;
    ll s,ni2;
    mi2[0]=1;
    ni2 = (P+1)>>1;
    while(cin>>n){
        for(i=nmax+1;i<=n;i++){
            mi2[i] = (mi2[i-1]<<1)%P;
        }
        ans = 0;
        nmax = max(n,nmax);
        memset(sum1,0,sizeof(sum1));
        memset(geshu,0,sizeof(geshu));
        memset(tag,0,sizeof(tag));
        for(i=0;i<n;i++){
            scanf("%lld %lld",&p[i].a,&p[i].b);
        }
        sort(p,p+n,bijiao2);
        for(i=0;i<n;i++){
            p[i].xiabiao=i+1;
            p[i].b = kuansu(p[i].b,3);
        }
        sort(p,p+n,bijiao1);
        for(i=0;i<n;i++){
            p[i].a = kuansu(p[i].a,2);
            c = chaxun(1,1,n,1,p[i].xiabiao);
            update1(1,1,n,p[i].b,p[i].xiabiao,c);
            if(p[i].xiabiao!=n){
                s = update2(1,1,n,p[i].xiabiao+1,n);
                ans = (ans+ p[i].a*(((s*ni2)%P)))%P;
            }
            ans = (ans+ ((p[i].a*mi2[c])%P)*p[i].b)%P;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
