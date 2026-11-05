#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=300003;
const ll P=998244353;
ll jiec[N<<1],ni[N<<1];
ll ca[N],nica[N];
void init(int n){
    ll i,k,r;
    jiec[0]=jiec[1]=1;
    ni[0]=ni[1]=1;
    for(i=2;i<=n;i++){
        jiec[i]=jiec[i-1]*i%P;
        k = P/i;
        r = P%i;
        ni[i]=(P-k)*ni[r]%P;
    }
    for(i=2;i<=n;i++){ni[i]=ni[i]*ni[i-1]%P;}
}
void jisuan(int n){
    int i;
    ca[0]=nica[0]=1;
    for(i=1;i<=n;i++){
        ca[i]=jiec[i<<1]*ni[i]%P*ni[i+1]%P;
        nica[i]=jiec[i]*jiec[i+1]%P*ni[i<<1]%P;
    }
}
int shunxun[N][2];
ll anss[N];
int peidui[N<<1];
int fa[N<<1];
int siz[N<<1];
int nex[N<<1];
int zhan[N],top;
int find(int x){
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
int main(){
    int T,n,i,a,b,c;
    ll ans;
    scanf("%d",&T);
    init(600003);
    jisuan(300001);
    while(T--){
        scanf("%d",&n);
        ans = 1;siz[0] = 0;
        for(i=1;i<=n;i++){
            scanf("%d %d",&shunxun[i][0],&shunxun[i][1]);
            peidui[shunxun[i][0]]=shunxun[i][1];
            peidui[shunxun[i][1]]=shunxun[i][0];
            fa[i]=i;fa[i+n]=i+n;
            siz[i]=siz[i+n]=0;
        }
        anss[n+1]=ans;
        top=0;
        for(i=1;i<=n*2;i++){
            if(peidui[i]<i){top--;}
            else{
                nex[i]=zhan[top];
                zhan[++top]=i;
            }
        }
        for(i=n;i>=1;i--){
            a = siz[shunxun[i][0]];
            b = find(nex[shunxun[i][0]]);
            c = siz[b];
            ans = ans*nica[a]%P*nica[c]%P;
            fa[shunxun[i][0]]=b;
            siz[b]=siz[b]+a+1;
            ans = ans*ca[siz[b]]%P;
            anss[i]=ans;
        }
        for(i=1;i<=n+1;i++){
            printf("%lld ",anss[i]);
        }
        printf("\n");
    }
    return 0;
}