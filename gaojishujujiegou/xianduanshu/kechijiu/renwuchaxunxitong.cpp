#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
int num[N<<6];
ll sum[N<<6];
int ls[N<<6],rs[N<<6];
struct node{
    int l,r;
    ll val;
}p[N];
bool bijiao(node & n1,node & n2){
    return n1.val<n2.val;
}
int root[N];
int add1[N<<1];
ll add2[N<<1];
int head[N],nex[N<<1],ent;
void push_up(int p){
    num[p]=num[ls[p]]+num[rs[p]];
    sum[p]=sum[ls[p]]+sum[rs[p]];
}
void adde(int u,int v,ll d){
    ent++;
    nex[ent]=head[u];
    add1[ent]=v;
    add2[ent]=d;
    head[u]=ent;
}
void addtree(int last,int & now,int pl,int pr,int id,ll v){
    now=++ent;
    if(pl==pr){num[now]=v>0?1:0;sum[now]=v>0?v:0;return;}
    int mid=(pl+pr)>>1;
    if(id<=mid){
        rs[now]=rs[last];
        addtree(ls[last],ls[now],pl,mid,id,v);
    }
    else{
        ls[now]=ls[last];
        addtree(rs[last],rs[now],mid+1,pr,id,v);
    }
    push_up(now);
}
ll chaxun(int p,int k){
    if(num[p]<=k){return sum[p];}
    if(k<=num[ls[p]]){return chaxun(ls[p],k);}
    else{
        return sum[ls[p]]+chaxun(rs[p],k-num[ls[p]]);
    }
}
int main(){
    int n,m,i,j,la;
    ll pre=1,a,b,c;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        scanf("%d %d %lld",&p[i].l,&p[i].r,&p[i].val);
    }
    sort(p,p+m,bijiao);
    for(i=0;i<m;i++){
        adde(p[i].l,i+1,p[i].val);
        adde(p[i].r+1,i+1,-p[i].val);
    }
    ent=0;
    for(i=1;i<=n;i++){
        la = root[i-1];
        for(j=head[i];j;j=nex[j]){
            addtree(la,root[i],1,m,add1[j],add2[j]);
            la = root[i];
        }
        root[i]=la;
    }
    while(n--){
        scanf("%d %lld %lld %lld",&i,&a,&b,&c);
        pre = chaxun(root[i],(a*(pre%c)+b)%c+1);
        printf("%lld\n",pre);
    }
    return 0;
}