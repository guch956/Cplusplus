#include<iostream>
#include<cstdio>
#include<cstring>
#define ull unsigned long long
using namespace std;
const ull P=131;
const ull mod=2014;
ull dp[103][103];
char s[103];
ull hashzhi[103];
ull p[103];
ull get_hash(int l,int r){/*l+1至r*/
    return hashzhi[r]-p[r-l]*hashzhi[l];
}
int main(){
    int n,i,j,k,d;
    scanf("%s",s+1);
    n = strlen(s+1);
    p[0]=1;
    for(i=1;i<=n;i++){
        p[i]=p[i-1]*P;
        hashzhi[i]=P*hashzhi[i-1]+s[i];
    }
    for(d=1;d<n;d++){
        for(i=1;i<=n-d;i++){
            j = i+d;
            dp[i][j]=1;
            for(k=i;k<j;k++){
                if(2*k+1>i+j){
                    if(get_hash(k,j)==get_hash(i-1,i+j-1-k)){
                        dp[i][j]=(dp[i][j]+dp[i][k])%mod;
                    }
                    if(get_hash(k,j)==get_hash(2*k-j,k)){
                        dp[i][j]=(dp[i][j]+dp[i][k])%mod;
                    }
                }
                if(2*k+1<i+j){
                    if(get_hash(i-1,k)==get_hash(k,2*k-i+1)){
                        dp[i][j]=(dp[i][j]+dp[k+1][j])%mod;
                    }
                    if(get_hash(i-1,k)==get_hash(i+j-k-1,j)){
                        dp[i][j]=(dp[i][j]+dp[k+1][j])%mod;
                    }
                }
            }
        }
    }
    dp[1][n]=(dp[1][n]+mod-1)%mod;
    cout<<dp[1][n];
    return 0;
}
