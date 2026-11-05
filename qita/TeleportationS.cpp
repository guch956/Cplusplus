#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=300003;
int n;
struct yici{
    ll begin;
    ll xielv;
    ll jieju;
}q[N];
void add(ll a,ll b,ll c){
    n++;
    q[n].begin=a;
    q[n].xielv=b;
    q[n].jieju=c;
}
bool bijiao(yici & y1,yici & y2){
    return y1.begin<y2.begin;
}
int main(){
    int m,i;
    ll a,b,sum=0,ans=0;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&a,&b);
        sum+=abs(a-b);
        if(a*b<0){
            if(b>0){
                add(0,1,0);
                add(b,-2,2*b);
                add(2*b,1,-2*b);
            }
            else{
                add(2*b,1,-2*b);
                add(b,-2,2*b);
                add(0,1,0);
            }
        }
        else if(a>0 && b>0 && b>2*a){
            add(2*a,1,-2*a);
            add(b,-2,2*b);
            add(2*b-2*a,1,2*a-2*b);
        }
        else if(b<0 && a<0 && b<2*a){
            add(2*b-2*a,1,2*a-2*b);
            add(b,-2,2*b);
            add(2*a,1,-2*a);
        }
    }
    if(n>0){
        a=0;b=0;
        sort(q+1,q+n+1,bijiao);
        q[0].begin=-0x3f3f3f3f3f3f3f3f;
        for(i=1;i<=n;i++){
            if(q[i].begin!=q[i-1].begin){
                if(a>=0){
                    ans=max(ans,a*q[i].begin+b);
                }
                else{
                    ans=max(ans,a*q[i-1].begin+b);
                }
            }
            a+=q[i].xielv;
            b+=q[i].jieju;
        }
    }
    printf("%lld",sum-ans);
    return 0;
}