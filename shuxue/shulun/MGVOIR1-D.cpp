#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=75000;
const ll P=1e9+7;
int ispri[N];
int pri[N],ent;
ll jiec[N];
ll sushu[40];
ll mici[40];
ll mi[N<<1];
int num;
ll quick(ll a,ll b){
    ll an=1;
    while(b){
        if(b&1){an = an*a%P;}
        a = a*a%P;
        b = b>>1;
    }
    return an;
}
void init(){
    int i,j,k;
    for(i=2;i<N;i++){
        if(!ispri[i]){
            pri[ent++]=i;
        }
        for(j=0;j<ent;j++){
            k = pri[j]*i;
            if(k>=N){break;}
            ispri[k]=1;
            if(i%pri[j]==0){break;}
        }
    }
}
void yuchuli(ll p,int x){
    int i;
    mi[0]=1;
    for(i=1;i<=x;i++){
        mi[i]=mi[i-1]*p%P;
    }
}
void fenjie(int x){
    num=0;
    for(int i=0;i<ent;i++){
        if(x%pri[i]==0){
            sushu[++num]=pri[i];
            mici[num]=0;
            while(x%pri[i]==0){
                mici[num]++;
                x = x/pri[i];
            }
        }
        if(x==1){return ;}
    }
    if(x>1){
        sushu[++num]=x;
        mici[num]=1;
    }
}
int main(){
    int i,T,j;
    ll a,b,c;
    ll ans,sum,sum2,sum1;
    init();
    jiec[0]=1;
    for(i=1;i<N;i++){
        jiec[i]=jiec[i-1]*i%P;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&a,&b);
        ans=1;
        fenjie(a);
        for(i=1;i<=num;i++){mici[i]=mici[i]*b;ans=ans*jiec[mici[i]]%P;}
        printf("%lld ",ans);
        sum = quick(a,2*b);
        sum2=1;ans=1;
        for(i=1;i<=num;i++){
            c = (mici[i]+1)*(mici[i]+2)/2;
            c = c%P;
            sum2 = sum2*c%P;
        }
        for(i=1;i<=num;i++){
            yuchuli(sushu[i],2*mici[i]);
            sum1=0;
            for(j=0;j<=mici[i];j++){
                sum1 = (mi[2*j]*jiec[j]%P*(mi[mici[i]+1-j]+P-1)%P+sum1)%P;
            }
            sum1 = sum1*quick(sushu[i]-1,P-2)%P;
            ans=(ans*sum1)%P;
        }
        printf("%lld\n",(sum-sum2+ans+P)%P);
    }
    return 0;
}