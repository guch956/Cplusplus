#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 150003;
class qujian{
    public:
    int l,r;
    bool operator<(const qujian q1)const {
        return r<q1.r;
    }
}q[N];
int dp[N];
int main(){
    int n,i,l,r,mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
    }
    sort(q+1,q+n+1);
    for(i=1;i<=n;i++){
        dp[i] = q[i].r-q[i].l+1;
        l = 0;r = i;
        while(l<r){
            mid = (l+r+1)>>1;
            if(q[mid].r<q[i].l){l = mid;}
            else{r = mid-1;}
        }
        dp[i]+=dp[l];
        dp[i] = max(dp[i],dp[i-1]);
    }
    printf("%d",dp[n]);
    return 0;
}