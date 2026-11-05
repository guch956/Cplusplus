#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll P=1e9+7;
const int N=1000003;
bool ispri[N];
int pri[N];
int top;
void init(int n){
    int i,k,j;
    for(i=2;i<=n;i++){
        if(!ispri[i]){pri[++top]=i;}
        for(j=1;j<=top;j++){
            k = pri[j]*i;
            if(k>n){break;}
            ispri[k]=1;
            if(i%pri[j]==0){break;}
        }
    }
}
int main(){
    ll n,ans=1,i,t,k,num;
    scanf("%lld",&n);
    init(n);
    for(i=1;i<=top;i++){
        k = 1;t = pri[i];num = 0;
        while(t<=n){
            num += n/t;
            t = t*pri[i];
            k++;
        }
        num = num<<1|1;
        ans = ans*num%P;
    }
    printf("%lld",ans);
    return 0;
}
