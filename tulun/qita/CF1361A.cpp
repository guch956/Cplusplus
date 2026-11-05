#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;
int head[N],nex[N<<1],to[N<<1],ent;
int exist[N];
int qiwang[N];
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
int main(){
    int n,m,i,a,b,num;
    bool ok=1;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&qiwang[i]);
    }
    for(a=1;a<=n;a++){
        num = 1;
        for(i=head[a];i;i=nex[i]){
            if(qiwang[to[i]]==qiwang[a]){ok=0;}
            if(!exist[qiwang[to[i]]]){
                exist[qiwang[to[i]]]=1;
                if(qiwang[to[i]]<qiwang[a]){num++;}
            }
        }
        if(num!=qiwang[a]){ok=0;}
        for(i=head[a];i;i=nex[i]){
            exist[qiwang[to[i]]]=0;
        }
    }
    if(ok){
        for(i=1;i<=n;i++){head[i]=0;}
        ent = 0;
        for(i=1;i<=n;i++){adde(qiwang[i],i);}
        for(a=1;a<=n;a++){
            for(i=head[a];i;i=nex[i]){
                printf("%d ",to[i]);
            }
        }
    }
    else{printf("-1");}
    return 0;
}