#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=100003;
ll p[N];
int wz[N];
ll minn(int l,int r){
    ll mi=INF,an=0;
    for(int i=l;i<=r;i++){
        if(p[i]<0){
            an+=p[i];
        }
        mi=min(mi,p[i]);
    }
    if(mi>=0){return mi;}
    return an;
}
int main(){
    int T,n,i,last,m,j;
    char c;
    ll ans,t,sum;
    scanf("%d %d",&n,&T);
    while(T--){
        scanf("%d",&n);
        m = 0;ans=0;
        for(i=1;i<=n;i++){
            cin>>c;
            if(c=='1'){
                wz[++m]=i;
            }
        }
        for(i=1;i<=n;i++){
            scanf("%lld",&p[i]);
        }
        wz[m+1]=N+6;
        last=1;
        for(i=1;i<=m;i++){
            if(wz[i]+2<wz[i+1]){
                t = INF;
                sum=0;
                if(wz[i]-wz[last]==i-last){
                    for(j=wz[last];j<=wz[i];j++){
                        sum+=p[j];
                    }
                    t = sum;
                }
                else{
                    t = minn(wz[last]+1,wz[i]-1);
                    if(p[wz[last]]<0){t+=p[wz[last]];}
                    if(p[wz[i]]<0){t+=p[wz[i]];}
                    if(wz[i]-wz[last]==2){t = min(t,p[wz[i]]+p[wz[last]]);}
                }
                ans+=t;
                last=i+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}