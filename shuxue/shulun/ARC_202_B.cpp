#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=400003;
const ll P=998244353;
ll jiec[N],ni[N];
void init(int n){
    ll i,k,r;
    jiec[0]=ni[0]=1;
    jiec[1]=ni[1]=1;
    for(i=2;i<=n;i++){
        jiec[i]=jiec[i-1]*i%P;
        r = P%i;
        k = (P-r)/i;
        ni[i]=(P-k)*ni[r]%P;
    }
    for(i=2;i<=n;i++){ni[i]=ni[i]*ni[i-1]%P;}
}
ll zuhe(int a,int b){
    return jiec[a]*ni[b]%P*ni[a-b]%P;
}
int gcd(int x,int y){
    if(y==0){return x;}
    return gcd(y,x%y);
}
int main(){
    int H,W,i,t;
    ll ans=0;
    scanf("%d %d",&H,&W);
    if(H&1){
        if(W&1){
            init(H);
            for(i=0;i<=H;i++){
                t = 2*i-H;
                if(gcd(W,(t%W+W)%W)==1){
                    ans+=zuhe(H,i);
                    ans%=P;
                }
            }
        }
        else{
            H = H<<1;
            init(H);
            for(i=0;i<=H;i++){
                t = 2*i-H;
                t = t/2;
                if(gcd(W/2,(t%W+W)%W)==1){
                    ans+=zuhe(H,i);
                    ans%=P;
                }
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
