#include<iostream>
#include<string>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[2010][2010];
int jia[30];
string s;
int main(){
    int m,n,i,j,k,a;
    char c;
    cin>>m>>n;
    cin>>s;
    for(i=0;i<m;i++){
        cin>>c>>a>>j;
        jia[c-'a']=min(a,j);
    }
    for(i=2;i<=n;i++){
        for(j=0;j<=n-i;j++){
            k = i+j-1;
            dp[j][k]=INF;
            if(s[j]==s[k]){
                dp[j][k]=dp[j+1][k-1];
            }
            dp[j][k]=min(dp[j][k],dp[j+1][k]+jia[s[j]-'a']);
            dp[j][k]=min(dp[j][k],dp[j][k-1]+jia[s[k]-'a']);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}