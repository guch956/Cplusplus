#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=(1<<20)+3;
ll A[23];
ll ziji[N],num[N];
ll dp[N][2];
ll linshi[20];
ll gcd(ll x ,ll y){
    if(y==0){return x;}
    return gcd(y,x%y);
}
int get(ll x){
    int l=0;
    while(x){
        linshi[++l]=x%10;
        x = x/10;
    }
    return l;
}
ll check(ll a,ll b,ll y){
    ll s=0;
    int k=get(b);
    while(k){
        s = s*10+linshi[k]*a;
        if(s>y){return -1;}
        k--;
    }
    return s;
}
int main(){
    int n,m,i,j=0,k=1,t,now,old;
    ll y,ans=0,a;
    scanf("%d %d %lld",&n,&m,&y);
    t = 1<<n;
    for(i=0;i<n;i++){
        scanf("%lld",&A[i]);
    }
    num[0]=y;
    ziji[0]=1;
    for(i=1;i<t;i++){
        if(i==k*2){
            k = i;
            j++;
        }
        old = 1<<j;
        if(ziji[i-old]==-1){
            ziji[i]=-1;
            num[i]=0;
        }
        else{
            a = gcd(A[j],ziji[i-old]%A[j]);
            a = A[j]/a;
            a = check(a,ziji[i-old],y);
            if(a<0){ziji[i]=-1;}
            else{
                ziji[i]=a;
                num[i]=y/ziji[i];
            }
        }
        dp[i][0]=num[i];
    }
    now=1;old=0;
    for(k=n-1;k>=0;k--){
        j = 1<<k;
        for(i=0;i<t;i++){
            if(i&j){
                dp[i][now]=dp[i][old];
            }
            else{
                dp[i][now]=dp[i][old]-dp[i+j][old];
            }
        }
        swap(now,old);
    }
    for(i=0;i<t;i++){
        j = i;
        k = 0;
        while(j){
            if(j&1){k++;}
            j = j>>1;
        }
        if(k==m){
            ans+=dp[i][old];
        }
    }
    printf("%lld",ans);
    return 0;
}