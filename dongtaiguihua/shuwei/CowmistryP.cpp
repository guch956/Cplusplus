#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=20003;
const ll P=1e9+7;
int le[N][31],ri[N][31];
int k[31],xianzhi[31];
int n;
int get(int x,int * p){
    int l=0;
    while(x){
        l++;
        if(x&1){p[l]=1;}
        x = x>>1;
    }
    return l;
}
ll dfs(){

}
ll jisuan(int len,int r){
    
}
ll solve(int len){
    int i;
    ll ans=0;
    for(i=len;i>=1;i--){
        if(k[i]==1){
            ans = (ans+jisuan(len,i))%P;
        }
        k[i]=1;
    }
    ans = (ans+jisuan(len,1))%P;
    return ans;
}
int main(){
    int K,i,lk,lm=0,a,b;
    ll num=0,ans;
    scanf("%d %d",&n,&K);
    lk=get(K,k);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        lm=max(lm,get(a,le[i]));
        lm=max(lm,get(b,ri[i]));
        num = num+b-a+1;
    }
    if(lk>lm){
        //ans = 
    }
    else{
        ans = solve(lm); 
    }
    printf("%lld",ans);
    return 0;
}