#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int tree[N<<2];
int A[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int x){
    tree[x]=max(tree[ls(x)],tree[rs(x)]);
}
int chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1,ans=0;
    if(l<=mid){ans = max(chaxun(ls(p),pl,mid,l,r),ans);}
    if(r>mid){ans = max(chaxun(rs(p),mid+1,pr,l,r),ans);}
    return ans;
}
void update(int p,int pl,int pr,int x,int d){
    if(pl==pr){
        tree[p]=max(tree[p],d);
        return ;
    }
    int mid=(pl+pr)>>1;
    if(x<=mid){update(ls(p),pl,mid,x,d);}
    else{update(rs(p),mid+1,pr,x,d);}
    push_up(p);
}
void build(int p,int pl,int pr){
    if(pl==pr){tree[p]=A[pl];return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
int main(){
    int n,q,i,a,b;
    char c;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    build(1,1,n);
    while(q--){
        c = getchar();
        while(c!='Q' && c!='U'){c = getchar();}
        scanf("%d %d",&a,&b);
        if(c=='Q'){printf("%d\n",chaxun(1,1,n,a,b));}
        else{update(1,1,n,a,b);}
    }
    return 0;
}