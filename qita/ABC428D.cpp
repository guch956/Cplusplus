#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
inline ll get(ll l,ll r){
    ll a = sqrt(r),b = sqrt(l-1);
    return a-b;
}
int main(){
    int T;
    ll c,d,ans,f,l,r,x;
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&c,&d);
        f = 1;
        while(f<c){f = f*10;}
        x = f-c-1;
        if(d<=x){ans = get(c*f+c+1,c*f+c+d);}
        else{
            ans = get(c*f+c+1,c*f+f-1);
            while(1){
                f = f*10;
                x = f-c-1;
                if(d<=x){
                    ans+=get(c*f+f/10,c*f+c+d);break;
                }
                else{
                    ans+=get(c*f+f/10,c*f+f-1);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}