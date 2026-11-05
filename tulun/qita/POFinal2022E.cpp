#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int head[N],to[N<<2],nex[N<<2],ent;
int deep[N];
int fa[N];
int cicle;
int zhan[N],top;
int q[N],tail;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    deep[s]=deep[f]+1;
    fa[s]=f;
    int i;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f){continue;}
        if(cicle){break;}
        if(!deep[to[i]]){
            dfs(to[i],s);
        }
        else{
            cicle=1;
            int a = to[i],b = s;
            if(deep[a]<deep[b]){swap(a,b);}
            while(deep[a]>deep[b]){
                zhan[++top]=a;
                a = fa[a];
            }
            while(a!=b){
                zhan[++top]=a;
                q[++tail]=b;
                a = fa[a];
                b = fa[b];
            }
            zhan[++top]=a;
        }    
    }
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        adde(a,b+n);
        adde(b+n,a);
        adde(a+n,b);
        adde(b,a+n);
    }
    for(i=1;i<=n;i++){
        if(deep[i]==0){
            dfs(i,0);
            if(cicle){
                printf("YES\n%d\n",top+tail);
                for(a=1;a<=top;a++){
                    if(zhan[a]>n){zhan[a]-=n;}
                    printf("%d ",zhan[a]);
                }
                for(a=tail;a>=1;a--){
                    if(q[a]>n){q[a]-=n;}
                    printf("%d ",q[a]);
                }
                break;
            }
        }
    }
    if(!cicle){printf("NO");}
    return 0;
}
