#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int zhan[200],top;
int solve(int k,ll x){
    ll a = (ll)1<<k,b;
    if(x==a){return 0;}
    if(x&1){
        if(x<a){
            b = solve(k-1,x);
            zhan[++top]=1;
        }
        else{
            b = solve(k-1,x-a);
            zhan[++top]=2;
        }
        return b+1;
    }
    else{return solve(k-1,x>>1);}
}
int main(){
    int T,n,i;
    ll x;
    scanf("%d",&T);
    while(T--){
        scanf("%d %lld",&n,&x);
        top=0;
        printf("%d\n",solve(n,x));
        for(i=1;i<=top;i++){
            printf("%d ",zhan[i]);
        }
        printf("\n");
    }
    return 0;
}