#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
int tree[N<<2],tag[N<<2];
int A[N];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
void push_up(int p){tree[p]=min(tree[ls(p)],tree[rs(p)]);}
void addtag(int p,int d){
    tag[p]+=d;
    tree[p]+=d;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
int chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1,ans=0x3f3f3f3f;
    push_down(p);
    if(l<=mid){ans=min(ans,chaxun(ls(p),pl,mid,l,r));}
    if(r>mid){ans=min(ans,chaxun(rs(p),mid+1,pr,l,r));}
    return ans;
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
void build(int p,int pl,int pr){
    if(pl==pr){tree[p]=A[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
int main(){
    int n,q,i,a,b,d;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    build(1,1,n);
    for(i=1;i<=q;i++){
        scanf("%d %d %d",&d,&a,&b);
        if(chaxun(1,1,n,a,b)<d){
            printf("-1\n%d",i);
            break;
        }
        else{
            update(1,1,n,a,b,-d);
        }
    }
    if(i==q+1){printf("0");}
    return 0;
}