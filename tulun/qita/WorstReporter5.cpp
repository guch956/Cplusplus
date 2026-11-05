#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;
int g[N][2];
int weizhi[N];
int edge[N][2];
bool adde(int x,int y){
    if(y==g[x][0] || y==g[x][1]){return 1;}
    if(!g[x][0]){
        g[x][0]=y;
        return 1;
    }
    if(!g[x][1]){
        g[x][1]=y;
        return 1;
    }
    return 0;
}
int zhan[N],top;
bool vis[N];
void dfs(int s,int f){
    zhan[++top]=s;
    vis[s]=1;
    int i;
    if(f==g[s][0] && g[s][1]){
        dfs(g[s][1],s);
    }
    if(f==g[s][1] && g[s][0]){
        dfs(g[s][0],s);
    }
}
int main(){
    int n,m,i,a,b;
    bool kexing=1;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&edge[i][0],&edge[i][1]);
    }
    for(i=1;i<=n;i++){
        weizhi[i]=i;
    }
    for(i=m;i>=1;i--){
        kexing=adde(weizhi[edge[i][0]],weizhi[edge[i][1]]);
        kexing=adde(weizhi[edge[i][1]],weizhi[edge[i][0]]);
        swap(weizhi[edge[i][0]],weizhi[edge[i][1]]);
    }
    if(kexing){
        for(i=1;i<=n;i++){
            if(!g[i][0]){
                zhan[++top]=i;
            }
            else if(!g[i][1]){
                if(!vis[i]){
                    dfs(i,0);
                }
            }
        }
        if(top==n){
            printf("Yes\n");
            for(i=1;i<=n;i++){
                printf("%d\n",zhan[i]);
            }
        }
        else{
            printf("No");
        }
    }
    else{
        printf("No");
    }
    return 0;
}