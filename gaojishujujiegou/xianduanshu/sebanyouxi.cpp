#include<cstdio>
#include<iostream>
const int N=100002;
int tree[N<<2];
int tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p]=tree[ls(p)]|tree[rs(p)];
}
void addtag(int p,int d){
    tag[p]=d;
    tree[p]=d;
}
void push_down(int p){
    if(tag[p]){
        addtag(ls(p),tag[p]);
        addtag(rs(p),tag[p]);
        tag[p]=0;
    }
}
void build(int p,int pl,int pr){
    tag[p]=0;
    if(pl==pr){tree[p]=1;return ;}
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
int  chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;int ans=0;
    push_down(p);
    if(l<=mid){ans=ans|chaxun(ls(p),pl,mid,l,r);}
    if(r>mid){ans=ans|chaxun(rs(p),mid+1,pr,l,r);}
    return ans;
}
int main(){
    int n,m,i,a,b,t,y,ans;
    char c;
    scanf("%d %d %d",&n,&t,&m);
    build(1,1,n);
    while(m){
        std::cin>>c;
        if(c=='P'){
            scanf("%d %d",&a,&b);
            if(a>b){std::swap(a,b);}
            y = chaxun(1,1,n,a,b);
            ans=0;
            while(y){
                if(y&1){ans++;}
                y = y>>1;
            }
            printf("%d\n",ans);
        }
        else{
            scanf(" %d %d %d",&a,&b,&y);
            if(a>b){std::swap(a,b);}
            update(1,1,n,a,b,1<<(y-1));
        }
        m--;
    }
    return 0;
}