#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=500003;
const ll P=998244353;
int xianzhi[N];
int lef[N],rig[N];
class main{
private:
    int n;
    ll dp[N][2];
    ll sum[N];
    int mi[N];
    int ma[N];
    int head[N];
    int to[N];
    int nex[N];
    int num[N];
    int ent;
    void add(int,int);
public:
    ll chuli(int ,int ,int );
}A;
void main::add(int a,int b){
    ent++;
    to[ent]=b;
    nex[ent]=head[a];
    head[a]=ent;
}
ll main::chuli(int n1,int m,int k){
    n = n1;
    ent=0;mi[0]=0;
    int i,j;
    dp[0][0]=1;dp[0][1]=0;
    sum[0]=1;
    for(i=1;i<=n;i++){
        head[i]=0;
        ma[i]=0;
        num[i]=0;
    }
    for(i=1;i<=m;i++){
        if(((xianzhi[i]>>k)&1)==0){
            add(rig[i],lef[i]);
            ma[lef[i]]=lef[i];
        }
        else{
            num[rig[i]+1]--;
            num[lef[i]]++;
        }
    }
    for(i=1;i<=n;i++){
        num[i] = num[i]+num[i-1];
        mi[i] = mi[i-1];
        for(j=head[i];j;j=nex[j]){
            mi[i] = max(mi[i],to[j]);
        }
        dp[i][1]=ma[i]==i?0:(dp[i-1][0]+dp[i-1][1])%P;
        if(num[i]>0){
            dp[i][0]=0;
        }
        else{
            if(mi[i-1]==0){dp[i][0]=sum[i-1];}
            else{dp[i][0]=(sum[i-1]-sum[mi[i-1]-1]+P)%P;}
        }
        sum[i] = (sum[i-1]+dp[i][0])%P;
    }
    return dp[n][0]+dp[n][1];
}
int main(){
    int n,m,k,i;
    ll ans=1;
    scanf("%d %d %d",&n,&k,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&lef[i],&rig[i],&xianzhi[i]);
    }
    for(i=0;i<k;i++){
        ans = (A.chuli(n,m,i)*ans)%P;
    }
    printf("%lld",ans);
    return 0;
}