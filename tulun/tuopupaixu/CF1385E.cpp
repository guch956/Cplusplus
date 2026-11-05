#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=200003;
int head[N],nex[N],to[N],ent;
int rudu[N];
int vis[N];
int wuxiang[N][2],top;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int tuopu(int n){
    int i,nu=0,u;
    queue<int> q;
    for(i=1;i<=n;i++){
        if(rudu[i]==0)q.push(i);
    }
    while(q.size()){
        u = q.front();
        vis[u]=++nu;
        q.pop();
        for(i=head[u];i;i=nex[i]){
            rudu[to[i]]--;
            if(rudu[to[i]]==0)q.push(to[i]);
        }
    }
    if(nu==n){return 1;}
    else{return 0;}
}
int main(){
    int t,n,m,i,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d %d",&i,&a,&b);
            if(i==1){
                adde(a,b);
                rudu[b]++;
            }
            else{
                wuxiang[++top][0]=a;
                wuxiang[top][1]=b;
            }
        }
        if(tuopu(n)){
            printf("YES\n");
            for(a=1;a<=n;a++){
                for(i=head[a];i;i=nex[i]){
                    printf("%d %d\n",a,to[i]);
                }
            }
            for(i=1;i<=top;i++){
                if(vis[wuxiang[i][0]]>vis[wuxiang[i][1]]){
                    swap(wuxiang[i][0],wuxiang[i][1]);
                }
                printf("%d %d\n",wuxiang[i][0],wuxiang[i][1]);
            }
        }
        else{printf("NO\n");}
        for(i=1;i<=n;i++){
            head[i]=rudu[i]=0;
        }
        ent=0;
        top=0;
    }
    return 0;
}