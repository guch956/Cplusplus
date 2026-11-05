#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200003;
struct node{
    int x;
    int y;
    int num;
    bool iscow;
}p[N];
bool bijiao1(node & p1,node & p2){
    return p1.x<p2.x;
}
bool bijiao2(node & p1,node & p2){
    return p1.y==p2.y?p1.iscow:p1.y<p2.y;
}
int tree[N<<2];
bool tag[N<<2];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
}
void addtag(int p){
    tree[p]=0;
    tag[p]=1;
}
void push_down(int p){
    if(tag[p]){
        addtag(ls(p));
        addtag(rs(p));
        tag[p]=0;
    }
}
void update1(int p,int pl,int pr,int x,int d){
    int mid=(pl+pr)>>1;
    if(pl==pr){tree[p]+=d;return;}
    push_down(p);
    if(x<=mid){update1(ls(p),pl,mid,x,d);}
    else{update1(rs(p),mid+1,pr,x,d);}
    push_up(p);
}
void update2(int p,int pl,int pr,int l,int r){
    int mid=(pl+pr)>>1;
    if(l<=pl && r>=pr){addtag(p);return ;}
    push_down(p);
    if(l<=mid){update2(ls(p),pl,mid,l,r);}
    if(r>mid){update2(rs(p),mid+1,pr,l,r);}
    push_up(p);
}
int chaxun1(int p,int pl,int pr,int l,int r){
    int mid=(pl+pr)>>1;
    if(l<=pl && r>=pr){return tree[p];}
    int ans=0;
    push_down(p);
    if(l<=mid){ans+=chaxun1(ls(p),pl,mid,l,r);}
    if(r>mid){ans+=chaxun1(rs(p),mid+1,pr,l,r);}
    return ans;
}
int chaxun2(int p,int pl,int pr,int s){
    int mid=(pl+pr)>>1,ans;
    if(pl==pr){tree[p]=s;return pl;}
    push_down(p);
    if(tree[ls(p)]>=s){ans=chaxun2(ls(p),pl,mid,s);}
    else{ans=chaxun2(rs(p),mid+1,pr,s-tree[ls(p)]);}
    push_up(p);
    return ans;
}
int main(){
    int m,n,a,b,c,i;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d %d",&a,&b,&c,&p[i].num);
        p[i].iscow=(a==1);
        p[i].x=b+c;
        p[i].y=b-c;
    }
    sort(p+1,p+m+1,bijiao1);
    a = -1;p[0].x=0;b = 0;
    for(i=1;i<=m;i++){
        if(p[i].x!=a){
            a = p[i].x;
            p[i].x=p[i-1].x+1;
        }
        else{
            a = p[i].x;
            p[i].x=p[i-1].x;
        }
    }
    n = p[m].x;
    sort(p+1,p+m+1,bijiao2);
    for(i=1;i<=m;i++){
        if(p[i].iscow){
            update1(1,1,n,p[i].x,p[i].num);
        }
        else{
            c = chaxun1(1,1,n,1,p[i].x);
            if(c<=p[i].num){
                b+=c;
                update2(1,1,n,1,p[i].x);
            }
            else{
                b+=p[i].num;
                a = chaxun2(1,1,n,c-p[i].num)+1;
                if(a<=p[i].x){
                    update2(1,1,n,a,p[i].x);
                }
            }
        }
    }
    printf("%d",b);
    return 0;
}
