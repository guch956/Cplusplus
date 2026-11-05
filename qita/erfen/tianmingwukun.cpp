#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
ll t[N];
ll s[N];
ll A[N];
ll change[N][2];
int main(){
    int n,sn,tn,i,l,r,mid,len;
    ll m,ans=0,sum=0,last;
    scanf("%d %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&A[i]);
        s[i]=m+1;
    }
    s[0]=0;
    t[0]=m+1;
    tn=0;
    for(i=n;i>=1;i--){
        l=0;r=tn;
        while(l<r){
            mid=(l+r+1)>>1;
            if(t[mid]>A[i]){
                l = mid;
            }
            else{
                r = mid-1;
            }
        }
        l++;
        change[i][0]=l;
        change[i][1]=t[l];
        t[l]=A[i];
        tn=max(tn,l);
    }
    len=tn;
    sn=0;
    sum=t[len]-1;
    ans+=sum;
    for(i=1;i<=n;i++){
        l=0;r=sn;
        while(l<r){
            mid=(l+r+1)>>1;
            if(s[mid]<A[i]){
                l = mid;
            }
            else{
                r = mid-1;
            }
        }
        l++;
        if(s[l]<t[len-l]){
            sum-=t[len-l]-s[l]-1;
        }
        s[l]=A[i];
        if(s[l]<t[len-l]){
            sum+=t[len-l]-s[l]-1;
        }
        sn=max(l,sn);
        if(s[len-change[i][0]]<t[change[i][0]]){
            sum-=t[change[i][0]]-s[len-change[i][0]]-1;
        }
        t[change[i][0]]=change[i][1];
        if(s[len-change[i][0]]<t[change[i][0]]){
            sum+=t[change[i][0]]-s[len-change[i][0]]-1;
        }
        ans+=sum;
    }
    printf("%lld",ans);
    return 0;
}