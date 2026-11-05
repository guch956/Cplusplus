#include<cstdio>
#include<iostream>
using namespace std;
int s[500004],dp[500004],p[500004],d=0;
int main(){
    int n,q,m,*a,*b,*c,i,j,e,s;
    freopen("reserve7.in","r",stdin);
    scanf("%d",&n);
    a = new int[n+1];a[0]=0;
    b = new int[n+1];b[0]=0;
    c = new int[n+1];c[0]=0;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    scanf("%d",&q);
    while(q>0){
        q--;
        scanf("%d",&m);
        d = 1;
        for(i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        p[m+1]=n+1;
        s = 0;
        for(i=1;i<=n;i++){
            if(i==p[d]){
                e = 0;
                s+=c[i];
                d++;
            }
            else{
                e = b[i];
            }
            dp[i] = min(a[i]+s,dp[i-1]+e);
        }
        printf("%d \n",dp[n]);
    }
    return 0;
}