#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=200003;
double sums[N<<2],sumc[N<<2];
double tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    sums[p]=sums[ls(p)]+sums[rs(p)];
    sumc[p]=sumc[ls(p)]+sumc[rs(p)];
}
void addtag(int p,double v){
    double s=sums[p],c=sumc[p];
    sums[p]=s*cos(v)+c*sin(v);
    sumc[p]=c*cos(v)-s*sin(v);
    tag[p]+=v;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
int A[N];
void build(int p,int pl,int pr){
    if(pl==pr){
        sums[p]=sin(A[pl]);
        sumc[p]=cos(A[pl]);
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
double chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return sums[p];}
    int mid=(pl+pr)>>1;
    double ans=0;
    push_down(p);
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans;
}
void update(int p,int pl,int pr,int l,int r,double d){
    if(l<=pl && r>=pr){addtag(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
int main(){
    int m,n,i,l,r;
    double v;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        scanf("%d",&i);
        if(i==1){
            scanf("%d %d %lf",&l,&r,&v);
            update(1,1,n,l,r,v);
        }
        else{
            scanf("%d %d",&l,&r);
            printf("%.1lf\n",chaxun(1,1,n,l,r));
        }
    }
    return 0;
}

