#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=200003;
ll A[N];
ll ma[N];
int fa[N];
int du[N];
int paixu[N];
int main(){
    int n,i,b,m=0,top,u;
    ll ans=0;
    queue<int> q;
    scanf("%d",&n);
    top = n;
    for(i=1;i<=n;i++){scanf("%lld",&A[i]);}
    for(i=1;i<=n;i++){
        scanf("%d",&b);
        fa[i]=b;
        if(b!=-1){du[b]++;}
    }
    for(i=1;i<=n;i++){if(du[i]==0)q.push(i);}
    while(q.size()){
        u = q.front();
        q.pop();
        ans+=A[u];
        if(A[u]>=0){
            if(fa[u]!=-1)A[fa[u]]+=A[u];
            paixu[++m]=u;}
        else{paixu[top--]=u;}
        if(fa[u]!=-1){
            du[fa[u]]--;
            if(du[fa[u]]==0){
                q.push(fa[u]);
            }
        }
    }
    printf("%lld\n",ans);
    for(i=1;i<=n;i++){
        printf("%d ",paixu[i]);
    }
    return 0;
}