#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll P=1e9+7;
const int N=5003;
ll dp1[N];
ll dp2[N];
ll p[N];
int zhongl[N];
ll num[30];
ll quick(ll a,ll x){
    ll an=1;
    while(x){
        if(x&1){an = (an*a)%P;}
        a = (a*a)%P;
        x = x>>1;
    }
    return an;
}
int main(){
    int n,m,k,i,j;
    scanf("%d %d %d",&n,&m,&k);
    char c;
    ll ans=1,sum;
    for(i=1;i<=n;i++){
        scanf("%d %d",&p[i],&zhongl[i]);
    }
    dp1[0]=1;
    for(i=1;i<k;i++){
        for(j=1;j<=n;j++){
            if(p[j]<=i){
                dp1[i]+=dp1[i-p[j]];
                dp1[i]%=P;
            }
        }
    }
    for(i=1;i<=n;i++){
        dp2[zhongl[i]]+=dp1[k-p[i]];
        dp2[zhongl[i]]%=P;
    }
    for(i=1;i<=m;i++){
        cin>>c;
        num[c-'A']++;
    }
    for(i=0;i<26;i++){
        if(num[i]){
            sum=0;
            for(j=1;j<=n;j++){
                sum+=quick(dp2[j],num[i]);
            }
            sum%=P;
            ans = (ans*sum)%P;
        }
    }
    printf("%lld",ans);
    return 0;
}