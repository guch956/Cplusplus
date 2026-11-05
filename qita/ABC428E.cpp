#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;
int head[N],to[N<<1],nex[N<<1],ent;
int zhijing;
int dis[N],ma1,ma2;
int dis2[N];
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void dfs(int s,int f,int * d){
    int i;
    d[s]=d[f]+1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s,d);
    }
}
int main(){
    int n,i,a,b,malen;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dis[0]=-1;
    dis2[0]=-1;
    dfs(1,0,dis);
    malen = -1;
    for(i=1;i<=n;i++){
        if(dis[i]>=malen){
            malen = dis[i];
            ma1 = i;
        }
    }
    dfs(ma1,0,dis);
    malen = -1;
    for(i=1;i<=n;i++){
        if(dis[i]>=malen){
            malen = dis[i];
            ma2 = i;
        }
    }
    if(ma2>ma1){
        swap(ma2,ma1);
    }
    dfs(ma1,0,dis);
    dfs(ma2,0,dis2);
    for(i=1;i<=n;i++){
        if(dis[i]<dis2[i])printf("%d\n",ma2);
        else printf("%d\n",ma1);
    }
    return 0;
}