#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=1000003;
struct {
    int son[26];
    int father;
    ll len;
    ll cishu;
}t[N<<1];
int ent=-1;
int last;
char s[N];
struct {
    int next;
    int to;
}g[N<<1];
int head[N<<1];
int ent1;
long long ans;
int newnode(int l){
    ent++;
    t[ent].father=-1;
    t[ent].len=l;
    return ent;
}
void init(){
    ent=-1;
    last=newnode(0);
}
void adde(int u,int v){
    ent1++;
    g[ent1].to=v;
    g[ent1].next=head[u];
    head[u]=ent1;
}
void dfs(int s){
    int i,v;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        dfs(v);
        t[s].cishu+=t[v].cishu;
    }
    if(t[s].cishu>1){
        ans=max(ans,t[s].cishu*t[s].len);
    }
}
void insert(int c){
    int p=last,q,cur,nq;
    cur=newnode(t[p].len+1);
    while(p!=-1 && !t[p].son[c]){
        t[p].son[c]=cur;
        p = t[p].father;
    }
    if(p==-1){
        t[cur].father=0;
    }
    else{
        q = t[p].son[c];
        if(t[q].len==t[p].len+1){
            t[cur].father=q;
        }
        else{
            nq=newnode(t[p].len+1);
            memcpy(t[nq].son,t[q].son,sizeof(t[q].son));
            t[nq].father=t[q].father;
            t[q].father=t[cur].father=nq;
            while(p!=-1 && t[p].son[c]==q){
                t[p].son[c]=nq;
                p=t[p].father;
            }
        }
    }
    last=cur;
    t[last].cishu++;
}
int main(){
    int i;
    scanf("%s",s);
    init();
    for(i=0;s[i];i++){
        insert(s[i]-'a');
    }
    for(i=1;i<=ent;i++){
        adde(t[i].father,i);
    }
    dfs(0);
    printf("%lld",ans);
    return 0;
}