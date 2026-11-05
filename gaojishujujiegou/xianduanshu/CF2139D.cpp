#include<iostream>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=500003;
struct node{
    int ma;
    int mi;
    bool exist;
    node(){ma=-INF;mi=INF;exist=0;}
};
node tree[N<<2];
int lef[N];
int A[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
node hebing(node n1,node n2){
    node c;
    c.exist=n1.exist||n2.exist;
    c.ma=max(n1.ma,n2.ma);
    c.mi=min(n1.mi,n2.mi);
    if(n1.ma>n2.mi)c.exist=1;
    return c;
}
void push_up(int p){
    tree[p]=hebing(tree[ls(p)],tree[rs(p)]);
}
void update(int p,int pl,int pr,int x,int d){
    if(pl==pr){
        if(d==-1){tree[p].ma=-INF;tree[p].mi=INF;}
        else{tree[p].ma=tree[p].mi=d;};
        return ;
    }
    int mid=(pl+pr)>>1;
    if(x<=mid){update(ls(p),pl,mid,x,d);}
    else{update(rs(p),mid+1,pr,x,d);}
    push_up(p);
}
node chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;
    node ans;
    if(l<=mid){ans = hebing(ans,chaxun(ls(p),pl,mid,l,r));}
    if(r>mid){ans = hebing(ans,chaxun(rs(p),mid+1,pr,l,r));}
    return ans;
}
int main(){
    int T,n,i,j,a,q;
    node u;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&q);
        for(i=1;i<=n*4;i++){
            tree[i].ma=-INF;
            tree[i].mi=INF;
            tree[i].exist=0;
        }
        j = 1;
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            update(1,1,n,a,i);
            A[i]=a;
            while(1){
                u = node();
                if(a<=n){u = chaxun(1,1,n,a+1,n);}
                if(u.exist){
                    update(1,1,n,A[j],-1);
                    j++;
                }
                else{break;}
            }
            lef[i]=j;
        }
        while(q--){
            scanf("%d %d",&i,&j);
            if(lef[j]<=i){printf("YES\n");}
            else{printf("NO\n");}
        }
    }
    return 0;
}