#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct {
    int tag1;/*赋值*/
    int tag2;/*取反*/
    int sum;
    int mlen0;
    int mlen1;
    int pre;
    int suf;
    int lt,rt;
}t[N<<2];
int A[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p,int len){
    t[p].sum=t[ls(p)].sum+t[rs(p)].sum;
    t[p].mlen0=max(t[ls(p)].mlen0,t[rs(p)].mlen0);
    t[p].mlen1=max(t[ls(p)].mlen1,t[rs(p)].mlen1);
    t[p].lt=t[ls(p)].lt;
    t[p].rt=t[rs(p)].rt;
    if(t[ls(p)].rt==t[rs(p)].lt){
        t[p].pre=t[ls(p)].pre==((len+1)>>1)?t[ls(p)].pre+t[rs(p)].pre:t[ls(p)].pre;
        t[p].suf=t[rs(p)].suf==(len>>1)?t[ls(p)].suf+t[rs(p)].suf:t[rs(p)].suf;
        if(t[ls(p)].rt==0){
            t[p].mlen0=max(t[p].mlen0,t[ls(p)].suf+t[rs(p)].pre);
        }
        else{
            t[p].mlen1=max(t[p].mlen1,t[ls(p)].suf+t[rs(p)].pre);
        }
    }
    else{
        t[p].pre=t[ls(p)].pre;
        t[p].suf=t[rs(p)].suf;
    }
}
void addtag1(int p,int len,int d){
    t[p].tag2=0;
    t[p].tag1=d;
    t[p].lt=t[p].rt=d;
    t[p].pre=t[p].suf=len;
    t[p].sum=d*len;
    if(d==0){
        t[p].mlen0=len;
        t[p].mlen1=0;
    }
    else{
        t[p].mlen0=0;
        t[p].mlen1=len;
    }
}
void addtag2(int p,int len){
    if(t[p].tag1!=-1){addtag1(p,len,t[p].tag1^1);return;}
    t[p].tag2^=1;
    t[p].sum=len-t[p].sum;
    t[p].lt^=1;
    t[p].rt^=1;
    swap(t[p].mlen0,t[p].mlen1);
}
void push_down(int p,int len){
    if(t[p].tag1!=-1){
        addtag1(ls(p),(len+1)>>1,t[p].tag1);
        addtag1(rs(p),len>>1,t[p].tag1);
        t[p].tag1=-1;
    }
    if(t[p].tag2){
        addtag2(ls(p),(len+1)>>1);
        addtag2(rs(p),len>>1);
        t[p].tag2=0;
    }
}
int chaxun1(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return t[p].sum;}
    int sum=0,mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){sum+=chaxun1(ls(p),pl,mid,l,r);}
    if(r>mid){sum+=chaxun1(rs(p),mid+1,pr,l,r);}
    return sum;
}
int chaxun2(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return t[p].mlen1;}
    int ans=0,mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l>mid){return chaxun2(rs(p),mid+1,pr,l,r);}
    if(r<=mid){return chaxun2(ls(p),pl,mid,l,r);}
    ans = max(chaxun2(ls(p),pl,mid,l,r),chaxun2(rs(p),mid+1,pr,l,r));
    if(t[ls(p)].rt==1 && t[rs(p)].lt==1){
        ans = max(ans,min(mid-l+1,t[ls(p)].suf)+min(r-mid,t[rs(p)].pre));
    }
    return ans;
}
void caozuo1(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag1(p,pr-pl+1,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){caozuo1(ls(p),pl,mid,l,r,d);}
    if(r>mid){caozuo1(rs(p),mid+1,pr,l,r,d);}
    push_up(p,pr-pl+1);
}
void caozuo2(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){addtag2(p,pr-pl+1);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){caozuo2(ls(p),pl,mid,l,r);}
    if(r>mid){caozuo2(rs(p),mid+1,pr,l,r);}
    push_up(p,pr-pl+1);
}
void build(int p,int pl,int pr){
    t[p].tag1=-1;
    if(pl==pr){
        t[p].lt=t[p].rt=A[pl];
        t[p].sum=A[pl];
        t[p].pre=t[p].suf=1;
        if(A[pl]==0){t[p].mlen0=1;}
        else{t[p].mlen1=1;}
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p,pr-pl+1);
}
int main(){
    int n,m,i,l,r;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    build(1,1,n);
    while(m--){
        scanf("%d %d %d",&i,&l,&r);
        l++;r++;
        if(i<=1){
            caozuo1(1,1,n,l,r,i);
        }
        else if(i==2){
            caozuo2(1,1,n,l,r);
        }
        else if(i==3){
            printf("%d\n",chaxun1(1,1,n,l,r));
        }
        else{
            printf("%d\n",chaxun2(1,1,n,l,r));
        }
    }
    return 0;
}