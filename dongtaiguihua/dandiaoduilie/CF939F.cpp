#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
const int INF=0x3f3f3f3f;
int dp[N][2];
int linshi[N];
int qujian[203];
int zhi[N];
int q[N];
int main(){
    int head,tail;
    int n,k,i,len,j,p;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++){
        scanf("%d %d",&qujian[2*i-1],&qujian[2*i]);
    }
    k = 2*k;
    qujian[k+1]=2*n;
    dp[0][0]=INF;
    for(i=1;i<=n;i++){
        dp[i][0]=INF;
        dp[i][1]=INF;
    }
    for(j=0;j<=k;j++){
        len = qujian[j+1]-qujian[j];
        if(j&1){
            head=1;tail=0;
            for(i=0;i<=n;i++){
                linshi[i]=dp[i][0];
                p = min(dp[i][0]+2,dp[i][1]+1);
                while(head<=tail && p<=zhi[tail]){tail--;}
                q[++tail]=i;zhi[tail]=p;
                while(q[head]<i-len){head++;}
                dp[i][0]=min(dp[i][0],zhi[head]);
            }
            head=1;tail=0;
            for(i=0;i<=n;i++){
                p = min(linshi[i]+1,dp[i][1]+2);
                linshi[i]=dp[i][1];
                while(head<=tail && p<=zhi[tail]){tail--;}
                q[++tail]=i;zhi[tail]=p;
                while(q[head]<i-len){head++;}
                dp[i][1]=zhi[head];
                if(i>=len){dp[i][1]=min(dp[i][1],linshi[i-len]);}
            }
        }
        else{
            for(i=n;i>=len;i--){dp[i][1]=dp[i-len][1];}
            for(i=0;i<=len-1;i++){dp[i][1]=INF;}
        }
    }
    p = min(dp[n][0],dp[n][1]);
    if(p<INF){
        printf("Full\n");
        printf("%d",p);
    }
    else{
        printf("Hungry");
    }
    return 0;
}