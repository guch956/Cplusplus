#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=70003;
const int INF=0x3f3f3f3f;
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
int deep[N];
int ans[N];
int d[N];
int siz[N],g1,mson,total,subtr;
bool del[N];
int num1[N],num2[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void bfs(int n){
    int i,u,v;
    queue<int> q;
    for(i=1;i<=n;i++){
        if(deep[i]==1){
            q.push(i);
            d[i]=0;
        }
        else{d[i]=INF;}
    }
    while(q.size()){
        u = q.front();
        q.pop();
        for(i=head[u];i;i=g[i].next){
            v = g[i].to;
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
void findg(int s,int f){
    int i,v,ma=0;
    siz[s]=1;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f || del[v]){continue;}
        findg(v,s);
        siz[s]+=siz[v];
        ma=max(siz[v],ma);
    }
    ma=max(total-siz[s],ma);
    if(ma<mson){
        g1 = s;
        mson=ma;
    }
}
int getans(int s,int f,bool xing){
    int an=0,i,v,a;
    deep[s]=deep[f]+1;
    siz[s]=1;
    v = d[s]-deep[s];
    a = d[f]-deep[f];
    if(v>=0 && v<a){for(i=v;i<a;i++){num1[i]++;}}
    if(xing && v<=0){an++;xing=0;}
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f || del[v]){continue;}
        an+=getans(v,s,xing);
        siz[s]+=siz[v];
    }
    return an;
}
void getnum2(int s,int f,int d1){
    int i,v,a;
    v = d[s]-deep[s];
    if(v<0){return;}
    a = d[f]-deep[f];
    if(v<a){for(i=v;i<a;i++){num2[i]+=d1;}}
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(del[v] || v==f){continue;}
        getnum2(v,s,d1);
    }
}
void getnum1(int s,int f){
    int i,v,a;
    v = d[s]-deep[s];
    if(v<0){return;}
    a = d[f]-deep[f];
    if(v<a){for(i=v;i<a;i++){num1[i]--;}}
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(del[v] || v==f){continue;}
        getnum1(v,s);
    }
}
void getsubt(int s,int f){
    int i,v;
    if(deep[s]>=d[g1]){
        if(deep[s]-1<d[subtr]){
            ans[s]++;
        }
    }
    else{
        ans[s]+=num1[deep[s]];
        ans[s]-=num2[deep[s]];
    }
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f || del[v]){continue;}
        getsubt(v,s);
    }
}
void fenzhi(int s){
    int i,v;
    del[s]=1;
    ans[s]+=getans(s,0,1);
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(del[v]){continue;}
        subtr=v;
        getnum2(v,s,1);
        getsubt(v,s);
        getnum2(v,s,-1);
    }
    getnum1(s,0);
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
    int n,i,a,b;
    scanf("%d",&n);
    deep[0]=-1;
    d[0]=-INF;
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        deep[a]++;
        deep[b]++;
        adde(a,b);
        adde(b,a);
    }
    bfs(n);
    total = n;
    mson=INF;
    findg(1,0);
    fenzhi(g1);
    for(i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}