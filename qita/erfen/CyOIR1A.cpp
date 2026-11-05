#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1000003;
const ll P=998244353;
ll jisuan[N];
ll paixu[N];
ll jiec[N*10];
ll ni[N*10];
double num[N];
bool bijiao(ll a,ll b){
    return ((ll)num[a]+1-jisuan[a])*jisuan[b]<((ll)num[b]+1-jisuan[b])*jisuan[a];
}
void init(int n){
    ll i,k,r;
    jiec[0]=ni[0]=1;
    jiec[1]=ni[1]=1;
    for(i=2;i<=n;i++){
        k = P/i;
        r = P%i;
        ni[i]=(P-k)*ni[r]%P;
    }
    for(i=2;i<=n;i++){
        jiec[i]=jiec[i-1]*i%P;
        ni[i]=ni[i-1]*ni[i]%P;
    }
}
ll C(int n,int m){
    return jiec[n]*ni[m]%P*ni[n-m]%P;
}
int main(){
    int m,i,j;
    ll k,sum,ans=1,a;
    double l=0,r=0,mid;
    scanf("%d %lld",&m,&k);
    for(i=1;i<=m;i++){
        scanf("%lf",&num[i]);
        r = max(r,num[i]);
    }
    init(r+2);
    for(i=1;i<=60;i++){
        mid = (l+r)/2;
        sum = 0;
        for(j=1;j<=m;j++){
            sum += (ll)((num[j]+1)/(mid+1));
        }
        if(sum<k){r=mid;}
        else{l=mid;}
    }
    sum=0;
    for(i=1;i<=m;i++){
        jisuan[i] = (int)((num[i]+1)/(l+1));
        sum = sum+jisuan[i];
        paixu[i]=i;
    }
    sum = sum-k;
    sort(paixu+1,paixu+m+1,bijiao);
    for(i=1;i<=sum;i++){jisuan[paixu[i]]--;}
    for(i=1;i<=m;i++){
        ans=ans*C(num[i],jisuan[i])%P;
    }
    printf("%lld",ans);
    return 0;
}
