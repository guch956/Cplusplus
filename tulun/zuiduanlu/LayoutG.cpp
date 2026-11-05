#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=1003;
bool inque[N];
int cishu[N];
int dis[N];
int head[N],nex[N*21],to[N*21],ent;
int len[N*20];
void adde(int u,int v,int l){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    len[ent]=l;
    head[u]=ent;
}
int n;
int spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(cishu,0,sizeof(cishu));
    memset(inque,0,sizeof(inque));
    int i,u,d;
    queue<int> q;
    dis[s]=0;inque[s]=1;
    q.push(s);
    while(q.size()){
        u = q.front();
        inque[u]=0;
        q.pop();
        for(i=head[u];i;i=nex[i]){
            d = dis[u]+len[i];
            if(d<dis[to[i]]){
                if(!inque[to[i]]){
                    inque[to[i]]=1;
                    cishu[to[i]]++;
                    if(cishu[to[i]]>n){return 1;}
                    q.push(to[i]);
                }
                dis[to[i]]=d;
            }
        }
    }
    return 0;
}
int main(){
    int m1,m2,a,b,c,i;
    scanf("%d %d %d",&n,&m1,&m2);
    for(i=n;i>1;i--){adde(i,i-1,0);}
    while(m1--){
        scanf("%d %d %d",&a,&b,&c);
        adde(a,b,c);
    }
    while(m2--){
        scanf("%d %d %d",&a,&b,&c);
        adde(b,a,-c);
    }
    if(spfa(n)){
        printf("-1\n");
    }
    else{
        spfa(1);
        if(dis[n]==0x3f3f3f3f){printf("-2\n");}
        else{printf("%d\n",dis[n]);}
    }
    return 0;
}