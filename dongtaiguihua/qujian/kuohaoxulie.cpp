#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=503;
const ll P=1000000007;
int n,k;
char p[N];
ll dp[N][N][4];
int main(){
    int l,j,t,c,r;
    scanf("%d %d",&n,&k);
    scanf("%s",p+1);
    for(j=1;j<n;j++){
        for(l=1;l<=n-j;l++){
            r = l+j;
            if(p[l]=='(' || p[l]=='?'){
                if(p[r]==')' || p[r]=='?'){
                    dp[l][r][0]+=dp[l+1][r-1][1]+dp[l+1][r-1][2]+dp[l+1][r-1][3];
                    c = 0;
                    for(t=l+1;t<r;t++){
                        if(p[t]=='?' || p[t]=='*')c++;
                    }
                    if(c==j-1 && c<=k){
                        dp[l][r][0]++;
                    }
                    dp[l][r][0]%=P;
                }
            }
            for(t=l;t<r;t++){
                dp[l][r][3]+=dp[l][t][0]*(dp[t+1][r][1]+dp[t+1][r][3]);
                dp[l][r][3]%=P;
            }
            dp[l][r][3]=(dp[l][r][3]+dp[l][r][0])%P;
            for(t=l;t<r;t++){
                if(t-l>=k){break;}
                if(p[t]=='*' || p[t]=='?'){
                    dp[l][r][1]+=dp[t+1][r][3];
                }
                else{break;}
            }
            dp[l][r][1]%=P;
            for(t=r;t>l;t--){
                if(r-t>=k){break;}
                if(p[t]=='*' || p[t]=='?'){
                    dp[l][r][2]+=dp[l][t-1][3];
                }
                else{break;}
            }
            dp[l][r][2]%=P;
        }
    }
    printf("%lld",dp[1][n][3]);
    return 0;
}