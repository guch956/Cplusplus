#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int LOG2[N];
int dp[N][18];
int n;
int p[N];
int last[N];
int left1[N],right1[N];
int total;
void st(){
    int i,k,a;
    LOG2[0]=-1;
    for(i=1;i<=n;i++){
        LOG2[i]=LOG2[i>>1]+1;
    }
    for(i=1;i<=n;i++){
        dp[i][0]=p[i];
    }
    for(k=1;k<=LOG2[n];k++){
        a = (1<<k)-1;
        for(i=1;i+a<=n;i++){
            dp[i][k]=min(dp[i][k-1],dp[i+(1<<(k-1))][k-1]);
        }
    }
}
int zuixiao(int l,int r){
    return min(dp[l][LOG2[r-l+1]],dp[r+1-(1<<LOG2[r-l+1])][LOG2[r-l+1]]);
}
void jisuan(){
    int i,a;
    for(i=1;i<=n;i++){
        if(last[p[i]]==0){
            total++;
            left1[i]++;
        }
        else{
            a = zuixiao(last[p[i]],i);
            if(a<p[i]){
                right1[last[p[i]]]++;
                left1[i]++;
                total++;
            }
        }
        last[p[i]]=i;
    }
    for(i=1;i<=n;i++){
        right1[last[i]]++;
    }
    right1[0]=0;
    left1[n+1]=0;
    for(i=2;i<=n;i++){
        right1[i]+=right1[i-1];
    }
    for(i=n-1;i>=1;i--){
        left1[i]+=left1[i+1];
    }
}
int chaxun(int l,int r){
    return total-left1[r+1]-right1[l-1];
}
int main(){
    int q,i,a;
    freopen("2.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    st();
    jisuan();
    while(q){
        scanf("%d %d",&i,&a);
        printf("%d\n",chaxun(i,a));
        q--;
    }
    return 0;

}