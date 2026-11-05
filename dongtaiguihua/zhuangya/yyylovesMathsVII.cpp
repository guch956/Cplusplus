#include<iostream>
#define ll long long
const int N=(1<<24)+3;const ll mod=10e9+7;
ll dp[N];
ll zhi[N];
ll p[26];
int main(){
    using namespace std;
    int n,m,a=-1,b=-1,i,j,k,c;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    cin>>m;
    if(m==1){cin>>a;}
    if(m==2){cin>>a>>b;}
    dp[0]=1;
    for(i=1;i<=(1<<n)-1;i++){
        c = 1;
        k=0;
        while(c<=i){
            if(c&i){
                if(zhi[i]==0){
                    zhi[i]=zhi[i-c]+p[k];
                }
                dp[i]+=dp[i-c];
                dp[i]=dp[i]%mod;
            }   
            c=c<<1;
            k++;
        }
        if(zhi[i]==a || zhi[i]==b){
            dp[i]=0;
        }
    }
    cout<<dp[(1<<n)-1];
    return 0;
}