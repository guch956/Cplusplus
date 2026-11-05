#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;const int INF=0x3f3f3f3f;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
struct node{
    int dmin;
    int dmax;
    int ziduan;
}tree[N<<2];
int q[N];int r[N];
int tag[N<<2];
void push_up(int p){
    tree[p].dmax=max(tree[ls(p)].dmax,tree[rs(p)].dmax);
    tree[p].dmin=min(tree[ls(p)].dmin,tree[rs(p)].dmin);
    tree[p].ziduan=max(tree[ls(p)].ziduan,tree[rs(p)].ziduan);
    tree[p].ziduan=max(tree[p].ziduan,tree[rs(p)].dmax-tree[ls(p)].dmin);
}
void addtag(int p,int d){
    tree[p].dmax+=d;
    tree[p].dmin+=d;
    tag[p]+=d;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p].dmax=q[pl];
        tree[p].dmin=q[pl];
        tree[p].ziduan=-INF;
        return;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
void max1(node & n1,node n2){
    n1.dmax=max(n1.dmax,n2.dmax);
    n1.dmin=min(n1.dmin,n2.dmin);
    n1.ziduan=max(n1.ziduan,n2.ziduan);
}
node chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;node ans,a;int b,c;
    push_down(p);
    ans.ziduan=-INF;ans.dmax=-INF;ans.dmin=INF;
    if(r<=mid){return chaxun(ls(p),pl,mid,l,r);}
    if(l>mid){return chaxun(rs(p),mid+1,pr,l,r);}
    a = chaxun(ls(p),pl,mid,l,r);
    b = a.dmin;
    max1(ans,a);
    a = chaxun(rs(p),mid+1,pr,l,r);
    c = a.dmax;
    max1(ans,a);
    ans.ziduan=max(ans.ziduan,c-b);
    return ans;
}
int main(){
    int n,m,i,a,b;node x;
    scanf("%d %d",&n,&m);
    n++;
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        q[i]=q[i-1]+a;
        r[i]=a;
    }
    build(1,1,n);
    while(m--){
        scanf("%d",&i);
        if(i==1){
            scanf("%d %d",&a,&b);
            if(a>b){swap(a,b);}
            x = chaxun(1,1,n,a,b+1);
            printf("%d\n",x.ziduan);
        }
        else{
            scanf("%d %d",&a,&b);
            a++;
            update(1,1,n,a,n,b-r[a]);
            r[a]=b;
        }
    }
    return 0;
}