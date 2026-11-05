#include<iostream>
#include<cstdio>
using namespace std;
const int N=300003;
int head[N],nex[N],to[N];
int centroid[N],siz[N];
int fa[N];
int ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s){
    int i;
    int ma=0;;
    siz[s]=1;
    for(i=head[s];i;i=nex[i]){
        dfs(to[i]);
        if(siz[to[i]]>siz[ma]){ma = to[i];}
        siz[s]+=siz[to[i]];
    }
    if(2*siz[ma]<=siz[s]){
        centroid[s] = s;
    }   
    else{
        int g = centroid[ma];
        while(2*siz[g]<siz[s]){
            g = fa[g];
        }
        centroid[s] = g;
    }
}
int main(){
    int i,n,a,q;
    scanf("%d %d",&n,&q);
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        adde(a,i);
        fa[i] = a;
    }
    dfs(1);
    while(q--){
        scanf("%d",&a);
        printf("%d\n",centroid[a]);
    }
    return 0;
}