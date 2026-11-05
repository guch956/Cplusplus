#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll P=1e5+3;
ll dp[2003];
int main(){
    int a,b,c,d,k,i,j;
    cin>>a>>b>>c>>d>>k;
    dp[0]=1;
    for(i=1;i<=b;i++){
        for(j=a;j>=1;j--){
            dp[j] = ((a-j+1)*dp[j-1]+dp[j])%P;
        }
    }
    a = a+c;
    for(i=1;i<=d;i++){
        for(j=a;j>=1;j--){
            dp[j] = ((a-j+1)*dp[j-1]+dp[j])%P;
        }
    }
    cout<<dp[k];
    return 0;
}