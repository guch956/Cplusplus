#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=5003;
int head[N],to[N*20],nex[N*20],ent;
int rudu[N];
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
int main(){
    int weiyi=0;
    int n,m,i,a,b;
    queue<int> q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        rudu[b]++;
    }
    for(i=1;i<=n;i++){if(rudu[i]==0)q.push(i);}
    while(q.size()){
        a = q.front();
        printf("%d\n",a);
        q.pop();
        if(q.size()){weiyi=1;}
        for(i=head[a];i;i=nex[i]){
            rudu[to[i]]--;
            if(rudu[to[i]]==0){q.push(to[i]);}
        }
    }
    printf("%d",weiyi);
    return 0;
}