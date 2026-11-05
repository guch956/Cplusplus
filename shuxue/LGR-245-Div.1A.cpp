#include<cstdio>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
const ll P=1e9+7;
int pri[N];
int p[N],ent;
void init(){
    int i,j,k;
    for(i=2;i<N;i++){
        if(!p[i]){pri[++ent]=i;}
        for(j=1;j<=ent;j++){
            k = i*pri[j];
            if(k>=N){break;}
            p[k]=pri[j];
            if(i%pri[j]==0){break;}
        }
    }
}
ll check(ll n){
    ll l=1,r=P,mid;
    while(l<r){
        mid = (l+r+1)>>1;
        if(mid*mid<=n){l = mid;}
        else{r = mid-1;}
    }
    if(l*l==n){return l;}
    else{return 1;}
}
int main(){
    int T,i,j;
    ll n,ans,q,a;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        ans = (n%P)*(n%P)%P;
        a = 1;
        for(i=1;i<=ent;i++){
            q = pri[i];
            if(n%pri[i]==0){
                for(j=0;;j++){
                    if(j&1){a = a*q;}
                    n = n/q;
                    if(n%q!=0){break;}
                }
            }
        }
        a = a*check(n);
        ans = (ans+a)%P;
        printf("%lld\n",ans);
    }
    return 0;
}