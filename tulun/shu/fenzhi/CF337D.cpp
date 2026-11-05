#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
const int INF=0x3f3f3f3f;
bool zy[N],buxing[N],del[N];
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
int deep[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
int son,len1,len2,mlen,d,l;
int g1,total,mson;
int siz[N];
void findg(int s,int f){
    int ma=0,i,v;
    siz[s]=1;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f || del[v]){continue;}
        findg(v,s);
        ma=max(ma,siz[v]);
        siz[s]+=siz[v];
    }
    ma=max(ma,total-ma);
    if(ma<mson){
        g1 = s;
        mson=ma;
    }
}
void jisuan(int s,int f){
    int i,v;
    deep[s]=deep[f]+1;
    siz[s]=1;
    if(zy[s]){mlen=max(mlen,deep[s]);}
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f || del[v]){continue;}
        jisuan(v,s);
        siz[s]+=siz[v];
    }
}
void check(int s,int f){
    int i,v;
    if(deep[s]+l>d){buxing[s]=1;}
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f || del[v]){continue;}
        check(v,s);
    }
}
void fenzhi(int s){
    int i,v;
    del[s]=1;
    deep[s]=0;
    len1=len2=-INF;
    son=0;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(del[v]){continue;}
        mlen=-INF;
        jisuan(v,s);
        if(mlen>d){
            buxing[s]=1;
        }
        if(mlen>len1){
            len2=len1;
            len1=mlen;
            son=v;
        }
        else if(mlen>len2){
            len2=mlen;
        }
    }
    if(zy[s]){
        if(len1<0){
            len1=0;
            son=0;
        }
        else if(len2<0){
            len2=0;
        }
    }
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(del[v]){continue;}
        if(v==son){l=len2;}
        else {l=len1;}
        check(v,s);
    }
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(del[v]){continue;}
        total=siz[v];
        mson=INF;
        findg(v,s);
        fenzhi(g1);
    }
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d %d",&n,&m,&d);
    for(i=1;i<=m;i++){
        scanf("%d",&a);
        zy[a]=1;
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    total=n;
    mson=INF;
    findg(1,0);
    fenzhi(g1);
    a = 0;
    for(i=1;i<=n;i++){
        if(!buxing[i]){a++;}
    }
    printf("%d",a);
    return 0;
}

