#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
const ll P=1e9+7;
int q[N];
ll p[N];
ll p1[N];
ll p2[N];
int head,tail;
ll tree1[N<<2];
ll tree2[N<<2];
ll tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree1[p]=tree1[ls(p)]+tree1[rs(p)];
    tree2[p]=tree2[ls(p)]+tree2[rs(p)];
}
void addtag(int p,ll l,ll r,ll d){
    tag[p]+=d;
    tree1[p]+=d*(r-l+1);
    tree1[p]%=P;
    tree2[p]+=d*(r+l)*(r-l+1)/2;
    tree2[p]%=P;
}
void push_down(int p,ll l,ll r){
    ll mid=(l+r)>>1;
    addtag(ls(p),l,mid,tag[p]);
    addtag(rs(p),mid+1,r,tag[p]);
    tag[p]=0;
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){addtag(p,pl,pr,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pl,pr);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
ll chaxun1(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree1[p];}
    int mid=(pl+pr)>>1;
    ll ans=0;
    push_down(p,pl,pr);
    if(l<=mid){ans+=chaxun1(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun1(rs(p),mid+1,pr,l,r);}
    return ans;
}
ll chaxun2(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree2[p];}
    int mid=(pl+pr)>>1;
    ll ans=0;
    push_down(p,pl,pr);
    if(l<=mid){ans+=chaxun2(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun2(rs(p),mid+1,pr,l,r);}
    return ans;
}
int main(){
    int n,i,a,b;
    ll ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        p[a+1]=b+1;
    }
    head=1;
    tail=0;
    for(i=1;i<=n;i++){
        while(head<=tail && p[i]>=p[q[tail]]){tail--;}
        q[++tail]=i;
    }
    while(head<=tail){
        for(i=q[head-1]+1;i<=q[head];i++){
            p1[i]=p[q[head]];
        }
        head++;
    }
    head=1;
    tail=0;
    for(i=n;i>=1;i--){
        while(head<=tail && p[i]<=p[q[tail]]){tail--;}
        q[++tail]=i;
    }
    q[0]=n+1;
    while(head<=tail){
        for(i=q[head-1]-1;i>=q[head];i--){
            p2[i]=p[q[head]];
        }
        head++;
    }
    for(i=1;i<=n;i++){
        if(p2[i]<p1[i]){
            p1[i]--;
            ans+=(p1[i]+1)*chaxun1(1,1,n-1,p2[i],p1[i]);
            ans-=chaxun2(1,1,n-1,p2[i],p1[i]);
            ans=((ans%P)+P)%P;
            update(1,1,n-1,p2[i],p1[i],1);
        }
    }
    printf("%lld",ans);
    return 0;
}

