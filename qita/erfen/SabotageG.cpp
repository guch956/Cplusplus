#include<iostream>
#include<cstdio>
using namespace std;
const double INF=100000000000;
const int N=100003;
double sum[N];
int n;
bool check(double x){
    double mi=sum[1]-x,ans=-INF;
    int i;
    for(i=2;i<=n-1;i++){
        ans=max(ans,sum[i]-i*x-mi);
        mi = min(mi,sum[i]-i*x);
    }
    if(ans>=sum[n]-n*x){
        return 1;
    }
    return 0;
}
int main(){
    int i;
    double a,l=0,r=0,mid;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf",&a);
        sum[i]=sum[i-1]+a;
        r = max(r,a);
    }
    for(i=1;i<=60;i++){
        mid=(l+r)/2;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    printf("%.3lf",l);
    return 0;
}