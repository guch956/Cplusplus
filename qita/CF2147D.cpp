#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=200003;
ll p[N];
ll num[N];
int main(){
    int T,n,i,m,nu;
    ll s,sa,sb;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        m = 0;nu = 0;
        s = sa = sb = 0;
        for(i=1;i<=n;i++){
            scanf("%lld",&p[i]);
        }
        sort(p+1,p+n+1);
        p[n+1]=0;
        for(i=1;i<=n;i++){
            nu++;
            if(p[i]!=p[i+1]){
                if(p[i]&1){
                    num[++m]=nu;
                }
                nu=0;
            }
            s+=p[i]/2;
        }
        sort(num+1,num+m+1,greater<ll>() );
        for(i=1;i<=m;i+=2){sa+=num[i];}
        for(i=2;i<=m;i+=2){sb+=num[i];}
        sa+=s;sb+=s;
        printf("%lld %lld\n",sa,sb);
    }
    return 0;
}
