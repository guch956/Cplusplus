#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
ll p[N];
int main(){
    int n,T,k,i,j,num1,m;
    ll ans=0,s,a;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        for(j=29;j>=0;j--){
            if(k==1){
                s=(1<<(j+1))-1;
                for(i=1;i<=n;i++){s = s&p[i];}
                ans += s;
                break;
            }
            s = 1<<j;
            num1=0;
            for(i=1;i<=n;i++){
                if(s&p[i]){num1++;}
            }
            if(num1==n){
                ans=ans+k*s;
                for(i=1;i<=n;i++){if(s&p[i]){p[i]=p[i]^s;}}
                continue;}
            if(num1==0){continue;}
            if(num1<=k-1){
                m = 0;
                for(i=1;i<=n;i++){
                    if(!(s&p[i])){p[++m]=p[i];}
                    else{ans+=p[i];
                        p[i]=p[i]^s;
                    }
                }
                n = m;
                k = k-num1;
            }
            else{
                ans += (k-1)*s;
                a = (1<<(j+1))-1;
                m = 0;
                for(i=1;i<=n;i++){
                    if(s&p[i]){p[++m]=p[i]^s;}
                    else{a = a&p[i];}
                }
                p[++m]=a;
                n = m;                
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}