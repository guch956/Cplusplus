#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int P=10000;
struct juzhen{
    int m[2][2];
};
juzhen operator*(juzhen a,juzhen b){
    juzhen c;
    c.m[0][0]=(a.m[0][0]*b.m[0][0]+a.m[0][1]*b.m[1][0])%P;
    c.m[0][1]=(a.m[0][0]*b.m[0][1]+a.m[0][1]*b.m[1][1])%P;
    c.m[1][0]=(a.m[1][0]*b.m[0][0]+a.m[1][1]*b.m[1][0])%P;
    c.m[1][1]=(a.m[1][0]*b.m[0][1]+a.m[1][1]*b.m[1][1])%P;
    return c;
}
int power(int n){
    juzhen ans,a;
    ans.m[0][0]=1;
    ans.m[0][1]=0;
    ans.m[1][0]=0;
    ans.m[1][1]=1;
    a.m[0][0]=a.m[0][1]=a.m[1][0]=1;
    a.m[1][1]=0;
    while(n){
        if(n&1){ans=ans*a;}
        a = a*a;
        n = n>>1;
    }
    return ans.m[1][0];
}
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==-1){break;}
        printf("%d\n",power(n));
    }
    return 0;
}