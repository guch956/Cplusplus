#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int n=100000;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
int sum[N<<2];
int righ[N<<2];
bool tag[N<<2];
void push_up(int p){
    sum[p]=sum[ls(p)]+sum[rs(p)];
    righ[p]=max(righ[ls(p)],righ[rs(p)]);
}
void addtag(int p){
    sum[p]=0;
    righ[p]=0;
    tag[p]=1;
}
void push_down(int p){
    if(tag[p]){
        addtag(ls(p));
        addtag(rs(p));
        tag[p]=0;
    }
}
int chaxun(int p,int pl,int pr,int l){
    if(pl==pr){return pl;}
    push_down(p);
    int mid=(pl+pr)>>1;
    if(righ[ls(p)]>=l){
        return chaxun(ls(p),pl,mid,l);
    }
    else {
        return chaxun(rs(p),mid+1,pr,l);
    }
}
void update1(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){
        addtag(p);return ;
    }
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update1(ls(p),pl,mid,l,r);}
    if(r>mid){update1(rs(p),mid+1,pr,l,r);}
    push_up(p);
}
void update2(int p,int pl,int pr,int l,int r){
    if(pl==pr){sum[p]=1;righ[p]=r;return ;}
    push_down(p);
    int mid=(pl+pr)>>1;
    if(l<=mid){update2(ls(p),pl,mid,l,r);}
    else{update2(rs(p),mid+1,pr,l,r);}
    push_up(p);
}
int main(){
    int m,a,b,d,e;
    char c;
    scanf("%d",&m);
    while(m--){
        cin>>c;
        if(c=='A'){
            d=sum[1];
            scanf("%d %d",&a,&b);
            e=b+1;
            if(righ[1]>=a){
                e=chaxun(1,1,n,a);
            }
            if(e<=b){
                update1(1,1,n,e,b);
            }
            update2(1,1,n,a,b);
            printf("%d\n",d-sum[1]+1);
        }
        else{
            printf("%d\n",sum[1]);
        }
    }
    return 0;
}