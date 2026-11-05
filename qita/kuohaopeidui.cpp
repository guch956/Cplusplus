#include<iostream>
#include<string>
int main(){
    using namespace std;
    int n,A[101],dp[101][101],i,j,k,a;
    string s;
    cin>>s;
    n = s.size();
    for(i=0;i<n;i++){
        if(s[i]=='('){
            A[i]=1;
        }
        else if(s[i]=='['){
            A[i] = 2;
        }
        else if(s[i]==']'){
            A[i] = 3;
        }
        else{
            A[i] = 4;
        }
    }
    for(i=1;i<n;i++){
        dp[i][i] = 1;
        dp[i][i-1]=0;
    }
    dp[n][n-1]=0;
    dp[0][0] = 1;
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            a = i+j;
            if(A[j]==3 || A[j]==4){
                dp[j][a] = dp[j+1][a]+1; 
            }
            else{
                dp[j][a] = 2147483647;
                for(k=j+1;k<=a;k++){
                    if(A[j]+A[k]==5){
                        dp[j][a] = min(dp[j][a],dp[j+1][k-1]+dp[k+1][a]);
                    }
                }
                for(k=j;k<=a;k++){
                    dp[j][a] = min(dp[j][a],dp[j+1][k]+dp[k+1][a]+1);
                }
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}