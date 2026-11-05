#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
const ll P=1e9+7;
int dp[N][101][4];
struct {
    int to;
    int next;
}g[N<<1];
int head[N],ent;
ll k;
ll siz[N];
void adde(int u,int v){
    ent++;
    g[ent].to=v;
    g[ent].next=head[u];
    head[u]=ent;
}
void dfs(int s,int f){
    int e,j,v;
    ll i,a,b,c,d;
    dp[s][0][0]=dp[s][0][1]=1;
    dp[s][1][2]=dp[s][1][3]=1;
    siz[s]=1;
    for(e=head[s];e;e=g[e].next){
        v = g[e].to;
        if(v==f){continue;}
        dfs(v,s);
        for(i=min(siz[s]+siz[v],k);i>=0;i--){
            a=b=c=d=0;
            for(j=max((ll)0,i-siz[s]);j<=min(i,siz[v]);j++){
                a+=(((ll)dp[v][j][1]+(ll)dp[v][j][3])*(ll)dp[s][i-j][0])%P;
                a = a%P;
                b+=((ll)dp[v][j][1]*(ll)dp[s][i-j][1])%P;
                b = b%P;
                c+=(((ll)dp[v][j][0]+(ll)dp[v][j][2])*(ll)dp[s][i-j][2])%P;
                c = c%P;
                d+=((ll)dp[v][j][0]*(ll)dp[s][i-j][3])%P;
                d = d%P;
            }
            dp[s][i][0]=a;
            dp[s][i][1]=b;
            dp[s][i][2]=c;
            dp[s][i][3]=d;
        }
        siz[s]+=siz[v];
    }
    for(i=0;i<=min(siz[s],k);i++){
        dp[s][i][1]=(dp[s][i][0]-dp[s][i][1]+P)%P;
        dp[s][i][3]=(dp[s][i][2]-dp[s][i][3]+P)%P;
    }
}
int main(){
    int n,i,a,b;
    scanf("%d %lld",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    dfs(1,1);
    printf("%lld",(dp[1][k][1]+dp[1][k][3])%P);
    return 0;
}
