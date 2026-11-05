#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
struct node{
    ll zhi;
    int id;
}p[N<<1];
ll siz[N<<2];
ll caozuo[N][3];
int m;
bool bijiao(node & n1,node & n2){
    return n1.zhi<n2.zhi;
}
struct {
    int you;
    int wu;
    int tag;
}t[N<<4];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void push_up(int p){
    t[p].you=min(t[ls(p)].you,t[rs(p)].you);
    t[p].wu=min(t[ls(p)].wu,t[rs(p)].wu);
}
inline void addtag1(int p,int pl){
    t[p].wu=pl;
    t[p].you=m;
    t[p].tag=1;
}
inline void addtag2(int p,int pl){
    t[p].you=pl;
    t[p].wu=m;
    t[p].tag=2;
}
inline void addtag(int p,int pl){
    if(t[p].tag==0 || t[p].tag==3){
        swap(t[p].you,t[p].wu);
        t[p].tag=3-t[p].tag;
    }
    else{
        if(t[p].tag==1){addtag2(p,pl);return ;}
        if(t[p].tag==2){addtag1(p,pl);return ;}
    }
}
void push_down(int p,int pl,int mid){
    if(t[p].tag==3){
        addtag(ls(p),pl);
        addtag(rs(p),mid);
    }
    else if(t[p].tag==2){
        addtag2(ls(p),pl);
        addtag2(rs(p),mid);
    }
    else if(t[p].tag==1){
        addtag1(ls(p),pl);
        addtag1(rs(p),mid);
    }
    t[p].tag=0;
}
void update(int p,int pl,int pr,int l,int r,int ti){
    if(l<=pl && r>=pr){
        if(ti==1){addtag1(p,pl);}
        else if(ti==2){addtag2(p,pl);}
        else{addtag(p,pl);}
        return ;
    }
    int mid=(pl+pr)>>1;
    push_down(p,pl,mid+1);
    if(l<=mid)update(ls(p),pl,mid,l,r,ti);
    if(r>mid)update(rs(p),mid+1,pr,l,r,ti);
    push_up(p);
}
int main(){
    int n,d=1,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld %lld %lld",&caozuo[i][0],&caozuo[i][1],&caozuo[i][2]);
        p[ls(i)].id=ls(i);
        p[ls(i)].zhi=caozuo[i][1];
        p[rs(i)].id=rs(i);
        p[rs(i)].zhi=caozuo[i][2];
    }
    sort(p,p+2*n,bijiao);
    if(p[0].zhi!=1)siz[d++]=1;
    for(i=0;i<2*n;i++){
        if(p[i].id&1)caozuo[p[i].id>>1][2]=d;
        else caozuo[p[i].id>>1][1]=d;
        if(p[i+1].zhi!=p[i].zhi){
            siz[d++]=p[i].zhi;
            if(p[i+1].zhi>p[i].zhi+1){
                siz[d++]=p[i].zhi+1;
            }
        }
    }
    siz[d]=p[2*n-1].zhi+1;
    m = d;
    addtag2(1,1);
    for(i=0;i<n;i++){
        update(1,1,d,caozuo[i][1],caozuo[i][2],caozuo[i][0]);
        printf("%lld\n",siz[t[1].you]);
    }
    return 0;
}