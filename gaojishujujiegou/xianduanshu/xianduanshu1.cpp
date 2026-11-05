#include<iostream>
#define ll long long
const int N=300000;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
ll tree[N];
ll tag[N];
ll q[N];
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
}
void build(int p,int pl,int pr){
    tag[p]=0;
    if(pl==pr){tree[p]=q[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void add_tag(int p,int pl,int pr,ll d){
    tag[p]+=d;
    tree[p]+=(pr-pl+1)*d;
}
void push_down(int p,int pl,int pr){
    if(tag[p]!=0){
        int mid=(pl+pr)>>1;
        add_tag(ls(p),pl,mid,tag[p]);
        add_tag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){add_tag(p,pl,pr,d); return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pl,pr);
    if(l<=mid)update(ls(p),pl,mid,l,r,d);
    if(r>=mid+1)update(rs(p),mid+1,pr,l,r,d);
    push_up(p);
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;ll ans=0;
    push_down(p,pl,pr);
    if(l<=mid) ans+=chaxun(ls(p),pl,mid,l,r);
    if(r>=mid+1) ans+=chaxun(rs(p),mid+1,pr,l,r);
    return ans;
}
int main(){
    using namespace std;
    int n,m,i,k,x,y;
    ll d;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>q[i];
    }
    build(1,1,n);
    for(i=1;i<=m;i++){
        cin>>k;
        if(k==1){
            cin>>x>>y>>d;
            update(1,1,n,x,y,d);
        }
        else{
            cin>>x>>y;
            cout<<chaxun(1,1,n,x,y)<<endl;
        }
    }
    return 0;
}
