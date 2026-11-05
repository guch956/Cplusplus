#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=150003;
ll p[N];
struct node{
    ll w;
    int xiabiao;
}q[N];
bool bijiao(node & n1,node & n2){
    return n1.w<n2.w;
}
ll he;
ll sum[N];
int A[N];
int main(){
    int n,i,l,r,T,x,mid;
    ll y,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&p[i]);
        q[i].xiabiao=i;
        q[i].w=p[i];
    }
    sort(q+1,q+1+n,bijiao);
    for(i=1;i<=n;i++){
        he+=i*q[i].w;
        sum[i] = sum[i-1]+q[i].w;
        A[q[i].xiabiao]=i;
    }
    q[0].w=-1;q[n+1].w=0x3f3f3f3f3f3f3f3f;
    scanf("%d",&T);
    while(T--){
        scanf("%d %lld",&x,&y);
        l = 0;r = n+1;
        while(l<r){
            mid=(l+r)>>1;
            if(q[mid].w<=y){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        if(l<=A[x]){
            ans = he+l*y-A[x]*p[x];
            ans+=sum[A[x]-1]-sum[l-1];
        }
        else{
            ans = he+(l-1)*y-A[x]*p[x];
            ans+=sum[A[x]]-sum[l-1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

