#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500003;
ll A[N<<1];
int main(){
    int n,i,j=1;
    ll m,ans=0,num=0,s,c,geshu=0;
    scanf("%d %lld %lld",&n,&m,&c);
    for(i=1;i<=n;i++){
        scanf("%lld",&A[i]);
    }
    sort(A+1,A+n+1);
    A[0]=A[n]-m;
    for(i=1;i<=n;i++)A[i+n]=A[i]+m;
    for(i=1;i<=n;i++){
        geshu++;
        while(num<c){
            s = A[j];
            while(A[j]==s){j++;num++;}
        }
        ans=(A[i]-A[i-1])*num+ans;
        if(A[i]!=A[i+1]){
            num-=geshu;
            geshu=0;
        }
    }
    printf("%lld",ans);
    return 0;
}