#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const ll INF=9223372036854775807;
const int N=100003;
ll vis[N];
int main(){
    ll h,ans=0,a;
    int x,y,z,i,u,d;
    deque<int> q;
    scanf("%lld %d %d %d",&h,&x,&y,&z);
    if(z<x){swap(x,z);}
    if(z<y){swap(y,z);}
    for(i=2;i<z;i++){vis[i]=INF;}
    vis[0]=INF;
    q.push_front(1);
    while(q.size()){
        u = q.front();
        q.pop_front();
        i = (u+x)%z;
        d = u+x>=z?vis[u]+1:vis[u];
        if(d<vis[i]){
            vis[i]=d;
            if(d==vis[u]){q.push_front(i);}
            else{q.push_back(i);}
        }
        i = (u+y)%z;
        d = u+y>=z?vis[u]+1:vis[u];
        if(d<vis[i]){
            vis[i]=d;
            if(d==vis[u]){q.push_front(i);}
            else{q.push_back(i);}
        }
    }
    for(i=0;i<z;i++){
        if(i>h){break;}
        if(vis[i]<INF){
            a = (h-i)/z;
            if(a>=vis[i]){
                ans+=a-vis[i]+1;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}