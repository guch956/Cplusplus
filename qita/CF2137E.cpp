#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
const int INF=0x3f3f3f3f;
int cishu[N];
void solve(){
    int n,i,a,k,mi=INF;
    ll ans=0,num=0,tot=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        cishu[a]++;
    }
    for(i=0;i<=n;i++){
        if(cishu[i]==0){break;}
        if(cishu[i]>=2){
            num=num+cishu[i];
            mi = min(mi,i);
        }
        else{ans = ans+i;}
        tot=tot+cishu[i];
    }
    ans = ans+(ll)i*(n-tot)+num*i;
    if(k>=2){
        if(k&1){
            if(mi==INF){ans = (ll)i*(i-1)/2+(ll)i*(n-i);}
            else{
                ans = (ll)mi*(mi-1)/2+(ll)mi*(n-mi);
                if(n-mi>=2){ans=ans+n-mi;}
            }
        }
        else{
            if(mi==INF){
                ans = (ll)i*(i-1)/2+(ll)i*(n-i);
                if(n-i>=2){ans=ans+n-i;}
            }
            else{ans = (ll)mi*(mi-1)/2+(ll)mi*(n-mi);}
        }
    }
    for(i=0;i<=n;i++){cishu[i]=0;}
    printf("%lld\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}