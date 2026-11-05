#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int head[N],to[N],nex[N],ent;
int siz[N];
int p[N];
int q[N];
int mi[N];
long long num[N];
void adde(int u,int v){
    ent++;
    to[ent]=v;
    nex[ent]=head[u];
    head[u]=ent;
}
int zuichang(int n){
    int m=0,l,r,mid,i;
    for(i=1;i<=n;i++){
        l = 0;r = m+1;
        while(l<r){
            mid = (l+r)>>1;
            if(mi[mid]>=q[i]){r = mid;}
            else{l = mid+1;}
        }
        if(l==m+1){m++;}
        mi[l]=q[i];
    }
    return m;
}
int main(){
    int n,i,c,t,b;
    long long ans=0,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&siz[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&c);
        adde(c,siz[i]);
        num[c]++;
    }
    for(i=1;i<=n;i++){
        for(c=head[i],b=num[i];c;c=nex[c],b--){
            q[b]=to[c];
        }
        a = zuichang(num[i]);
        ans = ans+(num[i]-a)*i;
    }
    printf("%lld",ans);
    return 0;
}