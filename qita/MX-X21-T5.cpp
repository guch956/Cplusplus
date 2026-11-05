#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=10000004;
int head[N<<1],nex[N],to[N],ent;
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
char s[N];
int zhi[N];
int main(){
    int T,n,i,a,r;
    ll ans;
    scanf("%d",&T);
    while(T--){
        ans=0;n=0;ent=0;a=0;
        scanf("%s",s+1);
        for(i=1;s[i];i++){
            if(s[i]=='1'){a++;}
            else{a--;}
            zhi[i]=a;
        }
        n = i-1;
        for(i=n;i>=1;i--){
            adde(zhi[i]+n,i);
        }
        for(i=1;i<=n;i++){
            a = zhi[i]+n;
            head[a] = nex[head[a]];
            if(s[i]=='1'){a = zhi[i-1]+n-1;}
            else{a = zhi[i-1]+n+1;}
            if(head[a]==0){r = n+1;}
            else{r = to[head[a]];}
            ans = ans+r-i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}