#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long
const int N=90000,M=10002;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct qujian{
    int l;
    int r;
    ll w;
}p[M];
bool bijiao(qujian q1,qujian q2){
    return q1.l<q2.l;
}
ll tree[N<<2],tag[N<<2];
ll dp[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p]=min(tree[ls(p)],tree[rs(p)]);
}
void build(){
    for(int i=1;i<(N<<2);i++){
        tree[i]=tag[i]=INF;
    }
}
void addtag(int p,ll x){
    if(x<tag[p]){
        tree[p]=min(tree[p],x);
        tag[p]=x;
    }
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=INF;
}
ll chaxun(int p,int pl,int pr,int x){
    if(pl==pr){return tree[p];}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(x<=mid){return chaxun(ls(p),pl,mid,x);}
    else{return chaxun(rs(p),mid+1,pr,x);}
}
void update(int p,int pl,int pr,int l,int r,ll x){
    if(l<=pl && r>=pr){addtag(p,x);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,x);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,x);}
    push_up(p);
}
int main(){
    int m,i,tl,tr,j,k;
    scanf("%d %d %d",&m,&tl,&tr);
    tl++;
    tr++;
    for(i=0;i<m;i++){
        scanf("%d %d %lld",&p[i].l,&p[i].r,&p[i].w);
        p[i].l++;
        p[i].r++;
    }
    build();
    sort(p,p+m,bijiao);
    j = 0;
    for(i=tl;i<=tr;i++){
        for(k=j;p[k].l==i;k++){
            update(1,1,tr,i,p[k].r,dp[i-1]+p[k].w);
        }
        j = k;
        dp[i]=chaxun(1,1,tr,i);
    }
    if(dp[tr]==INF){
        cout<<-1;
    }
    else{
        cout<<dp[tr];
    }
    return 0;
}