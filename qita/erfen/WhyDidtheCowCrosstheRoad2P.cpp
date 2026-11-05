#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int siz[N];
int weiz[N];
int f[N];
int change[10][2];
int main(){
    int i,j,a,n,m,l,r,mid,x,top;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        weiz[a]=i;
        f[i]=N+1;
    }
    m = 0;
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        top=0;
        for(j=max(1,a-4);j<=min(n,a+4);j++){
            x=weiz[j];
            l = 0;r = m+1;
            while(l<r){
                mid=(l+r)>>1;
                if(x<=f[mid]){
                    r = mid;
                }
                else{
                    l = mid+1;
                }
            }
            change[top][0]=l;
            change[top][1]=x;
            top++;
        }
        for(j=0;j<top;j++){
            if(change[j][0]>m){
                m = change[j][0];
            }
            f[change[j][0]]=min(f[change[j][0]],change[j][1]);
        }
    }
    printf("%d",m);
    return 0;
}