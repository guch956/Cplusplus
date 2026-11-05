#include<iostream>
#include<algorithm>
const int INF=0x3f3f3f3f;
const int N=4000;
int dp[N];
struct node{
    int t;
    int start;
    int h;
}p[N];
bool bijiao(node n1,node n2){
    return n1.start<n2.start;
}
int H;
int main(){
    using namespace std;
    int n,m,i,j;
    cin>>H>>n;
    for(i=1;i<=n;i++){
        cin>>p[i].start>>p[i].t>>p[i].h;
    }
    sort(p+1,p+n+1,bijiao);
    for(i=11;i<N;i++){
        dp[i]=-INF;
    }
    for(i=1;i<=n;i++){
        for(j=N-1;j>=p[i].start;j--){
            if(j<p[i].start+p[i].t){
                dp[j]=max(dp[j]+p[i].h,dp[p[i].start]);
            }
            else{
                dp[j]=max(dp[j]+p[i].h,dp[j-p[i].t]);
            }
        }
    }
    for(i=1;i<N;i++){
        if(dp[i]>=H){
            cout<<i;
            return 0;
        }
    }
    for(i=0;i<N;i++){
        if(dp[i+1]<0){
            cout<<i;
            return 0;
        }
    }
}