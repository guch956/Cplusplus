#include<iostream>
#include<cstdio>
using namespace std;
const int N=403;
int A[N][N];
int sum1[N<<1][N];
int sum2[N<<1][N];
int ans=-0x3f3f3f3f;
int n;
inline int jisuan1(int l1,int r1,int d){
    return sum1[n-l1+r1][min(l1,r1)+d]-sum1[n-l1+r1][min(l1,r1)-1];
}
inline int jisuan2(int l1,int r1,int d){
    return sum2[2*n+1-l1-r1][min(l1,n+1-r1)+d]-sum2[2*n+1-l1-r1][min(l1,n+1-r1)-1];
}
int main(){
    int i,j,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
        scanf("%d",&A[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            sum1[i][j] = sum1[i][j-1]+A[n+j-i][j];
            sum2[i][j] = sum2[i][j-1]+A[n+j-i][n+1-j];
        }
    }
    for(i=n+1;i<=2*n-1;i++){
        for(j=1;j<=2*n-i;j++){
            sum1[i][j] = sum1[i][j-1]+A[j][i+j-n];
            sum2[i][j] = sum2[i][j-1]+A[j][2*n+1-j-i];
        }
    }
    for(i=1;i<=n-1;i++){
        for(j=i+1;j<=n;j++){
            for(m=1;m+j-i<=n;m++){
                ans = max(ans,jisuan1(m,i,j-i)-jisuan2(m,j,j-i));
            }
        }
    }
    printf("%d",ans);
    return 0;
}