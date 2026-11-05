#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct {
    int to;
    int next;
}g[N];int ent=1,head[N];int n;
void addedge(int u,int v){
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
    ent++;
}
int deep[N],son[N],fa[N],top[N],siz[N];
int dfn,dfnm[N];
void dfs1(int s){
    int i,v,smax=0,so=-1;
    deep[s]=deep[fa[s]]+1;
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        dfs1(v);
        siz[s]+=siz[v];
        if(siz[v]>smax){
            smax=siz[v];
            so=v;
        }
    }
    son[s]=so;
    siz[s]++;
}
void dfs2(int s,int topx){
    int i,v;
    dfn++;
    dfnm[s]=dfn;
    top[s]=topx;
    if(son[s]!=-1){dfs2(son[s],topx);}
    for(i=head[s];i!=0;i=g[i].next){
        v = g[i].to;
        if(v!=son[s]){
            dfs2(v,v);
        }
    }
}
int tree[N<<2],tag[N<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
}
void addtag(int p,int len,int d){
    tag[p]=d;
    tree[p]=len*d;
}
void push_down(int p,int len){
    if(tag[p]!=-1){
        addtag(ls(p),(len+1)>>1,tag[p]);
        addtag(rs(p),len>>1,tag[p]);
        tag[p]=-1;
    }
}
int update(int p,int pl,int pr,int l,int r,int d){
    int ans=0;
    if(l<=pl && r>=pr){
        ans=tree[p];
        addtag(p,pr-pl+1,d);
        return ans;
    }
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid){ans+=update(ls(p),pl,mid,l,r,d);}
    if(r>mid){ans+=update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
    return ans;
}
int chaxun1(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]]){swap(x,y);}
        ans+=deep[x]-deep[top[x]]+1-update(1,1,n,dfnm[top[x]],dfnm[x],1);
        x = fa[top[x]];
    }
    if(deep[x]>deep[y]){swap(x,y);}
    ans+=deep[y]-deep[x]+1-update(1,1,n,dfnm[x],dfnm[y],1);
    return ans;
}
int chaxun2(int x){
    return update(1,1,n,dfnm[x],dfnm[x]+siz[x]-1,0);
}
int main(){
    int m,i,a,root=0;
    char c[15];
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d",&a);
        fa[i]=a;
        addedge(a,i);
    }
    dfs1(root);
    dfs2(root,root);
    scanf("%d",&m);
    while(m){
        scanf("%s",c);
        if(c[0]=='i'){
            scanf("%d",&a);
            printf("%d\n",chaxun1(a,root));
        }
        else{
            scanf("%d",&a);
            printf("%d\n",chaxun2(a));
        }
        m--;
    }
    return 0;
}
