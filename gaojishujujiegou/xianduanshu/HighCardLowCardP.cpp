#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=50003;
const int INF=0x3f3f3f3f;
int tree[N<<3];
int tag[N<<3];
int p[N];
int q[N];
int cnt[N<<1];
int tre[N<<1];
int n;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline int lowbit(int x){return x&(-x);}
int chaxun(int x){
    int a=0;
    while(x){
        a+=tre[x];
        x-=lowbit(x);
    }
    return a;
}
void xiugai(int x,int d){
    while(x<=2*n){
        tre[x]+=d;
        x+=lowbit(x);
    }
}
void push_up(int p){
    tree[p]=min(tree[ls(p)],tree[rs(p)]);
}
void addtag(int p,int d){
    tree[p]+=d;
    tag[p]+=d;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
void update1(int p,int pl,int pr,int x,int d){
    if(pl==pr){tree[p]=d;return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(x<=mid){update1(ls(p),pl,mid,x,d);}
    else{update1(rs(p),mid+1,pr,x,d);}
    push_up(p);
}
int main(){
    int i,a,b,ma=0,l,r,mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&q[i]);
        cnt[q[i]]++;
    }
    a = 1;
    for(i=2*n;i>=1;i--){
        if(cnt[i]==0){
            p[a]=i;
            a++;
        }
    }
    memset(tree,INF,sizeof(tree));
    for(i=n;i>=1;i--){
        l=i;r=n+1;
        while(l<r){
            mid=(l+r)>>1;
            if(p[mid]<q[i]){r=mid;}
            else{l=mid+1;}
        }
        update1(1,1,n,n+1-i,2*n+1-2*i-chaxun(p[i]));
        xiugai(q[i],1);
        if(l<=n){update(1,1,n,1,n+1-l,1);}
        cnt[i-1]=min(n+1-i,tree[1]-1);
    }
    memset(tree,INF,sizeof(tree));
    memset(tag,0,sizeof(tag));
    memset(tre,0,sizeof(tre));
    ma=cnt[0];
    cnt[n]=0;
    for(i=1;i<=n;i++){
        l=0;r=i;
        while(l<r){
            mid=(l+r+1)>>1;
            if(p[mid]>q[i]){l = mid;}
            else{r=mid-1;}
        }
        update1(1,1,n,i,i+chaxun(p[i]));
        xiugai(q[i],1);
        if(l){update(1,1,n,1,l,1);}
        ma=max(ma,min(i,tree[1]-1)+cnt[i]);
    }
    printf("%d",ma);
    return 0;
}