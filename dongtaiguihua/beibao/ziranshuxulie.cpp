#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=5003;
const ll P=998244353;
ll dp[N];
ll A[N];
int xianzhi[10][2];
ll solve(int x,int k){
    int y,i,m=1<<k,j,a,b;
    ll ans=0,an;
    for(i=0;i<m;i++){
        y = x;
        a = 0;
        b = i;
        for(j=0;j<k;j++){
            y-=A[xianzhi[j][0]]*xianzhi[j][1];
            if(b&1){
                y-=A[xianzhi[j][0]];
                a++;
            }
            b = b>>1;
        }
        an = y<0?0:dp[y];
        if(a&1){ans = (ans-an+P)%P;}
        else{ans = (ans+an)%P;}
    }
    return ans;
}
int main(){
    int n,i,q,l,r,k,j;
    ll s;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){scanf("%lld",&A[i]);}
    for(i=0;i<=5000;i++){dp[i]=1;}
    for(i=1;i<=n;i++){
        for(j=0;j<A[i];j++){
            s=0;
            for(k=j;k<=5000;k+=A[i]){
                s+=dp[k];
                s%=P;
                dp[k]=s;
            }
        }
    }
    while(q--){
        scanf("%d %d %d",&l,&r,&k);
        for(i=0;i<k;i++){
            scanf("%d %d",&xianzhi[i][0],&xianzhi[i][1]);
        }
        printf("%lld\n",(P+solve(r,k)-solve(l-1,k))%P);
    }
    return 0;
}
