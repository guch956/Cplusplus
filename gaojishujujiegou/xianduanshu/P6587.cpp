#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1<<21;
const int D=20;
ll sum[N];
ll A[N];
ll tag[N];
ll num[N];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void push_up(int p){sum[p]=sum[ls(p)]+sum[rs(p)];}
void addtag(int p,ll v){
    sum[p]+=num[p]*v;
    tag[p]+=v;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
void build(int p,ll n,int dep,int x){
    num[p]=n;
    if(dep==D){sum[p]=A[x];return ;}
    build(ls(p),(n+1)>>1,dep+1,x);
    build(rs(p),n>>1,dep+1,x+(1<<dep));
    push_up(p);
}
ll chaxun(int p,int dep,int x){
    if(dep==0)return sum[p];
    push_down(p);
    if(x&1)return chaxun(ls(p),dep-1,(x+1)>>1);
    else return chaxun(rs(p),dep-1,(x+1)>>1);
}
void update(int p,int dep,int x,ll d){
    if(dep==0){addtag(p,d);return ;}
    push_down(p);
    if(x&1)update(ls(p),dep-1,(x+1)>>1,d);
    else update(rs(p),dep-1,(x+1)>>1,d);
    push_up(p);
}
int main(){
    int n,q,i,op,x,y;
    ll c,lastans=0;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%lld",&A[i]);
    }
    build(1,n,0,0);
    while(q--){
        scanf("%d",&op);
        op = (lastans+op)%2+1;
        if(op==2){
            scanf("%d %d",&x,&y);
            lastans = chaxun(1,x,y);
            printf("%lld\n",lastans);
        }
        else{
            scanf("%d %d %lld",&x,&y,&c);
            update(1,x,y,c);
        }
    }
    return 0;
}