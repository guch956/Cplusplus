#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=400003;
int head[N],nex[N<<1],to[N<<1],ent;
int dfm[N],dfn,siz[N];
int col[N];
ll tree[N<<2];
ll tag[N<<2];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void push_up(int p){tree[p]=tree[ls(p)]|tree[rs(p)];}
void addtag(int p,ll d){
    tag[p]=d;
    tree[p]=d;
}
void push_down(int p){
    if(tag[p]!=0){
        addtag(ls(p),tag[p]);
        addtag(rs(p),tag[p]);
        tag[p]=0;
    }
}
ll chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;
    ll ans=0;
    push_down(p);
    if(l<=mid)ans = ans|chaxun(ls(p),pl,mid,l,r);
    if(r>mid)ans = ans|chaxun(rs(p),mid+1,pr,l,r);
    return ans;
}
void update(int p,int pl,int pr,int l,int r,ll d){
    if(l<=pl && r>=pr){
        addtag(p,d);
        return ;
    }
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid)update(ls(p),pl,mid,l,r,d);
    if(r>mid)update(rs(p),mid+1,pr,l,r,d);
    push_up(p);
}
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    dfm[s]=++dfn;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f)continue;
        dfs(to[i],s);
        siz[s]+=siz[to[i]];
        siz[s]++;
    }
}
int main(){
    int n,i,a,b,q;
    ll c;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){scanf("%d",&col[i]);}
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    for(i=1;i<=n;i++)update(1,1,n,dfm[i],dfm[i],(ll)1<<(col[i]-1));
    while(q--){
        scanf("%d",&i);
        if(i==1){
            scanf("%d %d",&a,&b);
            update(1,1,n,dfm[a],dfm[a]+siz[a],(ll)1<<(b-1));
        }
        else{
            scanf("%d",&a);
            c = chaxun(1,1,n,dfm[a],dfm[a]+siz[a]);
            b = 0;
            while(c){
                if(c&1)b++;
                c = c>>1;
            }
            printf("%d\n",b);
        }
    }
    return 0;
}