#include<iostream>
#include<string>
int dp[53][53];
int main(){
    using namespace std;
    int n,i,j,k,a,m;
    string s;
    cin>>s;
    n = s.size();
    for(i=0;i<n;i++){
        dp[i][i] = 1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            a = j+i;
            if(s[j]==s[a]){
                dp[j][a] = dp[j+1][a];
            }
            else{
                m = 999999;
                for(k=j;k<a;k++){
                    m = min(m,dp[j][k]+dp[k+1][a]);
                }
                dp[j][a] = m;
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}