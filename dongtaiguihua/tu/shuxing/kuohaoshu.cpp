#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=500003;
struct {
    int next;
    int to;
}g[N<<1];
int ent,head[N];
ll zhan[N<<1];
int top=N;
bool kuohao[N];
ll ans[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs1(int s,int f){
    int v,i;
    ll a;
    if(kuohao[s]){
        top++;
        a = zhan[top];
        zhan[top]=1;
    }
    else{
        top--;
        ans[s] = zhan[top];
        a = zhan[top];
        zhan[top]++;
    }
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
    }
    zhan[top]=a;
    if(kuohao[s]){
        top--;
    }
    else{
        top++;
    }
}
void dfs2(int s,int f){
    int i,v;
    ans[s]+=ans[f];
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs2(v,s);
    }
}
int main(){
    int n,i,a,b;
    char c;
    ll ans1=0;
    scanf("%d\n",&n);
    for(i=1;i<=n;i++){
        scanf("%c",&c);
        if(c=='('){kuohao[i]=1;}
        else{kuohao[i]=0;}
    }
    for(i=2;i<=n;i++){
        scanf("%d",&a);
        adde(i,a);
        adde(a,i);
    }
    zhan[top]=1;
    dfs1(1,1);
    dfs2(1,1);
    for(i=1;i<=n;i++){
        ans1 = ans1^((ll)i*ans[i]);
    }
    printf("%lld",ans1);
    return 0;
}