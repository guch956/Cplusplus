#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
const ll P=1000000007;
int z[N];
ll num[N];
char p[N];
void jisuan(char * s,int slen){
    int m=0,i,k,r;
    ll ans=1;
    memset(num,0,sizeof(num));
    for(i=1;i<slen;i++){
        z[i]=0;
        if(m>i){z[i]=min(m-i,z[i-k]);}
        while(s[i+z[i]]==s[z[i]]){z[i]++;}
        if(z[i]+i>m){
            m = z[i]+i;
            k = i;
        }
        r = min(i,z[i])+i;
        num[i]++;
        num[r]--;
    }
    for(i=1;i<slen;i++){
        num[i]=num[i-1]+num[i];
        ans = ans*(num[i]+1)%P;
    }
    printf("%lld\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",p);
        jisuan(p,strlen(p));
    }
    return 0;
}