#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=200003;
int fa[N],nex[N<<1],to[N<<1],head[N],ent;
int son[N];
ll val[N];
int siz[N];
struct node{
    int id;
    ll v;
    node(int i,ll v1){id=i;v=v1;}
    bool operator <(const node & n1)const{
        return v<n1.v;
    }
};
priority_queue<node> q;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    fa[s]=f;
    int i;
    val[s]=val[f]+1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        son[s]++;
        dfs(to[i],s);
    }
    if(son[s]==0){
        siz[s]=1;
        q.push(node(s,val[s]));
    }
}
int main(){
    ll ans=0;
    int n,k,i,b,a;
    node u(0,0);
    val[0]=-1;
    scanf("%d %d",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,0);
    while(k--){
        u = q.top();
        q.pop();
        ans+=u.v;
        siz[fa[u.id]]+=siz[u.id];
        son[fa[u.id]]--;
        if(son[fa[u.id]]==0){
            q.push(node(fa[u.id],val[fa[u.id]]-siz[fa[u.id]]));
            siz[fa[u.id]]++;
        }
    }
    printf("%lld",ans);
    return 0;
}