#include<iostream>
int s[200004],q[200004],dp[200004],head=0,tail=1,n,m;
void push(int j){
    while(q[head]<j-m){
        head++;
    }
    dp[j]=s[j]-s[q[head]];
    while(head<tail && s[j]<=s[q[tail-1]]){
        tail--;
    }
    q[tail]=j;
    tail++;
}
int main(){
    using namespace std;
    int i,a,ans=-2147483647;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a;
        s[i] = s[i-1]+a; 
    }
    for(i=1;i<=n;i++){
        push(i);
    }
    for(i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}