#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N=3;
ll P;
struct juzhen{
    ll m[N][N];
};
juzhen operator*(juzhen a,juzhen b){
    juzhen c;
    int i,j,k;
    memset(c.m,0,sizeof(c.m));
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            for(k=0;k<N;k++){
                c.m[i][j]+=a.m[i][k]*b.m[k][j];
                c.m[i][j]=((c.m[i][j]%P)+P)%P;
            }
        }
    }
    return c;
}
ll power(int n){
    juzhen ans,a;
    memset(ans.m,0,sizeof(ans.m));
    memset(a.m,0,sizeof(a.m));
    ans.m[0][0]=ans.m[1][1]=ans.m[2][2]=1;
    a.m[0][0]=2;
    a.m[0][2]=-1;
    a.m[1][0]=1;
    a.m[2][1]=1;
    while(n){
        if(n&1){
            ans = ans*a;
        }
        a = a*a;
        n = n>>1;
    }
    return (2*ans.m[2][0]+ans.m[2][1])%P;
}
int main(){
    int n;
    scanf("%d %lld",&n,&P);
    printf("%lld",power(n));
    return 0;
}