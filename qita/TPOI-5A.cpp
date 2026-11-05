#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=200003;
const ll P=998244353;
ll le[N],weil[N];
ll ri[N],weir[N];
int p[N];
int chuli(int n,int * p1,ll * l,ll * w){
    int d=0,i;
    for(i=1;i<=n;i++){
        if(p1[i]!=p1[i-1]){
            l[++d]=p1[i];
            w[d]=i;
        }
    }
    return d;
}
int main(){
    ll sum,num,kong;
    int n,i,T,a,b,d,lnum,rnum,mi;
    scanf("%d",&T);
    p[0]=-1;
    le[0]=ri[0]=0x3f3f3f3f;
    while(T--){
        scanf("%d",&n);
        a = -1;d = 0;mi = 0;
        for(i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        lnum = chuli(n,p,le,weil);
        for(i=0;i<n;i++){
            scanf("%d",&p[n-i]);
        }
        rnum = chuli(n,p,ri,weir);
        num = 1;sum = 0;kong = 0;
        lnum--;rnum--;
        while(lnum || rnum){
            if(le[lnum]<ri[rnum]){
                sum = le[lnum]*(weil[lnum+1]-weil[lnum])%P*weir[rnum+1]%P+sum;
                sum%=P;
                for(a=mi+1;a<le[lnum];a++){
                    num = num*(kong--)%P;
                }
                kong += weil[lnum+1]-weil[lnum]-1;
                mi = le[lnum];
                lnum--;
            }
            else{
                sum = ri[rnum]*(weir[rnum+1]-weir[rnum])%P*weil[lnum+1]%P+sum;
                sum%=P;
                for(a=mi+1;a<ri[rnum];a++){
                    num = num*(kong--)%P;
                }
                kong += weir[rnum+1]-weir[rnum]-1;
                mi = ri[rnum];
                rnum--;
            }
        }
        for(a=mi+1;a<n;a++){num = num*(kong--)%P;}
        sum = (sum+n)%P;
        printf("%lld\n",sum*num%P);
    }
    return 0;
}