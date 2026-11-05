#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node{
    ll d;
    ll p;
    bool operator<(const node & n)const{
        return d<n.d;
    }
};
node p[100003];
int main(){
    int n,i,num=1;
    ll ans=0,last;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&p[i].d,&p[i].p);
    }
    sort(p+1,p+n+1);
    q.push(p[1].p);
    ans+=p[1].p;
    for(i=2;i<=n;i++){
        last=0;
        if(num>=p[i].d){last = q.top();}
        if(p[i].p>last){
            ans+=p[i].p-last;
            q.push(p[i].p);
            if(last==0){
                num++;
            }
            else {
                q.pop();
            }
        }
        
    }
    printf("%lld",ans);
    return 0;
}