#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20003;
int tree[N<<2];
int tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void addtag(int p,int x){
    tree[p]+=x;
    tag[p]+=x;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
int chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1,ans=0;
    push_down(p);
    if(l<=mid){ans=max(ans,chaxun(ls(p),pl,mid,l,r));}
    if(r>mid){ans=max(ans,chaxun(rs(p),mid+1,pr,l,r));}
    return ans;
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
struct qujian{
    int l;
    int r;
    int ni;
}p[N*3];
bool bijiao(qujian q1,qujian q2){
    return q1.r<q2.r;
}
int main(){
    int n,m,i,c,a,b,ans=0;
    scanf("%d %d %d",&m,&n,&c);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&p[i].l,&p[i].r,&p[i].ni);
        p[i].r--;
    }
    sort(p+1,p+m+1,bijiao);
    for(i=1;i<=m;i++){
        a = chaxun(1,1,n,p[i].l,p[i].r);
        b = min(c-a,p[i].ni);
        ans+=b;
        if(b!=0){update(1,1,n,p[i].l,p[i].r,b);}
    }
    cout<<ans;
    return 0;
}