#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=200005;
const ll P = 998244353;
int son[N][2];
int sta[N];
ll ans[N];
ll siz[N];
void addson(int f,int s,int k){
    son[f][k] = s;
}
void dfs(int s,ll o){
    siz[s] = ans[s] = 1;
    if(son[s][0]){
        dfs(son[s][0],o);
        ans[s] = ans[s]*ans[son[s][0]]%P;
        ans[s] = ans[s]*(siz[son[s][0]]+o)%P;
    }
    if(son[s][1]){
        dfs(son[s][1],1);
        ans[s] = ans[s]*ans[son[s][1]]%P;;
    }
    siz[s] = siz[s]+siz[son[s][0]]+siz[son[s][1]];
}
int main(){
    int n,i,ebp=0,a;
    scanf("%d",&n);
    sta[ebp] = n+1;
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        while(a>sta[ebp]){
            ebp--;
            if(a>sta[ebp]){
                addson(sta[ebp],sta[ebp+1],1);
            }
            else{
                addson(a,sta[ebp+1],0);
            }
        }
        sta[++ebp] = a;
    }
    while(ebp>1){
        ebp--;
        addson(sta[ebp],sta[ebp+1],1);
    }
    dfs(sta[ebp],0);
    printf("%lld",ans[sta[ebp]]);
    return 0;
}