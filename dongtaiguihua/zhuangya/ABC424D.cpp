#include<iostream>
#include<cstdio>
using namespace std;
const int N=130;
const int INF=0x3f3f3f3f;
int check[N][N];
int dp[N][10];
int num[N];
char s[10];
int zhuant[10];
void init(){
    int n=1<<7,i,a=1,j,b1,b2;
    for(i=1;i<n;i++){
        if(i==2*a){a = a*2;}
        num[i]=num[i-a]+1;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            check[i][j]=1;
            for(a=0;a<6;a++){
                b1 = 1<<a;
                b2 = 1<<(a+1);
                if((i&b1) && (i&b2) && (j&b1) && (j&b2)){
                    check[i][j]=0;
                }
            }
        }
    }
}
int main(){
    int T,n,m,i,j,a,ans,k;
    init();
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%s",s);
            zhuant[i]=0;
            for(j=0;j<m;j++){
                if(s[j]=='#'){
                    zhuant[i]+=1<<j;
                }
            }
        }
        a = 1<<m;
        for(j=0;j<a;j++){
            if((j|zhuant[0])==zhuant[0])dp[j][0]=num[zhuant[0]-j];
            else dp[j][0]=INF;
        }
        for(i=1;i<n;i++){
            for(j=0;j<a;j++){
                dp[j][i]=INF;
                if((j|zhuant[i])!=zhuant[i])continue;
                for(k=0;k<a;k++){
                    if(check[k][j]){
                        dp[j][i]=min(dp[j][i],dp[k][i-1]+num[zhuant[i]-j]);
                    }
                }
            }
        }
        ans = INF;
        for(j=0;j<a;j++){
            ans = min(ans,dp[j][n-1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

