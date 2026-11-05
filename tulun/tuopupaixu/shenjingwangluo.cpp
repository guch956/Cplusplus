#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=103;
ll C[N],U[N];
int head[N],to[N*N],nex[N*N],val[N*N],ent;
int rudu[N];
int chudu[N];
void adde(int u,int v,ll va){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    val[ent]=va;
    head[u]=ent;
}
int main(){
    int n,m,i,a,b,u;
    ll c;
    queue<int> q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&C[i],&U[i]);
        U[i]=-U[i];
    }
    while(m--){
        scanf("%d %d %lld",&a,&b,&c);
        chudu[a]++;rudu[b]++;
        adde(a,b,c);
    }
    for(i=1;i<=n;i++){if(rudu[i]==0){U[i]=C[i];q.push(i);}}
    while(q.size()){
        u = q.front();
        q.pop();
        if(U[u]<=0){continue;}
        for(i=head[u];i;i=nex[i]){
            U[to[i]]+=val[i]*U[u];
            rudu[to[i]]--;
            if(rudu[to[i]]==0){q.push(to[i]);}
        }
    }
    a = 0;
    for(i=1;i<=n;i++){
        if(chudu[i]==0 && U[i]>0){
            printf("%d %lld\n",i,U[i]);a++;
        }
    }
    if(a==0){printf("NULL");}
    return 0;
}