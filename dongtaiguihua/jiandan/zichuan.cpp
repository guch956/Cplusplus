#include<iostream>
#include<string>
#define ll long long
using namespace std;
ll P=1000000007;
ll dp[1003][203][2];
int main(){
    string sn,sm;
    int m,n,i,j,k,t,d,now=1,old=0;
    cin>>n>>m>>k;
    cin>>sn>>sm;
    for(j=1;j<=m;j++){
        for(i=1;i<=n;i++){
            dp[i][j][old]=dp[i-1][j][old];
            d=1;
            while(d<=i && d<=j && sn[i-d]==sm[j-d]){
                dp[i][j][now]+=dp[i-d][j-d][old];
                d++;
            }
            if(d==j+1){
                dp[i][j][old]++;
            }
        }
    }
    for(t=2;t<=k;t++){
        for(j=1;j<=m;j++){
            for(i=1;i<=n;i++){
                d = 1;
                dp[i][j][now]=dp[i-1][j][now];
                while(d<=i && d<=j && sn[i-d]==sm[j-d]){
                    dp[i][j][now]+=dp[i-d][j-d][old];
                    d++;
                }
                dp[i][j][now]=(dp[i][j][now]%P);
            }
        }
        swap(old,now);
    }
    cout<<dp[n][m][old];
    return 0;
}


