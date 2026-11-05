#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
ll d[N],t[N],st[N];
ll dp[N][2];
ll q[N];
int head,tail;
inline ll f(int j,int old){
    return dp[j][old]+st[j];
}
int main(){
    int n,m,p,i,j,now=1,old=0,k;
    ll h;
    scanf("%d %d %d",&m,&n,&p);
    for(i=2;i<=m;i++){
        scanf("%lld",&d[i]);
        d[i]=d[i]+d[i-1];
    }
    for(i=1;i<=n;i++){
        scanf("%d %lld",&j,&h);
        t[i]=h-d[j];
    }
    sort(t+1,t+n+1);
    for(i=1;i<=n;i++){
        st[i]=st[i-1]+t[i];
        dp[i][old]=i*t[i]-st[i];
    }
    for(k=2;k<=p;k++){
        head=tail=1;
        q[head]=0;
        for(i=1;i<=n;i++){
            while(head<tail && ((q[head+1]-q[head])*t[i])>=(f(q[head+1],old)-f(q[head],old))){
                head++;
            }
            dp[i][now]=f(q[head],old)-t[i]*q[head]+i*t[i]-st[i];
            while(head<tail && (f(i,old)-f(q[tail],old))*(q[tail]-q[tail-1])<=(f(q[tail],old)-f(q[tail-1],old))*(i-q[tail])){
                tail--;
            }
            q[++tail]=i;
            /*dp[i][now]=0x3f3f3f3f3f3f3f3f;
            for(j=0;j<i;j++){
                dp[i][now]=min(dp[i][now],dp[j][old]+i*t[i]-j*t[i]-st[i]+st[j]);
            }*/
        }
        swap(now,old);
    }
    printf("%lld",dp[n][old]);
    return 0;
}