#include<cstdio>
#include<iostream>
using namespace std;
const int N=200002;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
struct node{
    int pre;
    int suf;
    int ma;
};
node tree[N<<2];
int q[N];
void push_up(int p,int pl,int pr){
    int mid=(pl+pr)>>1;
    tree[p].ma=max(tree[ls(p)].ma,tree[rs(p)].ma);
    if(q[mid]==q[mid+1]){
        tree[p].pre=tree[ls(p)].pre;
        tree[p].suf=tree[rs(p)].suf;
    }
    else{
        tree[p].pre=tree[ls(p)].pre==mid-pl+1?tree[rs(p)].pre:0;
        tree[p].pre+=tree[ls(p)].pre;
        tree[p].suf=tree[rs(p)].suf==pr-mid?tree[ls(p)].suf:0;
        tree[p].suf+=tree[rs(p)].suf;
        tree[p].ma=max(tree[p].ma,tree[ls(p)].suf+tree[rs(p)].pre);
    }
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p].pre=1;
        tree[p].suf=1;
        tree[p].ma=1;
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p,pl,pr);
}
void update(int p,int pl,int pr,int x){
    if(pl==pr){return ;}
    int mid=(pl+pr)>>1;
    if(x<=mid){update(ls(p),pl,mid,x);}
    if(x>mid){update(rs(p),mid+1,pr,x);}
    push_up(p,pl,pr);
}
int main(){
    int n,m,y;
    scanf("%d %d",&n,&m);
    build(1,1,n);
    while(m){
        scanf("%d",&y);
        q[y]=1-q[y];
        update(1,1,n,y);
        printf("%d\n",tree[1].ma);
        m--;
    }
    return 0;
}