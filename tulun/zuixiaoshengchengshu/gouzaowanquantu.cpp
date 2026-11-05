#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
struct e{
    int u1;
    int u2;
    ll w;
}g[N];
int f[N];
ll siz[N];
bool bijiao(e & g1, e & g2){
    return g1.w<g2.w;
}
int find_set(int x){
    if(x!=f[x]){
        f[x] = find_set(f[x]);
    }
    return f[x];
}
int main(){
    int n,i,a,b;
    ll ans=0;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        scanf("%d %d %lld",&g[i].u1,&g[i].u2,&g[i].w);
        ans+=g[i].w;
        f[i]=i;
        siz[i]=1;
    }
    f[n]=n;siz[n]=1;
    sort(g+1,g+n,bijiao);
    for(i=1;i<n;i++){
        a = find_set(g[i].u1);
        b = find_set(g[i].u2);
        ans+=(siz[a]*siz[b]-1)*(g[i].w+1);
        f[a]=b;
        siz[b]+=siz[a];
    }
    cout<<ans;
    return 0;
}
