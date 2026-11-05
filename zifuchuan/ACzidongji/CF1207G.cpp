#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=400003;
struct {
    int son[26];
    int fail;
}t[N];
struct {
    int son[26];
}tr[N];
inline int lowbit(int x){return x&(-x);}
int ent;
int entr;
char p[N];
int tree[N];
int dfm[N],siz[N];
int dfn;
int ans[N];
struct {
    int to;
    int next;
}g[N];
struct {
    int to;
    int next;
    int bianhao;
}gq[N];
int headq[N],entq;
int head[N],entg;
int weizhi[N];
void addeq(int u,int v,int bh){
    entq++;
    gq[entq].to=v;
    gq[entq].next=headq[u];
    gq[entq].bianhao=bh;
    headq[u]=entq;
}
void update(int x,int d){
    while(x<=dfn){
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
int add(int now,int k){
    if(!tr[now].son[k]){
        tr[now].son[k]=++entr;
    }
    return tr[now].son[k];
}
void adde(int u,int v){
    entg++;
    g[entg].to=v;
    g[entg].next=head[u];
    head[u]=entg;
}
int insert(char *s){
    int i,now=0,ch;
    for(i=0;s[i];i++){
        ch=s[i]-'a';
        if(!t[now].son[ch]){
            t[now].son[ch]=++ent;
        }
        now=t[now].son[ch];
    }
    return now;
}
void dfs(int s){
    int i,v;
    dfm[s]=++dfn;
    siz[s]=1;
    for(i=head[s];i;i=g[i].next){
        v=g[i].to;
        dfs(v);
        siz[s]+=siz[v];
    }
}
void getfail(){
    int now,i;
    queue<int> q;
    for(i=0;i<26;i++){
        if(t[0].son[i]){
            q.push(t[0].son[i]);
        }
    }
    while(q.size()){
        now=q.front();
        q.pop();
        adde(t[now].fail,now);
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
    dfs(0);
}
void dfs2(int s,int now){
    int i,v;
    update(dfm[now],1);
    for(i=headq[s];i;i=gq[i].next){
        v = gq[i].to;
        ans[gq[i].bianhao]=chaxun(dfm[v]+siz[v]-1)-chaxun(dfm[v]-1);
    }
    for(i=0;i<26;i++){
        if(tr[s].son[i]){
            dfs2(tr[s].son[i],t[now].son[i]);
        }
    }
    update(dfm[now],-1);
}
int main(){
    int n,m,d,i,k;
    char c;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        if(k==1){
            cin>>c;
            weizhi[i]=add(0,c-'a');
        }
        else{
            scanf("%d",&d);
            cin>>c;
            weizhi[i]=add(weizhi[d],c-'a');
        }
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d",&d);
        scanf("%s",p);
        k = insert(p);
        addeq(weizhi[d],k,i);
    }
    getfail();
    dfs2(0,0);
    for(i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
