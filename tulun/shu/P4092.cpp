#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int to[N<<1],nex[N<<1],head[N],ent;
int dfm[N],dfn,siz[N];
int tree[N<<2],tag[N<<2];
bool yes[N];
void adde(int u,int v){
    ent++;
    to[ent] = v;
    nex[ent] = head[u];
    head[u] = ent;
}
void dfs(int s,int f){
    int i;
    dfm[s] = ++dfn;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
        siz[s]+=siz[to[i]];
    }
    siz[s]++;
}
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p] = dfm[tree[ls(p)]]>dfm[tree[rs(p)]]?tree[ls(p)]:tree[rs(p)];
}
void addtag(int p,int x){
    if(dfm[x]>dfm[tag[p]]){
        tag[p] = x;
        if(dfm[tree[p]]<dfm[x]){
            tree[p] = x;
        }
    }

}
void push_down(int p){
    if(tag[p]){
        addtag(ls(p),tag[p]);
        addtag(rs(p),tag[p]);
        tag[p] = 0;
    }
}
void change(int p,int pl,int pr,int l,int r,int x){
    if(l<=pl && r>=pr){addtag(p,x);return ;}
    push_down(p);
    int mid = (pl+pr)>>1;
    if(l<=mid){change(ls(p),pl,mid,l,r,x);}
    if(r>mid){change(rs(p),mid+1,pr,l,r,x);}
    push_up(p);
}
int chaxun(int p,int pl,int pr,int d){
    if(pl==pr){return tree[p];}
    push_down(p);
    int mid=(pl+pr)>>1;
    if(d<=mid){return chaxun(ls(p),pl,mid,d);}
    else return chaxun(rs(p),mid+1,pr,d);
}
int main(){
    int n,i,a,b,q;
    char C;
    scanf("%d %d",&n,&q);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,0);
    yes[1] = 1;
    change(1,1,n,1,n,1);
    while(q--){
        cin>>C>>a;
        if(C=='C'){
            if(!yes[a]){
                change(1,1,n,dfm[a],dfm[a]+siz[a]-1,a);
                yes[a] = 1;
            }
        }
        else{
            printf("%d\n",chaxun(1,1,n,dfm[a]));
        }
    }
    return 0;
}