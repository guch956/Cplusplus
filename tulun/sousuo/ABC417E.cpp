#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1003;
int zhan[N],top;
int head[N],to[N*100],nex[N*100];
int ent;
bool shan[N];
bool vis[N];
int n;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void bfs(int sta){
    int i,u;
    queue<int> q;
    for(i=1;i<=n;i++){vis[i]=0;}
    vis[sta]=1;
    q.push(sta);
    while(q.size()){
        u = q.front();
        q.pop();
        for(i=head[u];i;i=nex[i]){
            if((!vis[to[i]]) && (!shan[to[i]])){
                vis[to[i]]=1;
                q.push(to[i]);
            }
        }
    }
}
int main(){
    int T,i,m,a,b,s,t,c;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d %d",&n,&m,&s,&t);
        top=0;
        while(m--){
            scanf("%d %d",&a,&b);
            adde(a,b);
            adde(b,a);
        }
        zhan[top]=s;shan[s]=1;
        while(1){
            bfs(t);
            c = n+1;
            for(i=head[s];i;i=nex[i]){
                if(vis[to[i]]==1 && to[i]<c){
                    c = to[i];
                }
            }
            zhan[++top]=c;
            shan[c]=1;
            if(c==t){break;}
            s = c;
        }
        for(i=0;i<=top;i++){
            printf("%d ",zhan[i]);
        }
        printf("\n");
        for(i=1;i<=n;i++){
            head[i]=0;
            shan[i]=0;
        }
        ent=0;
    }
    return 0;
}