#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100003;
struct {
    int son[26];
    int fail;
    int deep;
    int father;
}t[N];
int ent;
struct {
    int to;
    int next;
}g[N];
int dfm[N],dfn,siz[N];
struct {
    int to;
    int next;
    int bianhao;
}gq[N];
char p[N];
int ans[N];
int entg,entq;
int headg[N],headq[N];
int weizhi[N];
void addeg(int u,int v){
    entg++;
    g[entg].to=v;
    g[entg].next=headg[u];
    headg[u]=entg;
}
void addeq(int u,int v,int a){
    entq++;
    gq[entq].to=v;
    gq[entq].next=headq[u];
    gq[entq].bianhao=a;
    headq[u]=entq;
}
int newnode(int d,int f){
    ent++;
    t[ent].deep=d;
    t[ent].father=f;
    return ent;
}
void insert(char *s,int slen){
    int i,now=0,num=0,ch;
    for(i=0;i<slen;i++){
        if(s[i]=='B'){
            now=t[now].father;
        }
        else if(s[i]=='P'){
            weizhi[++num]=now;
        }
        else{
            ch=s[i]-'a';
            if(!t[now].son[ch]){
                t[now].son[ch]=newnode(t[now].deep+1,now);
            }
            now=t[now].son[ch];
        }
    }
}
void dfs1(int s){
    int i,v;
    dfm[s]=++dfn;
    siz[s]=1;
    for(i=headg[s];i;i=g[i].next){
        v=g[i].to;
        dfs1(v);
        siz[s]+=siz[v];
    }
}
void getfail(){
    int i,now;
    queue<int> q;
    for(i=0;i<26;i++){
        if(t[0].son[i]){
            q.push(t[0].son[i]);
        }
    }
    while(q.size()){
        now=q.front();
        q.pop();
        addeg(t[now].fail,now);
        for(i=0;i<26;i++){
            if(t[now].son[i]){
                t[t[now].son[i]].fail=t[t[now].fail].son[i];
                q.push(t[now].son[i]);
            }
            else{
                t[now].son[i]=t[t[now].fail].son[i];
            }
        }
    }
    dfs1(0);
}
inline int lowbit(int x){
    return x&(-x);
}
int tree[N];
void update(int x,int d){
    while(x<=ent){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int chaxun(int x){
    int ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void dfs(int s){
    int i,v;
    update(dfm[s],1);
    for(i=headq[s];i;i=gq[i].next){
        v = gq[i].to;
        ans[gq[i].bianhao]=
            chaxun(dfm[v]+siz[v]-1)-chaxun(dfm[v]-1);
    }
    for(i=0;i<26;i++){
        if(t[t[s].son[i]].deep>t[s].deep){
            dfs(t[s].son[i]);
        }
    }
    update(dfm[s],-1);
}
int main(){
    int m,a,b,i;
    scanf("%s",p);
    insert(p,strlen(p));
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        addeq(weizhi[b],weizhi[a],i);
    }
    ent++;
    getfail();
    dfs(0);
    for(i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}