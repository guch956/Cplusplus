#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node{
    ll x;
    ll t;
    bool operator<(const node & n)const{
        return x<n.x;
    }
}p[100003];
int main(){
    int n,i,ans=0,num=0;
    ll m,m0,sum=0;
    priority_queue<ll> q;
    scanf("%d %lld",&n,&m0);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&p[i].x,&p[i].t);
    }
    sort(p+1,p+n+1);
    for(i=1;i<=n;i++){
        q.push(p[i].t);
        num++;
        sum+=p[i].t;
        m = m0-p[i].x;
        if(m<0)break;
        while(sum>m){
            num--;
            sum-=q.top();
            q.pop();
        }
        ans = max(ans,num);
    }
    printf("%d",ans);
    return 0;
}