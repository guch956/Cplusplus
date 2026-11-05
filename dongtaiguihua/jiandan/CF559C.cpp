#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll jiecheng[200003];
ll ni[200003];
const ll P=1e9+7;
int point[2003][2];
ll dp[2003];
int n,h,w;
void init(int n){
    ll k,i,r;
    jiecheng[0]=1;
    ni[0]=1;
    jiecheng[1]=1;
    ni[1]=1;
    for(i=2;i<=n;i++){
        jiecheng[i] = jiecheng[i-1]*i%P;
        r = P%i;
        k = P/i;
        ni[i] = (P-k)*ni[r]%P;
    }
    for(i=2;i<=n;i++){
        ni[i] = ni[i]*ni[i-1]%P;
    }
}
ll zuhe(int n,int m){
    return jiecheng[n]*ni[m]%P*ni[n-m]%P;
}
void dfs(int m){
    int i;
    dp[m] = zuhe(h-point[m][0]+w-point[m][1],h-point[m][0]);
    for(i=1;i<=n;i++){
        if(i==m)continue;
        if(point[i][0]>=point[m][0] && point[i][1]>=point[m][1]){
            if(dp[i]==-1){dfs(i);}
            dp[m] = (dp[m]-(zuhe(point[i][0]+point[i][1]-point[m][0]-point[m][1],point[i][0]-point[m][0])*dp[i]%P)+P)%P;
        }
    }
}
int main(){
    int i;
    scanf("%d %d %d",&h,&w,&n);
    point[0][0]=point[0][1]=1;
    dp[0]=-1;
    init(h+w);
    for(i=1;i<=n;i++){
        dp[i]=-1;
        scanf("%d %d",&point[i][0],&point[i][1]);
    }
    dfs(0);
    printf("%lld",dp[0]);
    return 0;
}