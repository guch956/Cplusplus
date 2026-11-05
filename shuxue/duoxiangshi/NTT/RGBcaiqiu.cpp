#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1050000;
const ll P=998244353;
ll gg=3,w;
ll jiecheng[N],ni[N];
ll R[N],G[N],B[N];
ll R1[N],G1[N],B1[N];
int rev[N];
ll quick(ll a,ll x){
    ll an=1;
    while(x){
        if(x&1){
            an = (a*an)%P;
        }
        a = (a*a)%P;
        x = x>>1;
    }
    return an;
}
void init(int n){
    int i;
    ll q,r;
    jiecheng[1]=ni[1]=1;
    jiecheng[0]=ni[0]=1;
    for(i=2;i<=n;i++){
        r = P%i;
        q = (P-r)/i;
        q = P-q;
        ni[i]=(q*ni[r])%P;
    }
    for(i=2;i<=n;i++){
        jiecheng[i]=(jiecheng[i-1]*i)%P;
        ni[i]=(ni[i-1]*ni[i])%P;
    }
}
void NTT(int n,ll * p){
    int i,j,k,t=2;
    ll ww,c,www;
    for(i=1;t<=n;i++,t=t<<1){
        ww = quick(w,n/t);
        for(j=0;j<n;j+=t){
            www = 1;
            for(k=0;2*k<t;k++){
                c = p[j+k+t/2];
                p[j+k+t/2]=((p[j+k]-www*c)%P+P)%P;
                p[j+k]=(p[j+k]+www*c)%P;
                www = (www*ww)%P;
            }
        }
    }
}
int main(){
    int r,g,b,k,x,y,z,n=1,i,c,d,f;
    scanf("%d %d %d %d",&r,&g,&b,&k);
    scanf("%d %d %d",&x,&y,&z);
    x = k-x;
    y = k-y;
    z = k-z;
    while(n<=3*k){
        n = n<<1;
    }
    for(i=0;i<n;i++){
        c=i;
        d=0;
        f = n>>1;
        while(c){
            if(c&1){
                d+=f;
            }
            c = c>>1;
            f = f>>1;
        }
        rev[i]=d;
    }
    init(max(n,max(r,max(g,b))));
    w = quick(gg,(P-1)/n);
    for(i=x;i<=min(k,b);i++){
        B[i]=((jiecheng[b]*ni[i])%P*ni[b-i])%P;
    }
    for(i=y;i<=min(k,r);i++){
        R[i]=((jiecheng[r]*ni[i])%P*ni[r-i])%P;
    }
    for(i=z;i<=min(k,g);i++){
        G[i]=((jiecheng[g]*ni[i])%P*ni[g-i])%P;
    }
    for(i=0;i<n;i++){
        R1[i]=R[rev[i]];
        G1[i]=G[rev[i]];
        B1[i]=B[rev[i]];
    }
    NTT(n,R1);
    NTT(n,G1);
    NTT(n,B1);
    for(i=0;i<n;i++){
        R1[i]=((R1[i]*G1[i])%P*B1[i])%P;
    }
    for(i=0;i<n;i++){
        G1[rev[i]]=R1[i];
    }
    w = quick(w,P-2);
    NTT(n,G1);
    w = quick(n,P-2);
    printf("%lld",(G1[k]*w)%P);
    return 0;
}
