#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int N=200003;
int du[N];
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        du[a]^=1;
        du[b]^=1;
    }
    if((n&1)==0){
        for(i=1;i<=n;i++){
            du[i]^=1;
        }
    }
    m = 0;
    for(i=1;i<=n;i++){
        m+=du[i];
    }
    m = m/2;
    printf("%lld",(ll)n*(n-1)/2-m);
    return 0;
}