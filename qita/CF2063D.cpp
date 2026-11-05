#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll A[N],B[N];
ll zhia[N],zhib[N];
int sum[2][N<<1];
int main(){
    int T,n,m,n1,m1,i,k,j,l,tot,p1,p2;
    ll ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        n1 = n>>1;m1 = m>>1;ans = 0;
        for(i=1;i<=n;i++){
            scanf("%lld",&A[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%lld",&B[i]);
        }
        sort(A+1,A+n+1);
        sort(B+1,B+m+1);
        for(i=1;i<=n1;i++){
            zhia[i]=A[n+1-i]-A[i];
        }
        for(i=1;i<=m1;i++){
            zhib[i]=B[m+1-i]-B[i];
        }
        i = j = 1;
        zhia[n1+1]=zhib[m1+1]=-INF;
        k = min(min(n,m),(m+n)/3);
        if(k==0){printf("0\n\n");continue;}
        tot=0;
        while(i<=n1 || j<=m1){
            tot++;
            if(zhia[i]>zhib[j]){
                i++;
                sum[0][tot]=sum[0][tot-1]+1;
                sum[1][tot]=sum[1][tot-1];
            }
            else{
                j++;
                sum[0][tot]=sum[0][tot-1];
                sum[1][tot]=sum[1][tot-1]+1;
            }
        }
        for(i=1;i<=n1;i++){zhia[i]+=zhia[i-1];}
        for(i=1;i<=m1;i++){zhib[i]+=zhib[i-1];}
        printf("%d\n",k);
        for(l=1;l<=k;l++){
            p1 = min(l,n-l);
            p2 = min(l,m-l);
            if(sum[0][l]>p1){ans = zhia[p1]+zhib[l-p1];}
            else if(sum[1][l]>p2){ans = zhia[l-p2]+zhib[p2];}
            else{ans = zhia[sum[0][l]]+zhib[sum[1][l]];}
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}