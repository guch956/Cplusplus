#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=40000003;
const ll MOD=(1<<30)-1;
ll sum[N];
ll q[N];
ll p[N];
ll dp[N];
ll b[N];
int head,tail;
int n;
void jisuan(){
    int i;
    head=tail=0;
    q[0]=0;
    for(i=1;i<=n;i++){
        while(head<tail && p[q[head+1]]+sum[q[head+1]]<=sum[i]){
            head++;
        }
        p[i]=sum[i]-sum[q[head]];
        dp[i]=dp[q[head]]+(sum[i]-sum[q[head]])*(sum[i]-sum[q[head]]);
        while(head<=tail && p[i]+sum[i]<=p[q[tail]]+sum[q[tail]]){
            tail--;
        }
        q[++tail]=i;
    }
    printf("%lld",dp[n]);
}
int main(){
    int ty,i,m,last=0,s,j;
    ll a,x,y,z,l,r;
    scanf("%d %d",&n,&ty);
    if(ty==0){
        for(i=1;i<=n;i++){
            scanf("%lld",&a);
            sum[i]=sum[i-1]+a;
        }
    }
    else{
        scanf("%lld %lld %lld %lld %lld %d",&x,&y,&z,&b[1],&b[2],&m);
        for(j=1;j<=m;j++){
            scanf("%d %lld %lld",&s,&l,&r);
            for(i=last+1;i<=s;i++){
                if(i>=3){
                    b[i]=(x*b[i-1]+y*b[i-2]+z)&MOD;
                }
                a = (b[i]%(r-l+1))+l;
                sum[i]=sum[i-1]+a;
            }
            last=s;
        }
    }
    jisuan();
    for(i=1;i<=20;i++){
        printf("%lld\n",sum[i]);
    }
    return 0;
}