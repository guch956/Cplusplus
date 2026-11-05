#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
ll sum[N<<6];
ll jiage[N<<6];
int ls[N<<6],rs[N<<6];
struct node{
    int meiwei;
    ll danjia;
    ll zuida;
}p[N];
int daxiao[N];
int root[N];
int cnt[N],ent;
bool bijiao(node & n1,node & n2){
    return n1.meiwei>n2.meiwei;
}
void push_up(int p){
    sum[p]=sum[ls[p]]+sum[rs[p]];
    jiage[p]=jiage[ls[p]]+jiage[rs[p]];
}
void build(int last,int & now,int pl,int pr,int id,ll z,ll j){
    now=++ent;
    if(pl==pr){sum[now]=z;jiage[now]=j;return;}
    int mid=(pl+pr)>>1;
    if(id<=mid){
        rs[now]=rs[last];
        build(ls[last],ls[now],pl,mid,id,z,j);
    }
    else{
        ls[now]=ls[last];
        build(rs[last],rs[now],mid+1,pr,id,z,j);
    }
    push_up(now);
}
ll chaxun(ll v,int r,int pl,int pr){
    if(pl==pr){return jiage[r]/sum[r]*v;}
    int mid=(pl+pr)>>1;
    if(v<=sum[ls[r]]){return chaxun(v,ls[r],pl,mid);
    }
    else{
        return jiage[ls[r]]+chaxun(v-sum[ls[r]],rs[r],mid+1,pr);
    }
}
int main(){
    int n,q,i,l,r,mid;
    ll g,L;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d %lld %lld",&p[i].meiwei,&p[i].danjia,&p[i].zuida);
        cnt[p[i].danjia]++;
    }
    sort(p+1,p+n+1,bijiao);
    for(i=1;i<=100000;i++){cnt[i]=cnt[i]+cnt[i-1];}
    for(i=1;i<=n;i++){
        daxiao[i]=cnt[p[i].danjia]--;
    }
    for(i=1;i<=n;i++){
        build(root[i-1],root[i],1,n,daxiao[i],p[i].zuida,p[i].zuida*p[i].danjia);
        p[i].zuida+=p[i-1].zuida;
    }
    while(q--){
        scanf("%lld %lld",&g,&L);
        l = 1;r = n+1;
        while(l<r){
            mid=(l+r)>>1;
            if(p[mid].zuida<L){l = mid+1;continue;}
            if(chaxun(L,root[mid],1,n)<=g){r = mid;}
            else{l = mid+1;}
        }
        if(r==n+1){printf("-1\n");}
        else{printf("%d\n",p[r].meiwei);}
    }
    return 0;
}

