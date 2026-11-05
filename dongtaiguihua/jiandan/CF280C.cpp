#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
double deep[N];
int nex[N<<1],head[N],to[N<<1];
int ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int i;
    deep[s]=deep[f]+1;
    for(i=head[s];i;i=nex[i]){
        if(to[i]==f)continue;
        dfs(to[i],s);
    }
}
int main(){
    int n,i,a,b;
    double ans=0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    for(i=1;i<=n;i++){
        ans = ans+(1/deep[i]);
    }
    printf("%.15lf",ans);
    return 0;
}