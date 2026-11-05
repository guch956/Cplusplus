#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;
int s[N];
char p[N];
int banjing[N];
int main(){
    int n,i,r=0,k=0;
    long long ans=0;
    char c;
    scanf("%d",&n);
    scanf("%s",p+1);
    for(i=1;i<=n;i++){if(p[i]=='1'){s[i]=1;}}
    s[0]=s[n+1]=2;
    for(i=1;i<n;i++){
        if(k+r>i){banjing[i]=min(k+r-i,banjing[2*k-i]);}
        while(s[i+1+banjing[i]]+s[i-banjing[i]]==1){banjing[i]++;}
        if(i+banjing[i]>k+r){k = i;r = banjing[i];}
        ans = ans+banjing[i];
    }
    printf("%lld",ans);
    return 0;
}