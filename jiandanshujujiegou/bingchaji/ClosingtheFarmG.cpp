#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+3;
int head[N],nex[N<<1],to[N<<1],ent;
int fa[N];
int caozuo[N];
bool exist[N],xing[N];
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
int find(int x){
    if(fa[x]!=x){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
int main(){
    int liant=1,n,m,i,a,b,x,y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    for(i=1;i<n;i++){
        scanf("%d",&caozuo[i]);
        exist[caozuo[i]]=1;
        fa[i]=i;
    }
    fa[n]=n;
    xing[n]=1;
    for(i=n-1;i>=1;i--){
        liant++;
        b = caozuo[i];
        exist[b]=0;
        for(a=head[b];a;a=nex[a]){
            if(!exist[to[a]]){
                x = find(to[a]);
                y = find(b);
                if(x!=y){
                    liant--;
                    fa[y]=x;
                }
            }
        }
        if(liant==1){
            xing[i]=1;
        }
    }
    for(i=1;i<=n;i++){
        if(xing[i]){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}