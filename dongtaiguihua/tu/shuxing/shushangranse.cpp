#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=2003;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll k,n;
ll dp[N][N][3];
ll siz[N];
struct {
    int to;
    int next;
    ll len;
}g[N<<1];
int head[N],ent;
void adde(int u,int v,ll l){
    ent++;
    g[ent].len=l;
    g[ent].next=head[u];
    g[ent].to=v;
    head[u]=ent;
}
void dfs1(int s,int f){
    int i,v;
    siz[s]=1;
    for(i=head[s];i;i=g[i].next){
        v = g[i].to;
        if(v==f){continue;}
        dfs1(v,s);
        siz[s]+=siz[v];
    }
}
void dfs(int s,int f){
    int v,d;
    ll i,a,b,c,sum,A,B,C,Sum,j,si;
    si=1;
    for(d=head[s];d;d=g[d].next){
        v = g[d].to;
        if(v==f){continue;}
        dfs(v,s);
        for(i=min(si+siz[v],k);i>=0;i--){
            Sum=-INF;
            for(j=max((ll)0,i-si);j<=min(i,siz[v]);j++){
                a=dp[s][i-j][0]+dp[v][j][0]+j*dp[s][i-j][1]+(i-j)*dp[v][j][1]+(siz[v]-j)*dp[s][i-j][2]+(si-i+j)*dp[v][j][2]+g[d].len*(j*(i-j)+(siz[v]-j)*(si-i+j));
                b=dp[s][i-j][1]+j*g[d].len+dp[v][j][1];
                c=dp[s][i-j][2]+(siz[v]-j)*g[d].len+dp[v][j][2];
                sum = a+(k-i)*b+(n-k-siz[s]+i)*c;
                if(sum>Sum){
                    Sum=sum;
                    A=a;
                    B=b;
                    C=c;
                }
            }
            dp[s][i][0]=A;
            dp[s][i][1]=B;
            dp[s][i][2]=C;
        }
        si+=siz[v];
    }
}
int main(){
    int i,a,b;
    ll c;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d %d %lld",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
    dfs1(1,1);
    dfs(1,1);
    printf("%lld",dp[1][k][0]);
    return 0;
}