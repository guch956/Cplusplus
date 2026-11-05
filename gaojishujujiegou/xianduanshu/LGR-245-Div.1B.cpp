#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000003;
const int INF=0x3f3f3f3f;
int tma[N<<2],tag[N<<2];
int A[N];
int B[N];
int sum[N];
int ans[N],c;
int head[N],to[N],nex[N],id[N],ent;
int lef[N],n;
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline int lowbit(int x){return x&(-x);}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x){
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
inline void push_up1(int p){
    tma[p]=tma[ls(p)]+tma[rs(p)];
}
int chaxun(int x){
    int ans=0;
    while(x){
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}
void update(int x,int d){
    while(x<=n){
        sum[x]+=d;
        x+=lowbit(x);
    }
}
void adde(int u,int v,int i){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    id[ent]=i;
    head[u]=ent;
}
int chaxun1(int p,int pl,int pr,int r,int t){
    if(pl==pr){
        c = pl;
        return t-tma[p];
    }
    int mid=(pl+pr)>>1;
    if(r<=mid){return chaxun1(ls(p),pl,mid,r,t);}
    if(r>=pr){
        if(t<=tma[p]){
            if(tma[rs(p)]>=t){return chaxun1(rs(p),mid+1,pr,r,t);}
            else{return chaxun1(ls(p),pl,mid,r,t-tma[rs(p)]);}
        }
        else{return t-tma[p];}
    }
    int s = chaxun1(rs(p),mid+1,pr,r,t);
    if(s==0){return s;}
    else{return chaxun1(ls(p),pl,mid,r,s);}
}
void update1(int p,int pl,int pr,int x,int d){
    if(pl==pr){tma[p]+=d;return ;}
    int mid=(pl+pr)>>1;
    if(x<=mid){update1(ls(p),pl,mid,x,d);}
    else{update1(rs(p),mid+1,pr,x,d);}
    push_up1(p);
}
int main(){
    int T,i,a,b,k;
    scanf("%d %d %d",&n,&k,&T);
    for(i=1;i<=n;i++){
        A[i] = read();
        B[A[i]]=i;
    }
    for(i=1;i<=T;i++){
        a = read();b = read();
        adde(b,a-1,i);
    }
    for(i=1;i<=n;i++){
        lef[B[i]] = chaxun1(1,1,n,B[i],k);
        if(lef[B[i]]==0){lef[B[i]]=c;}
        else{lef[B[i]]=0;}
        update1(1,1,n,B[i],1); 
    }
    for(i=1;i<=n;i++){
        if(lef[i]){update(lef[i],1);}
        for(a=head[i];a;a=nex[a]){
            ans[id[a]]=i-to[a]-chaxun(i)+chaxun(to[a]);
        }
    }
    for(i=1;i<=T;i++){
        write(ans[i]);
        putchar('\n');
    }
    return 0;
}