#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int N=1000003;
struct {
    int son[26];
    ll siz;
    int fail;
}t[N];
int ent;
bool exist[N];
char p[N];
int weizhi[N];
int num;
struct {
    int to;
    int next;
}g[N];
int head[N],entg;
int dfm[N],dfn,siz[N];
ll cha[N];
void adde(int u,int v){
    entg++;
    g[entg].to=v;
    g[entg].next=head[u];
    head[u]=entg;
}
void insert(char *s,int slen){
    int i,now=0,ch;
    for(i=0;i<slen;i++){
        ch=s[i]-'a';
        if(!t[now].son[ch]){
            t[now].son[ch]=++ent;
        }
        now=t[now].son[ch];
    }
    t[now].siz++;
    weizhi[++num]=now;
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
    cha[dfm[s]]=t[s].siz;
}
ll tree[N];
inline int lowbit(int x){return x&(-x);}
void update(int x,ll d){
    while(x<=ent){
        tree[x]+=d;
        x+=lowbit(x);
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
        t[now].siz+=t[t[now].fail].siz;
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
    ent++;
    for(i=1;i<=ent;i++){
        update(i,cha[i]-cha[i-1]);
    }
}
ll chaxun(int x){
    ll ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
ll query(char *s,int slen){
    int i,now=0;
    ll ans=0;
    for(i=0;i<slen;i++){
        now=t[now].son[s[i]-'a'];
        ans+=chaxun(dfm[now]);
    }
    return ans;
}
void xiugai(int x,ll d){
    update(dfm[x]+siz[x],-d);
    update(dfm[x],d);
}
int main(){
    int n,i,T;
    char c;
    scanf("%d %d",&T,&n);
    for(i=1;i<=n;i++){
        scanf("%s",p);
        insert(p,strlen(p));
        exist[i]=1;
    }
    getfail();
    while(T--){
        cin>>c;
        if(c=='?'){
            scanf("%s",p);
            printf("%lld\n",query(p,strlen(p)));
        }
        else if(c=='+'){
            scanf("%d",&i);
            if(!exist[i]){
                exist[i]=1;
                xiugai(weizhi[i],1);
            }
        }
        else{
            scanf("%d",&i);
            if(exist[i]){
                exist[i]=0;
                xiugai(weizhi[i],-1);
            }
        }
    }
    return 0;
}
