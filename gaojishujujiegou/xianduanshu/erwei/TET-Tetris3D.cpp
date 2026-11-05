#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int N=1003;
ll tree[N<<2][N<<2];
ll tag[N<<2][N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
int d,s;
void subpush_up(int p1,int p2){
    tree[p1][p2]=max(tree[p1][ls(p2)],tree[p1][rs(p2)]);
}
void subaddtag(int p1,int p2,ll h){
    tree[p1][p2]=h;
    tag[p1][p2]=h;
}
void subpush_down(int p1,int p2){
    if(tag[p1][p2]!=0){
        subaddtag(p1,ls(p2),tag[p1][p2]);
        subaddtag(p1,rs(p2),tag[p1][p2]);
        tag[p1][p2]=0;
    }
}
ll subchaxun(int p1,int p2,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p1][p2];}
    subpush_down(p1,p2);
    int mid=(pl+pr)>>1;ll ans=0;
    if(l<=mid){ans=max(ans,subchaxun(p1,ls(p2),pl,mid,l,r));}
    if(r>mid){ans=max(ans,subchaxun(p1,rs(p2),mid+1,pr,l,r));}
    return ans;
}
ll chaxun(int p1,int pl,int pr,int l1,int r1,int l2,int r2){
    if(l1<=pl && r1>=pr){return subchaxun(p1,1,1,s,l2,r2);}
    int mid=(pl+pr)>>1;ll ans=0;
    if(l1<=mid){ans=max(ans,chaxun(ls(p1),pl,mid,l1,r1,l2,r2));}
    if(r1>mid){ans=max(ans,chaxun(rs(p1),mid+1,pr,l1,r1,l2,r2));}
    return ans;
}
void subupdate(int p1,int p2,int pl,int pr,int l,int r,ll h){
    if(l<=pl && r>=pr){subaddtag(p1,p2,h);return ;}
    subpush_down(p1,p2);
    int mid=(pl+pr)>>1;
    if(l<=mid){subupdate(p1,ls(p2),pl,mid,l,r,h);}
    if(r>mid){subupdate(p1,rs(p2),mid+1,pr,l,r,h);}
    subpush_up(p1,p2);
}
void update(int p1,int pl,int pr,int l1,int r1,int l2,int r2,ll h){
    if(l1<=pl & r1>=pr){subupdate(p1,1,1,s,l2,r2,h);return ;}
    int mid=(pl+pr)>>1;
    if(l1<=mid){update(ls(p1),pl,mid,l1,r1,l2,r2,h);}
    if(r1>mid){update(rs(p1),mid+1,pr,l1,r1,l2,r2,h);}
}
int main(){
    int n,a,b,c,e;
    ll w,h1;
    scanf("%d %d %d",&d,&s,&n);
    d++;s++;
    while(n){
        scanf("%d %d %lld %d %d",&a,&b,&w,&c,&e);
        c++;d++;
        h1 = chaxun(1,1,d,c,c+a,e,e+b);
        update(1,1,d,c,c+a,e,e+b,h1+w);
        n--;
    }
    printf("%lld",chaxun(1,1,d,1,d,1,s));
    return 0;
}

