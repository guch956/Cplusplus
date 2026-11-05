#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=10003;
int A[N];
int num[N];
int main(){
    int n,T,i,x,y,m,nr,ans,nl;
    //freopen("5.in","r",stdin);
    scanf("%d %d",&n,&T);
    for(i=1;i<=n;i++){scanf("%d",&A[i]);}
    while(T--){
        scanf("%d %d",&x,&y);
        m = 0;ans = 0;
        memset(num,0,sizeof(num));
        for(i=x+1;i<y;i++){if(A[i]<A[x])m++;}
        nr=0;nl=0;
        for(i=y;i<=n;i++){
            if(A[i]<A[x])nr++;
            num[nr]++;
        }
        for(i=x;i>=1;i--){
            if(A[i]<A[x]){nl++;}
            nr = y-m-nl-i;
            if(nr>=0)ans+=num[nr];
        }
        printf("%d\n",ans);
    }
    return 0;
}
