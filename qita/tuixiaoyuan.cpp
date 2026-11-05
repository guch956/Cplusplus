#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
struct node{
    int dis;
    int val;
}p[N];
bool bijiao(node & n1,node & n2){
    return n1.val>n2.val;
}
int ma[N];
int main(){
    int n,i,sum0=0,sum1=0,ans,md=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].dis);
        p[i].dis=p[i].dis<<1;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].val);
    }
    sort(p+1,p+n+1,bijiao);
    for(i=n;i>=1;i--){
        ma[i]=max(ma[i+1],p[i].val+p[i].dis);
    }
    for(i=1;i<=n;i++){
        sum1+=p[i].val;
        md = max(md,p[i].dis);
        ans = sum1+md;
        ans = max(sum0+ma[i],ans);
        sum0+=p[i].val;
        printf("%d\n",ans);
    }
    return 0;
}