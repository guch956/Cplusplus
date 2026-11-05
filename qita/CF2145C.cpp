#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int zhi[N<<1];
int sum[N];
char s[N];
int main(){
    int i,n,T,su,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s+1);
        su=0;ans = n;
        for(i=1;i<=n;i++){
            if(s[i]=='a')su++;
            else su--;
            sum[i]=su;
            zhi[N-i]=zhi[N+i]=-0x3f3f3f3f;
        }
        zhi[N]=0;
        for(i=1;i<=n;i++){
            zhi[N+sum[i]]=i;
            ans = min(ans,i-zhi[N+sum[i]-su]);
        }
        if(ans==n)printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}