#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200003;
const int INF=0x3f3f3f3f;
int dis1[N],point[N],dis2[N];
int head[N],to[N<<1],nex[N<<1],ent;
char s[N];
struct node{
    int from;
    int now;
    int dis;
    node(int f,int n,int d){from=f;now=n;dis=d;}
};
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void bfs(int n){
    int i,v,d;
    node u(0,0,0);
    queue<node> q;
    for(i=1;i<=n;i++){
        if(s[i]=='S'){
            q.push(node(i,i,0));
            dis2[i]=INF;
            point[i]=i;
        }
        else{dis1[i]=dis2[i]=INF;}
    }
    while(q.size()){
        u = q.front();
        q.pop();
        d = u.dis+1;
        for(i=head[u.now];i;i=nex[i]){
            v = to[i];
            if(d<dis1[v]){
                dis2[v]=dis1[v];
                dis1[v]=d;
                point[v]=u.from;
                q.push(node(u.from,v,d));
            }
            else if(d<dis2[v] && u.from!=point[v]){
                dis2[v]=d;
                q.push(node(u.from,v,d));
            }
        }
    }
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    scanf("%s",s+1);
    bfs(n);
    for(i=1;i<=n;i++){
        if(s[i]=='D'){
            printf("%d\n",dis1[i]+dis2[i]);
        }
    }
    return 0;
}