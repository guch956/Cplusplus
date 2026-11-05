#include<iostream>
#include<cstdio>
#define ll long long
const int N=100003;
ll val[N];
int weizhi[N];
int vis[N];
int ent[N];
int main(){
    int n,i,a;
    ll ans=0,mi,len,mii=N;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&val[i]);
        ans+=val[i];
        mii = std::min(mii,val[i]);
        ent[val[i]]=i;
    }
    len=0;
    for(i=1;i<=100000;i++){
        if(ent[i]){
            len++;
            weizhi[ent[i]]=len;
        }
    }
    for(i=1;i<=n;i++){
        if(!vis[i]){
            len=-2;
            mi=N;
            a = i;
            while(!vis[a]){
                vis[a]=1;
                len++;
                mi = std::min(mi,val[a]);
                a = weizhi[a];
            }
            ans+=std::min(len*mi,len*mii+3*mii+mi);
        }
    }
    printf("%lld",ans);
    return 0;
}