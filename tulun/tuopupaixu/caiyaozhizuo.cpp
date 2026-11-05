#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=100003;
int head[N],to[N],nex[N],ent;
int rudu[N];
int shunxu[N];
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
int main(){
    int T,n,m,num,a,b,i,u;
    scanf("%d",&T);
    while(T--){
        num=0;
        priority_queue<int> q;
        scanf("%d %d",&n,&m);
        memset(rudu,0,sizeof(rudu));
        memset(head,0,sizeof(head));
        ent=0;
        while(m--){
            scanf("%d %d",&a,&b);
            adde(b,a);
            rudu[a]++;
        }
        for(i=1;i<=n;i++){if(rudu[i]==0)q.push(i);}
        while(q.size()){
            u = q.top();
            shunxu[++num]=u;
            q.pop();
            for(i=head[u];i;i=nex[i]){
                rudu[to[i]]--;
                if(rudu[to[i]]==0){q.push(to[i]);}
            }
        }
        if(num==n){
            for(i=n;i>=1;i--){printf("%d ",shunxu[i]);}
        }
        else{printf("Impossible!");}
        printf("\n");
    }
    return 0;
}
