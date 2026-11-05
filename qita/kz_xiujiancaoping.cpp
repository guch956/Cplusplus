#include<iostream>
long long dp[100004],q[100004],s[100004],ds[100004];
int head=0,tail=1,n,k;
void push(int j){
    ds[j]=s[j]-dp[j-1];
    while(head <tail && ds[j]<=ds[q[tail-1]]){
        tail--;
    }
    q[tail]=j;
    tail++;
    while(q[head]<j-k){
        head++;
    }
    dp[j]=s[j]-ds[q[head]];
}
int main(){
    using namespace std;
    freopen("3.in","r",stdin);
    int i,a;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a;
        s[i]=s[i-1]+a;
    }
    for(i=1;i<=n;i++){
        push(i);
    }
    cout<<dp[n];
    return 0;
}