#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct {
    int ls;
    int rs;
    int num;
}t[N<<6];
int ent;
int fa[N];
int daxiao[N];
int paiming[N];
int root[N];
void push_up(int p){t[p].num=t[t[p].ls].num+t[t[p].rs].num;}
void build(int & p,int pl,int pr,int x){
    p = ++ent;
    if(pl==pr){t[p].num=1;return;}
    int mid=(pl+pr)>>1;
    if(x<=mid){build(t[p].ls,pl,mid,x);}
    else{build(t[p].rs,mid+1,pr,x);}
    push_up(p);
}
int find(int x){
    if(fa[x]!=x){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

int hebing(int r1,int r2){
    if(r1==0 || r2==0){return r1|r2;}
    t[r1].ls=hebing(t[r1].ls,t[r2].ls);
    t[r1].rs=hebing(t[r1].rs,t[r2].rs);
    push_up(r1);
    return r1;
}
int chaxun(int p,int pl,int pr,int k){
    if(pl==pr){return pl;}
    int mid=(pl+pr)>>1;
    if(t[t[p].ls].num>=k){
        return chaxun(t[p].ls,pl,mid,k);
    }
    else{
        return chaxun(t[p].rs,mid+1,pr,k-t[t[p].ls].num);
    }
}
int main(){
    int n,m,q,i,a,b,x,y;
    char c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&daxiao[i]);
        build(root[i],1,n,daxiao[i]);
        fa[i]=i;
        paiming[daxiao[i]]=i;
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        a = find(x);b = find(y);
        if(a!=b){
            root[a]=hebing(root[a],root[b]);
            fa[b]=a;
        }
    }
    scanf("%d",&q);
    while(q--){
        c = getchar();
        while(c!='B' && c!='Q'){c = getchar();}
        scanf("%d %d",&x,&y);
        if(c=='B'){
            a = find(x);b = find(y);
            if(a!=b){
                root[a]=hebing(root[a],root[b]);
                fa[b]=a;
            }
        }
        else{
            a = find(x);
            if(t[root[a]].num<y){printf("-1\n");}
            else{printf("%d\n",paiming[chaxun(root[a],1,n,y)]);}
        }
    }
    return 0;
}