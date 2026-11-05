#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=100003;
int c[N<<1];
int main(){
    int sum=0,j,i,n,s;
    ll ans=0;
    queue<ll> q;
    scanf("%d",&n);
    s = n+1;
    for(i=1;i<=n;i++){
        scanf("%d",&c[i]);
        c[i+n]=c[i];
        sum+=c[i]-1;
        if(sum<=s){
            s = sum;
            j = i;
        }
    }
    j++;
    for(i=j;i<j+n;i++){
        while(c[i]){
            q.push(i);
            c[i]--;
        }
        ans+=(i-q.front())*(i-q.front());
        q.pop();
    }
    printf("%lld",ans);
    return 0;
}
