#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int log2[N];
int ma[N][18];
int A[N];
int main(){
    int n,q,i,k=2,t=1,l,r;
    scanf("%d %d",&n,&q);
    log2[0]=-1;
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        log2[i]=log2[i>>1]+1;
        ma[i][0]=A[i];
    }
    while(k<=n){
        for(i=1;i<=n-k+1;i++){
            ma[i][t]=max(ma[i+(k>>1)][t-1],ma[i][t-1]);
        }
        k = k<<1;
        t++;
    }
    while(q--){
        scanf("%d %d",&l,&r);
        k = r-l+1;
        t = 1<<log2[k];
        printf("%d\n",max(ma[l][log2[k]],ma[r-t+1][log2[k]]));
    }
    return 0;
}