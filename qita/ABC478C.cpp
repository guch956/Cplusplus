#include<iostream>
#include<cstdio>
using namespace std;
const int N = 200003;
int A[N],pre_max[N],suf_min[N];
bool pre[N],suf[N];
int main(){
    int n,k,i;
    scanf("%d %d",&n,&k);
    A[0] = 0;A[n+1] = n+1;
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    pre_max[0] = A[0];pre[0] = true;
    for(i=1;i<=n;i++){
        pre_max[i] = max(pre_max[i-1],A[i]);
        pre[i] = pre[i-1]&&(A[i]>=A[i-1]);
    }
    suf_min[n+1] = A[n+1];suf[n+1] = true;
    for(i=n;i>=1;i--){
        suf_min[i] = min(suf_min[i+1],A[i]);
        suf[i] = suf[i+1]&&(A[i]<=A[i+1]);
    }
    for(i=1;i<=n-k+1;i++){
        if(pre_max[i-1]<=suf_min[i] && pre_max[i+k-1]<=suf_min[i+k] && pre[i-1] && suf[i+k]){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}