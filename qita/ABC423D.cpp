#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=300003;
struct node{
    ll leave;
    ll num;
    node(ll n,ll l){num=n;leave=l;}
    bool operator<(const node & n1)const{
        return leave>n1.leave;
    }
};
ll ti[N],stay[N],rens[N];
int main(){
    int n,i;
    ll k,now=0,t=0;
    node u(0,0);
    priority_queue<node> q;
    scanf("%d %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld %lld %lld",&ti[i],&stay[i],&rens[i]);
    }
    for(i=1;i<=n;i++){
        t = max(t,ti[i]);
        while(q.size()){
            u = q.top();
            if(u.leave<=t){
                now-=u.num;
                q.pop();
            }
            else{break;}
        }
        while(now+rens[i]>k){
            u = q.top();
            q.pop();
            now-=u.num;
            t = u.leave;
        }
        q.push(node(rens[i],t+stay[i]));
        now+=rens[i];
        printf("%lld\n",t);
    }
    return 0;
}