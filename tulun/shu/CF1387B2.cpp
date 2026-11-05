#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
ll sum[N];
ll siz[N];
int head[N],to[N<<1],nex[N<<1],ent;
int mg=1;
int weizhi[N];
int zhan[N],top;
queue<int> q;
bool bijiao(int n1,int n2){
    return siz[n1]>siz[n2];
}
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void dfs1(int s,int f){
    int i;
    siz[s]=sum[s]=0;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs1(to[i],s);
        siz[s]+=siz[to[i]];
        sum[s]+=sum[to[i]];
    }
    sum[s]+=siz[s];
    siz[s]++;
}
void dfs2(int s,int f){
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        sum[to[i]]=sum[s]-2*siz[to[i]]+siz[s];
        siz[to[i]]=siz[s];
        if(sum[to[i]]<sum[mg]){mg=to[i];}
        dfs2(to[i],s);
    }
}
void jia(int s,int f){
    q.push(s);
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        jia(to[i],s);
    }
}
void chuli(int s,int f){
    int i;
    weizhi[s]=q.front();
    q.pop();
    q.push(s);
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        chuli(to[i],s);
    }
}
int main(){
    int n,i,b,a;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs1(1,1);
    dfs2(1,1);
    dfs1(mg,0);
    for(i=head[mg];i;i=nex[i]){
        zhan[top++]=to[i];
    }
    sort(zhan,zhan+top,bijiao);
    jia(zhan[0],mg);
    for(i=1;i<top;i++){
        chuli(zhan[i],mg);
    }
    weizhi[mg]=q.front();
    q.pop();
    q.push(mg);
    chuli(zhan[0],mg);
    printf("%lld\n",2*sum[mg]);
    for(i=1;i<=n;i++){
        printf("%d ",weizhi[i]);
    }
    return 0;
}