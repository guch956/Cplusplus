#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
ll p[300003];
int main(){
    int n,i;
    ll ans=0,a;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&p[i]);
    }
    q.push(p[1]);
    for(i=2;i<=n;i++){
        a = q.top();
        if(p[i]>a){
            ans+=p[i]-a;
            q.pop();
            q.push(p[i]);
        }
        q.push(p[i]);
    }
    printf("%lld",ans);
    return 0;
}