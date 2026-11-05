#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=500003;
int head[N],to[N],nex[N],ent;
int biaohao[N],num;
ll sum[N];
ll zhi[N];
int geshu[N];
int linshi[N];
int xin[N];
int zhan[N],top;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
ll gcd(ll a,ll b){
    if(b==0){return a;}
    return gcd(b,a%b);
}
int main(){
    int T,i,n,a,b,m,d;
    ll ans;
    scanf("%d",&T);
    geshu[0]=0x3f3f3f3f;
    while(T--){
        scanf("%d %d",&n,&m);
        ans=0;
        for(i=1;i<=n;i++){scanf("%lld",&zhi[i]);}
        for(i=1;i<=m;i++){
            scanf("%d %d",&a,&b);
            adde(a,b);
        }
        for(d=1;d<=n;d++){
            top=0;
            for(i=head[d];i;i=nex[i]){
                linshi[biaohao[to[i]]]++;
            }
            for(i=head[d];i;i=nex[i]){
                if(linshi[biaohao[to[i]]]>0 && linshi[biaohao[to[i]]]<geshu[biaohao[to[i]]]){
                    if(!xin[biaohao[to[i]]]){
                        xin[biaohao[to[i]]]=++num;
                        zhan[++top]=biaohao[to[i]];
                    }
                    linshi[biaohao[to[i]]]--;
                    geshu[biaohao[to[i]]]--;
                    biaohao[to[i]]=xin[biaohao[to[i]]];
                    geshu[biaohao[to[i]]]++;
                }
                else{linshi[biaohao[to[i]]]=0;}
            }
            for(i=1;i<=top;i++){xin[zhan[i]]=0;}
        }
        for(i=1;i<=n;i++){
            if(biaohao[i]){
                sum[biaohao[i]]+=zhi[i];
            }
        }
        for(i=1;i<=num;i++){
            ans = gcd(max(ans,sum[i]),min(ans,sum[i]));
            sum[i]=geshu[i]=0;
        }
        for(i=1;i<=n;i++){
            head[i]=biaohao[i]=0;
        }
        num=0;
        printf("%lld\n",ans);
    }
    return 0;
}