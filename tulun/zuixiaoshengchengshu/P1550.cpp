#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct e{
    int u1;
    int u2;
    int w;
}g[100000];
int ent;
void adde(int a,int b,int w){
    ent++;
    g[ent].u1=a;
    g[ent].u2=b;
    g[ent].w=w;
}
bool bijiao(e a,e b){
    return a.w<b.w;
}
int fa[303];
int find_set(int x){
    if(fa[x]!=x){
        fa[x] = find_set(fa[x]);
    }
    return fa[x];
}
int main(){
    int n,i,j,a,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        adde(i,n+1,a);
        fa[i]=i;
    }
    fa[n+1]=n+1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a);
            adde(i,j,a);
        }
    }
    sort(g+1,g+ent+1,bijiao);
    for(a=1;a<=ent;a++){
        i = find_set(g[a].u1);
        j = find_set(g[a].u2);
        if(i!=j){
            ans+=g[a].w;
            fa[i]=j;
        }
    }
    cout<<ans;
    return 0;
}