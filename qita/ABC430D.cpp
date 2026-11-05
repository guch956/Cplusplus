#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500003;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll ans[N];
struct node{
    int id;
    int pre;
    int suf;
    ll weizhi;
    ll juli;
}lian[N];
int paixu[N];
bool bijiao(node & n1,node & n2){
    return n1.weizhi<n2.weizhi;
}
inline void up(int t){
    lian[t].juli=min(lian[lian[t].suf].weizhi-lian[t].weizhi,lian[t].weizhi-lian[lian[t].pre].weizhi);
}
ll shanchu(int t){
    ll s=-lian[t].juli-lian[lian[t].pre].juli-lian[lian[t].suf].juli;
    lian[lian[t].pre].suf=lian[t].suf;
    lian[lian[t].suf].pre=lian[t].pre;
    if(lian[lian[t].pre].juli!=0)up(lian[t].pre);
    if(lian[lian[t].suf].juli!=0)up(lian[t].suf);
    s = s+lian[lian[t].pre].juli+lian[lian[t].suf].juli;
    return s;
}
int main(){
    int n,i;
    ll sum=0;
    scanf("%d",&n);
    lian[1].id=1;
    lian[1].weizhi=0;
    for(i=2;i<=n+1;i++){
        scanf("%lld",&lian[i].weizhi);
        lian[i].id=i;
    }
    sort(lian+1,lian+n+2,bijiao);
    lian[0].weizhi=-INF;
    lian[n+2].weizhi=INF;
    for(i=1;i<=n+1;i++){
        paixu[lian[i].id]=i;
        lian[i].pre=i-1;
        lian[i].suf=i+1;
        up(i);
        sum+=lian[i].juli;
    }
    ans[n+1]=sum;
    for(i=n+1;i>=2;i--){
        sum = sum+shanchu(paixu[i]);
        ans[i-1]=sum;
    }
    for(i=2;i<=n+1;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}