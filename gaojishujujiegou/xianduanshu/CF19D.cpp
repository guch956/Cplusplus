#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=200003;
const int INF=0x3f3f3f3f;
struct caozuo{
    int x;
    int y;
    int type;
    int id;
}p[N];
int q[N];
int yy[N];
int xx[N];
bool bijiaox(caozuo c1,caozuo c2){
    return c1.x<c2.x;
}
bool bijiaoy(caozuo c1,caozuo c2){
    return c1.y<c2.y;
}
bool bijiaoid(caozuo c1,caozuo c2){
    return c1.id<c2.id;
}
int tree[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
int chaxun(int p,int pl,int pr,int l,int r,int x){
    if(l<=pl && r>=pr && tree[p]<=x){return -1;}
    if(pl==pr){return pl;}
    int mid=(pl+pr)>>1,ans=-1;
    if(l<=mid){ans=chaxun(ls(p),pl,mid,l,r,x);}
    if(ans!=-1){return ans;}
    if(r>mid){ans=chaxun(rs(p),mid+1,pr,l,r,x);}
    return ans;
}
void update(int p,int pl,int pr,int x,int d){
    if(pl==pr){tree[p]=d;return ;}
    int mid=(pl+pr)>>1;
    if(x<=mid){update(ls(p),pl,mid,x,d);}
    else{update(rs(p),mid+1,pr,x,d);}
    push_up(p);
}
struct{
    int value;
    int ma;
    int lson;
    int rson;
    int exist;
}t[N];
int ent,root[N];
void push(int ro){
    if(t[ro].exist){t[ro].ma=t[ro].value;}
    else{t[ro].ma=-1;}
    t[ro].ma=max(max(t[t[ro].lson].ma,t[t[ro].rson].ma),t[ro].ma);
}
void buildt(int & ro,int l,int r){
    int mid=(l+r)>>1;
    ro = ++ent;
    t[ro].exist=0;
    t[ro].value=q[mid];
    t[ro].ma=-1;
    t[ro].lson=t[ro].rson=0;
    if(l<mid){buildt(t[ro].lson,l,mid-1);}
    if(r>mid){buildt(t[ro].rson,mid+1,r);}
}
void change(int ro,int x){
    if(t[ro].value==x){t[ro].exist^=1;push(ro);return;}
    if(x<t[ro].value){change(t[ro].lson,x);}
    else{change(t[ro].rson,x);}
    push(ro);
}
int query(int ro,int x){
    if(t[ro].ma<x){return -1;}
    int ans=-1;
    if(t[ro].lson){
        ans=query(t[ro].lson,x);
    }
    if(ans!=-1){return ans;}
    if(t[ro].value>=x && t[ro].exist){return t[ro].value;}
    return query(t[ro].rson,x);
}
int main(){
    char s[10];
    int n,i,a,b,nx=0,ny=0,j;
    scanf("%d",&n);
    t[0].ma=-1;
    for(i=0;i<n;i++){
        scanf("%s",s);
        scanf("%d %d",&p[i].x,&p[i].y);
        p[i].id=i;
        if(s[0]=='a'){p[i].type=1;}
        if(s[0]=='r'){p[i].type=2;}
        if(s[0]=='f'){p[i].type=3;}
    }
    sort(p,p+n,bijiaoy);
    p[n].y=INF;
    b = 0;
    for(i=0;i<n;i++){
        if(p[i].y!=p[i+1].y){
            ny++;
            yy[ny]=p[i].y;
            for(j=b;j<=i;j++){
                p[j].y=ny;
            }
            b = i+1;
        }
    }
    sort(p,p+n,bijiaox);
    p[n].x=INF;
    a = 0;
    for(i=0;i<n;i++){
        a++;
        q[a]=p[i].y;
        if(p[i].x!=p[i+1].x){
            nx++;
            xx[nx]=p[i].x;
            for(j=i-a+1;j<=i;j++){
                p[j].x=nx;
            }
            sort(q+1,q+a+1);
            b=1;q[a+1]=INF;
            for(j=1;j<=a;j++){
                if(q[j]!=q[j+1]){
                    q[b]=q[j];b++;
                }
            }
            buildt(root[nx],1,b-1);
            a = 0;
        }
    }
    sort(p,p+n,bijiaoid);
    for(i=0;i<n;i++){
        if(p[i].type==3){
            if(p[i].x==nx){printf("-1\n");}
            else{
                a = chaxun(1,1,nx,p[i].x+1,nx,p[i].y);
                if(a==-1){printf("-1\n");}
                else{printf("%d %d\n",xx[a],yy[query(root[a],p[i].y+1)]);}
            }
        }
        else{
            change(root[p[i].x],p[i].y);
            update(1,1,nx,p[i].x,t[root[p[i].x]].ma);
        }
    }
    return 0;
}
