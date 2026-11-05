#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=301;
const ll P=1000000007;
int numA[20];
int numB[20];
int dp[N][N][19][19][2];
int dpB[N][N][2];
int dpA[N][N][2];
int f[N][N];
int A[N];
int n;
void jisuan(int (*dp1)[301][2],int len,int *num){
    int i,j,l,r,d;
    for(i=1;i<=n;i++){
        for(l=0;l<len;l++){
            dp[i][i][l][l][0]=A[i]<=num[l]?2:0;
            dp[i][i][l][l][1]=A[i]<num[l]?2:0;
        }
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            for(l=0;l<len;l++){
                dp[i][j][l][l][0]=dp[i][j-1][l][l][0];
                dp[i][j][l][l][1]=dp[i][j-1][l][l][1];
                dp[i][j][l][l][0]+=A[j]<=num[l]?2:0;
                dp[i][j][l][l][0]%=P;
                dp[i][j][l][l][1]+=A[j]<num[l]?2:0;
                dp[i][j][l][l][1]%=P;
                for(r=l+1;r<len;r++){
                    dp[i][j][l][r][0]=dp[i][j-1][l][r][0];
                    dp[i][j][l][r][1]=dp[i][j-1][l][r][1];
                    if(A[j]==num[r]){
                        dp[i][j][l][r][0]+=dp[i][j-1][l][r-1][0];
                        dp[i][j][l][r][0]%=P;
                        dp[i][j][l][r][1]+=dp[i][j-1][l][r-1][1];
                        dp[i][j][l][r][1]%=P;
                    }
                    else if(A[j]<num[r]){
                        dp[i][j][l][r][0]+=f[j-i][r-l];
                        dp[i][j][l][r][0]%=P;
                        dp[i][j][l][r][1]+=f[j-i][r-l];
                        dp[i][j][l][r][1]%=P;
                    }
                    dp[i][j][l][r][0]+=A[j]<=num[l]?dp[i][j-1][l+1][r][0]:dp[i][j-1][l+1][r][1];
                    dp[i][j][l][r][1]+=A[j]<num[l]?dp[i][j-1][l+1][r][0]:dp[i][j-1][l+1][r][1];
                    dp[i][j][l][r][0]%=P;
                    dp[i][j][l][r][1]%=P;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            dp1[i][j][0]=dp[i][j][0][len-1][0];
            dp1[i][j][1]=dp[i][j][0][len-1][1];
        }
    }
}
int main(){
    ll a,b;
    int ans;
    int lenA=0,lenB=0,i,j,q;
    scanf("%d %lld %lld",&n,&a,&b);
    while(a){
        numA[lenA]=a%10;
        lenA++;
        a = a/10;
    }
    while(b){
        numB[lenB]=b%10;
        lenB++;
        b = b/10;
    }
    f[0][0]=1;
    for(i=1;i<=n;i++){
        f[i][0]=1;
        scanf("%d",&A[i]);
    }
    for(j=1;j<=n;j++){
        for(i=j;i<=n;i++){
            f[i][j]=((2*f[i-1][j-1])%P+f[i-1][j])%P;
        }
    }
    jisuan(dpA,lenA,numA);
    jisuan(dpB,lenB,numB);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            f[i][j]=(f[i][j]+f[i][j-1])%P;
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&i,&j);
        ans=((dpB[i][j][0]+f[j-i+1][lenB-1])%P-(dpA[i][j][1]+f[j-i+1][lenA-1])%P+P)%P;
        printf("%d\n",ans);
    }
    return 0;
}
