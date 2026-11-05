#include<iostream>
#include<cstdio>
using namespace std;
const int N=20003;
int head[N],to[N*10],nex[N*10],ent;
int dfm[N],low[N],r,dfn;
int iscut[N],cnt;
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void dfs(int s,int f){
    int i,num=0;
    dfm[s]=low[s]=++dfn;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        if(!dfm[to[i]]){
            num++;
            dfs(to[i],s);
            low[s]=min(low[s],low[to[i]]);
            if(low[to[i]]>=dfm[s] && !iscut[s] && s!=r){cnt++;iscut[s]=1;}
        }
        else{
            low[s]=min(low[s],dfm[to[i]]);
        }
    }
    if(s==r && num>=2){
        cnt++;
        iscut[s]=1;
    }
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    for(i=1;i<=n;i++){
        if(!dfm[i]){
            r = i;
            dfs(i,0);
        }
    }
    printf("%d\n",cnt);
    for(i=1;i<=n;i++){
        if(iscut[i])printf("%d ",i);
    }
    return 0;
}