#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll m;
class juzhen{
public:
    ll shu[5][5];
    juzhen(){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                shu[i][j]=0;
            }
        }
    }
    juzhen operator *(juzhen B){
        juzhen C;
        int i,j,k;
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                for(k=0;k<5;k++){
                    C.shu[i][j] = shu[i][k]*B.shu[k][j]%m+C.shu[i][j];
                }
                C.shu[i][j]%=m;
            }
        }
        return C;
    }
};
int main(){
    ll n;
    juzhen a,ans;
    a.shu[0][0]=1;
    a.shu[0][1]=1;
    a.shu[1][1]=1;
    a.shu[1][2]=1;
    a.shu[1][3]=1;
    a.shu[1][4]=2;
    a.shu[2][1]=1;
    a.shu[3][3]=1;
    a.shu[3][4]=1;
    a.shu[4][3]=1;
    for(int i=0;i<5;i++){ans.shu[i][i]=1;}
    scanf("%lld %lld",&n,&m);
    while(n){
        if(n&1){
            ans = a*ans;
        }
        a = a*a;
        n = n>>1;
    }
    printf("%lld",(ans.shu[0][1]+ans.shu[0][3])%m);
    return 0;
}