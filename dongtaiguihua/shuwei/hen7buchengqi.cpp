#include<iostream>
#define ll long long
using namespace std;
const ll P=1000000007;
ll p10p[42],p107[42];
ll dp[22][7][7][3];
ll num[22];
ll solve(ll x){
    int len=0,i,j;
    ll ans=0,last10=0,last=0;
    ll a,b;
    while(x){
        num[++len]=x%10;
        x = x/10;
    }
    for(i=len;i;i--){
        last10 = (10*last10+num[i]*p10p[len-1])%P;
        last += num[i];
        for(j=0;j<num[i];j++){
            if(j==7){continue;}
            a = (last10-(p107[i-1]*j)+56)%7;
            b = (last-j+14)%7;
            ans+=((last10*last10)%P)*dp[i-1][a][b][0];
            ans%=P;
            ans+=2*last10*dp[i-1][a][b][1];
            ans%=P;
            ans+=dp[i-1][a][b][2];
            ans%=P;
        }
        if(num[i]==7){break;}
    }
    if(i==0){ans=(ans+last10)%P;}
    return ans;
}
int main(){
    int i,j,pos,n,t;
    ll a,b;
    p107[0]=p10p[0]=1;
    for(i=1;i<=41;i++){
        p107[i]=(p107[i-1]*10)%7;
        p10p[i]=(p10p[i-1]*10)%P;
    }
    for(i=1;i<=6;i++){
        for(j=1;j<=6;j++){
            dp[0][i][j][0]=1;
        }
    }
    for(pos=1;pos<=19;pos++){
        for(i=0;i<=6;i++){
            for(j=0;j<=6;j++){
                for(n=0;n<=9;n++){
                    a = (i-(p107[pos-1]*n)+56)%7;
                    b = (j-n+14)%7;
                    if(n!=7){
                        dp[pos][i][j][0]+=dp[pos-1][a][b][0];
                        dp[pos][i][j][0]%=P;
                        dp[pos][i][j][1]+=p10p[pos-1]*n*dp[pos-1][a][b][0];
                        dp[pos][i][j][1]%=P;
                        dp[pos][i][j][1]+=dp[pos-1][a][b][1];
                        dp[pos][i][j][2]+=p10p[2*pos-2]*n*n*dp[pos-1][a][b][0];
                        dp[pos][i][j][2]%=P;
                        dp[pos][i][j][2]+=2*p10p[pos-1]*t*dp[pos-1][a][b][1];
                        dp[pos][i][j][2]%=P;
                        dp[pos][i][j][2]+=dp[pos-1][a][b][2];
                        dp[pos][i][j][2]%=P;
                    }
                }
            }
        }
    }
    scanf("%d",&t);
    while(t--){
        cin>>a>>b;
        cout<<solve(b)-solve(a-1)<<endl;
    }
    return 0;
}