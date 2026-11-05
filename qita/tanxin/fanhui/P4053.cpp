#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
class node{
public:
    ll ti;
    ll end;
    bool operator<(const node & n1)const{
        return end<n1.end;
    }
}p[150004];
int main(){
    int n,i,ans=0;
    ll now=0;
    priority_queue<int> q;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&p[i].ti,&p[i].end);
    }
    sort(p+1,p+n+1);
    for(i=1;i<=n;i++){
        if(now+p[i].ti<=p[i].end){
            ans++;
            now = now+p[i].ti;
            q.push(p[i].ti);
        }
        else{
            if(q.top()>p[i].ti){
                now = now+p[i].ti-q.top();
                q.pop();
                q.push(p[i].ti);
            }
        }
    }
    printf("%d",ans);
    return 0;
}