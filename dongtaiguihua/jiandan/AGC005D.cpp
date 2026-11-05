#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=2003;
const ll P=924844033;
ll jiec[N];
ll ni[N];
ll dp[N];
int fa[N<<1],siz[N<<1];
void init(int n){
    ll i,k,r;
    jiec[0]=jiec[1]=1;
    ni[0]=ni[1]=1;
    for(i=2;i<=n;i++){
        jiec[i]=jiec[i-1]*i%P;
        k = P/i;
        r = P%i;
        ni[i]=(P-k)*ni[r]%P;
    }
    for(i=2;i<=n;i++){
        ni[i]=ni[i]*ni[i-1]%P;
    }
}
inline ll C(int m,int n){
    return jiec[n]*ni[m]%P*ni[n-m]%P;
}
int find(int x){
    if(fa[x]!=x){fa[x]=find(fa[x]);}
    return fa[x];
}
void hebing(int x,int y){
    int a=find(x),b=find(y);
    fa[b]=a;
    siz[a]+=siz[b];
}
int main(){
    int n,k,i,num=0,j,t;
    ll ans=0,fuhao=1;
    scanf("%d %d",&n,&k);
    for(i=1;i<=2*(n-k);i++){
        fa[i]=i;
        siz[i]=1;
    }
    init(n);
    for(i=k+1;i<=n-k;i++){
        hebing(i-k,n-k+i);
    }
    for(i=k+1;i<=n-k;i++){
        hebing(n-2*k+i,i);
    }
    dp[0]=1;
    for(i=1;i<=2*(n-k);i++){
        if(fa[i]==i){
            for(j=n;j>=1;j--){
                for(t=1;t<=min(j,(siz[i]+1)>>1);t++){
                    dp[j]=(dp[j-t]*C(t,siz[i]+1-t)%P+dp[j])%P;
                }
            }
        }
    }
    for(j=0;j<=n;j++){
        ans = (fuhao*jiec[n-j]*dp[j]%P+ans+P)%P;
        fuhao=-fuhao;
    }
    printf("%lld",ans);
    return 0;
}