#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int head[N],to[N<<1],nex[N<<1],ent;
int deep[N];
int fa[N];
int md;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    fa[s]=f;
    deep[s]=deep[f]+1;
    if(deep[s]>deep[md]){md=s;}
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        dfs(to[i],s);
    }
}
int main(){
    int t,n,i,a,b;
    scanf("%d",&t);
    while(t--){
        md = 0;
        scanf("%d",&n);
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        dfs(1,0);
        dfs(md,0);
        b = 0;
        while (md){
            a = md;
            md = fa[md];
            for(i=head[md];i;i=nex[i]){
                if(to[i]==fa[md] || to[i]==a){continue;}
                b = to[i];
                break;
            }
            if(b){
                printf("%d %d %d",fa[md],md,b);
                break;
            }
        }
        if(b==0){printf("-1");}
        printf("\n");
        for(i=1;i<=n;i++){
            head[i]=0;
        }
        ent=0;
    }
    return 0;
}