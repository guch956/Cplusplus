#include<iostream>
#include<cstdio>
#define ll long long
const int N=100003;
int fa[N];
ll dis[N];
int find(int x){
    if(fa[x]!=x){
        int f=find(fa[x]);
        dis[x]+=dis[fa[x]];
        fa[x]=f;
    }
    return fa[x];
}
int main(){
    int n,i,q,t,x,y,a,b;
    ll v,ans;
    scanf("%d",&n);
    scanf("%d",&q);
    for(i=1;i<=n;i++){fa[i]=i;}
    while(q--){
        scanf("%d %d %d %lld",&i,&x,&y,&v);
        if(i==0){
            if(y&1){v = -v;}
            a = find(x);
            b = find(y);
            if(a!=b){
                fa[a]=y;
                dis[a]=v-dis[x];
            }
        }
        else{
            a = find(x);
            b = find(y);
            if(x&1){v = -v;}
            if(a!=b){
                printf("Ambiguous\n");
            }
            else{
                ans = dis[x]-dis[y]+v;
                if(y&1){ans = -ans;}
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
} 