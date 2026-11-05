#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=50003;
ll sum[N<<4];
ll tag[N<<4];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void addtag(int p,ll len,ll d){
    tag[p]+=d;
    sum[p]+=d*len;
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return sum[p];}
    int mid=(pl+pr)>>1;
    ll ans=(min(r,pr)-max(l,pl)+1)*tag[p];
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r);}
    return ans;
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag(p,pr-pl+1,d);return ;}
    sum[p]+=(min(pr,r)-max(pl,l)+1)*d;
    int mid=(pl+pr)>>1;
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
}
struct {
    int a;
    int b;
    int type;
    ll c;
    int id;
}q[N],q1[N],q2[N];
int n;
int ans[N];
void solve(int l,int r,int L,int R){
    if(l>r){return ;}
    if(L>R){return ;}
    if(l==r){
        for(int i=L;i<=R;i++){
            if(q[i].type==2){ans[q[i].id]=l;}
        }
        return ;
    }
    int i,mid=(l+r+1)>>1,ent1=0,ent2=0;
    ll t;
    for(i=L;i<=R;i++){
        if(q[i].type==2){
            t = q[i].c-chaxun(1,1,n,q[i].a,q[i].b);
            if(t>0){
                q[i].c=t;
                q1[ent1++]=q[i];
            }
            else{
                q2[ent2++]=q[i];
            }
        }
        else{
            if(q[i].c>=mid){
                update(1,1,n,q[i].a,q[i].b,1);
                q2[ent2++]=q[i];
            }
            else{q1[ent1++]=q[i];}
        }
        
    }
    for(i=0;i<ent1;i++){
        q[i+L]=q1[i];
    }
    for(i=0;i<ent2;i++){
        if(q2[i].type==1){
            update(1,1,n,q2[i].a,q2[i].b,-1);
        }
        q[i+L+ent1]=q2[i];
    }
    solve(l,mid-1,L,L+ent1-1);
    solve(mid,r,L+ent1,R);
}
int main(){
    int m,i,d=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d %lld",&q[i].type,&q[i].a,&q[i].b,&q[i].c);
        if(q[i].type==2){q[i].id=++d;}
        else{q[i].c+=n+1;}
    }
    solve(1,rs(n),1,m);
    for(i=1;i<=d;i++){
        printf("%d\n",ans[i]-n-1);
    }
    return 0;
}