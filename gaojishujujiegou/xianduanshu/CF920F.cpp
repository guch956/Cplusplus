#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=300003;
int mip[N<<2],ent;
int pri[N<<2];
int d[N<<2];
ll sum[N<<2];
int tag[N<<2];
int A[N];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
void init(int m){
    int i,j,c,k;
    d[1]=1;
    for(i=2;i<=m;i++){
        if(!mip[i]){
            d[i]=2;
            pri[++ent]=i;
        }
        else{
            c = mip[i];k = 1;
            while(i%c==0){c=c*mip[i];k++;}
            c = c/mip[i];
            d[i]=k*d[i/c];
        }
        for(j=1;j<=ent;j++){
            if(i*pri[j]>m){break;}
            mip[i*pri[j]]=pri[j];
            if(i%pri[j]==0){break;}
        }
    }
} 
void push_up(int p){
    sum[p]=sum[ls(p)]+sum[rs(p)];
    tag[p]=tag[ls(p)]&tag[rs(p)];
}
void build(int p,int pl,int pr){
    if(pl==pr){
        sum[p]=A[pl];
        if(A[pl]==1 || A[pl]==2){tag[p]=1;}
        else{tag[p]=0;}
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r){
    if(tag[p]){return ;}
    if(pl==pr){
        sum[p]=d[sum[p]];
        if(sum[p]==1 || sum[p]==2){tag[p]=1;}
        return ;
    }
    int mid=(pl+pr)>>1;
    if(l<=mid){update(ls(p),pl,mid,l,r);}
    if(r>mid){update(rs(p),mid+1,pr,l,r);}
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return sum[p];}
    int mid=(pl+pr)>>1;
    ll ans=0;
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans;
}
int main(){
    int n,q,a=0,i,b;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        a = max(a,A[i]);
    }
    init(a);
    build(1,1,n);
    while(q--){
        scanf("%d %d %d",&i,&a,&b);
        if(i==1){
            update(1,1,n,a,b);
        }
        else{
            printf("%lld\n",chaxun(1,1,n,a,b));
        }
    }
    return 0;
}