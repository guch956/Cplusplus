#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
class gaojing{
    public:
        ll shu[4];
        gaojing(){shu[0]=shu[1]=shu[2]=shu[3]=0;}
        void fuzhi(int i,ll a){shu[i]=a;}
        void print();
        gaojing operator+(gaojing & g1);
        gaojing operator*(gaojing & g1);
        gaojing min(gaojing g1);
};
void gaojing::print(){
    int i=3,j;
    ll a;
    while(i>=0 && shu[i]==0){i--;}
    if(i==-1){cout<<0;}
    cout<<shu[i];
    i--;
    while(i>=0){
        a = shu[i];
        j = 9;
        while(a){a = a/10;j--;}
        while(j){cout<<0;j--;}
        cout<<shu[i];
        i--;
    }
}
gaojing gaojing::operator+(gaojing & g1){
    gaojing g2;
    int i;ll jin=0;
    for(i=0;i<4;i++){
        g2.fuzhi(i,(shu[i]+g1.shu[i]+jin)%1000000000);
        jin=(shu[i]+g1.shu[i]+jin)/1000000000;
    }
    return g2;
}
gaojing gaojing::operator*(gaojing & g1){
    gaojing g2;
    int i,j;ll zhi,jin=0;
    for(i=0;i<4;i++){
        zhi=jin;
        jin=0;
        for(j=0;j<=i;j++){
            zhi+=(shu[j]*g1.shu[i-j])%1000000000;
            jin+=shu[j]*g1.shu[i-j]/1000000000;
        }
        jin+=zhi/1000000000;
        zhi=zhi%1000000000;
        g2.fuzhi(i,zhi);
    }
    return g2;
}
gaojing gaojing::min(gaojing g1){
    for(int i=3;i>=0;i--){
        if(shu[i]<g1.shu[i]){
            return *this;
        }
        if(g1.shu[i]<shu[i]){
            return g1;
        }
    }
    return g1;
}
gaojing dp[52][52];
gaojing p[52];
int main(){
    int n,i,j,k,d;
    ll a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a);
        p[i].fuzhi(0,a);
    }
    for(d=2;d<n;d++){
        for(i=1;i<=n-d;i++){
            j = i+d;
            dp[i][j]=p[i]*p[i+1]*p[j]+dp[i+1][j];
            for(k=i+2;k<j;k++){
                dp[i][j]=dp[i][j].min(p[i]*p[k]*p[j]+dp[i][k]+dp[k][j]);
            }
        }
    }
    dp[1][n].print();
    return 0;
}