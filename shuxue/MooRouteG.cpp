#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
ll P=1000000007;
ll jiecheng[N];
ll ni[N];
ll A[N];
int main(){
    int n,i;
    ll ma=0,a,ans=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a);
        if(a&1 || a==0){printf("0");return 0;}
        A[i] = a>>1;
        ma = max(ma,A[i]);
    }
    jiecheng[0]=ni[0]=1;
    ni[1]=jiecheng[1]=1;
    for(i=2;i<=ma;i++){
        a = (P-P%i)/i;
        ni[i] = ((P-a)*ni[P%i])%P;
    }
    for(i=1;i<=ma;i++){
        jiecheng[i] = (i*jiecheng[i-1])%P;
        ni[i] = (ni[i]*ni[i-1])%P;
    }
    for(i=1;i<n;i++){
        if(A[i]<=A[i-1]){
            ans = (ans*jiecheng[A[i-1]])%P;
            ans = (ans*ni[A[i]])%P;
            ans = (ans*ni[A[i-1]-A[i]])%P;
        }
        else{
            ans = (ans*jiecheng[A[i]-1])%P;
            ans = (ans*ni[A[i-1]-1])%P;
            ans = (ans*ni[A[i]-A[i-1]])%P;
        }
    }
    printf("%lld",ans);
    return 0;
}