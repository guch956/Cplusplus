#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=204,M=10003;
const ll INF=0x3f3f3f3f3f3f3f3f;
int s,t,n,m;
int head[N],to[M],nex[M],ent=1;
ll w[M];
void adde(int u,int v,ll ww){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    w[ent]=ww;
    head[u]=ent;
}
int now[N];
ll dep[N];
int bfs(){
    int i,u;
    queue<int> q;
    for(i=1;i<=n;i++){dep[i]=INF;}
    dep[s]=0;
    now[s]=head[s];
    q.push(s);
    while(q.size()){
        u = q.front();
        q.pop();
        for(i=head[u];i;i=nex[i]){
            if(w[i]>0 && dep[to[i]]==INF){
                dep[to[i]]=dep[u]+1;
                now[to[i]]=head[to[i]];
                q.push(to[i]);
                if(to[i]==t){return 1;}
            }
        }
    }
    return 0;
}
ll dfs(int u,ll sum){
    if(u==t){return sum;}
    ll k,flow=0;
    int i;
    for(i=now[u];i && sum>0;i=nex[i]){
        now[u]=i;
        if(w[i]>0 && dep[to[i]]==dep[u]+1){
            k = dfs(to[i],min(w[i],sum));
            if(k==0){dep[to[i]]=INF;}
            w[i] -= k;
            w[i^1] += k;
            flow+=k;
            sum-=k;
        }
    }
    return flow;
}
int main(){
    int i,u,v;
    ll ww,ans=0;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(i=1;i<=m;i++){
        scanf("%d %d %lld",&u,&v,&ww);
        adde(u,v,ww);
        adde(v,u,0);
    }
    while(bfs()){ans+=dfs(s,INF);}
    cout<<ans;
    return 0;
}