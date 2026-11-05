#include<iostream>
int A[202],q[202],head=0,tail=1,dp[202],n,m;
void push(int j){
    while(q[head]<j-m){
        head++;
    }
    dp[j]=A[j]+dp[q[head]];
    while(head<tail && dp[j]<=dp[q[tail-1]]){
        tail--;
    }
    q[tail]=j;
    tail++;
}
int main(){
    using namespace std;
    int i,s=2147483647;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>A[i];
    }
    for(i=1;i<=n;i++){
        push(i);
    }
    for(i=n-m+1;i<=n;i++){
        s = min(s,dp[i]);
    }
    cout<<s;
    return 0;
}