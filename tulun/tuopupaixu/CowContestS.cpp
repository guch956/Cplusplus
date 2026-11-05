#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int head[103],to[9003],nex[9003];
int ent=1;
int num[103][2];
int vis[103],geshu;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int k){
    int i;
    vis[s]=1;
    geshu++;
    for(i=head[s];i;i=nex[i]){
        if(i%2==k){
            if(!vis[to[i]]){dfs(to[i],k);}
        }
    }
}
int main(){
    int n,m=0,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){scanf("%d %d",&a,&b);adde(a,b);adde(b,a);}
    for(i=1;i<=n;i++){
        geshu=0;
        memset(vis,0,sizeof(vis));
        dfs(i,0);
        num[i][0]=geshu;
        geshu=0;
        memset(vis,0,sizeof(vis));
        dfs(i,1);
        num[i][1]=geshu;
    }
    m=0;
    for(i=1;i<=n;i++){
        if(num[i][0]+num[i][1]==n+1){
            m++;
        }
    }
    printf("%d\n",m);
    return 0;
}
