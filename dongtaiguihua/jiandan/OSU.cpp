#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,i;
    double sum=0,dp0=0,dp1=0,dp2=0,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf",&a);
        sum+=a;
        dp0=a*dp1+dp0;
        dp1=a*(dp1+dp2+6);
        dp2=a*(dp2+6);
    }
    printf("%.1f",sum+dp0);
    return 0;
}