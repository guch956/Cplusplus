#include<iostream>
#include<cstdio>
using namespace std;
const int N=5005;
const int INF=0x3f3f3f3f;
int dp[N];
int h[N];
int sum[N];
int main(){
    int i,j,n,s;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&h[i]);
    }
    for(i=1;i<=n;i++){
        s = h[i];
        for(j=i-1;j>=0;j--){
            if(s>=sum[j]){
                sum[i]=s;
                dp[i]=dp[j]+1;
                break;
            }
            s+=h[j];
        }
    }
    cout<<n-dp[n];
    return 0;
}
