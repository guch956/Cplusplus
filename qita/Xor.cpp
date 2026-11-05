#include<iostream>
#include<cstdio>
using namespace std;
const int N=500003;
int p[N],q[N][2];
int main(){
    int n,ans=0,i,j,last=0,c,num,b,t,now=1,old=0,k,d;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
        q[i][old]=i;
    }
    t = n;
    for(i=0;i<=30;i++){
        num=0;
        for(j=1;j<=n;j++){
            if(p[j]&(1<<i)){num++;}
        }
        b = ((num&(n-num))^last)&1;
        if(b){ans+=(1<<i);}
        num = n-num;
        b = 0;c = num;
        k = 1<<i;
        for(j=1;j<=n;j++){
            if(p[q[j][old]]&k){
                q[++c][now]=q[j][old];
            }
            else{
                q[++b][now]=q[j][old];
            }
        }
        c = 1;
        last=0;
        k = k<<1;
        for(j=n;j>=1;j--){
            b=p[q[j][now]]&(k-1);
            d = p[q[c][now]]&(k-1);
            while(c<=j && b+d<k){
                c++;
                d = p[q[c][now]]&(k-1);
            }
            if(c>j){break;}
            else{
                last = last^(j-c+1);
            }
        }
        swap(now,old);
    }
    printf("%d",ans);
    return 0;
}