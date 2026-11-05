#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll P=353442899;
ll p2[200];
ll dp[70];
ll n2=(P+1)/2;
ll solve(ll x){
    if(x==0){return 0;}
    if(x==1){return 1;}
    ll i=0,a=1,ans=0;
    while(2*a<=x){
        i++;
        a=a<<1;
    }
    ans=dp[i];
    if(2*x<3*a){
        ans+=((((x-p2[i]+1)%P)*((x+p2[i])%P)%P)*n2)%P;
        ans+=((x-p2[i]+1)%P)*((i+1-p2[i-1]+P)%P)%P;
    }
    else{
        ans+=n2*(p2[2*i]+p2[2*i-2]-p2[i-1]+P)%P;
        ans+=p2[i-1]*(i+1-p2[i-1]+P)%P;
        ans+=(p2[i]+i+1)*((x-a-(a>>1)+1)%P)%P;
    }
    return ans%P;
}
int main(){
    ll i,a,b;
    int T;
    p2[0]=1;
    for(i=1;i<200;i++){
        p2[i]=p2[i-1]*2%P;
    }
    dp[1]=1;
    dp[2]=8;
    for(i=3;i<70;i++){
        dp[i]=(dp[i-1]+p2[2*i-2]-p2[2*i-5]-p2[i-3]+i*p2[i-1]+P*2)%P;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",(solve(b)-solve(a-1)+P)%P);
    }
    return 0;
}