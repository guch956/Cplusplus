#include<iostream>
#include<cstdio>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll P=1e9+7;
const int N=50000003;
bool A[N],B[N];
ll wa[2],ta0[2],sa0[2],sa[2],st[2];
ll wb[2],tb1[2],sb1[2],sb[2];
ll po2=1;
ll dp,sum;
int main(){
    int n,i,op,j,k;
    int now=1,old=0;
    ll ab,a,b;
    scanf("%d %d",&n,&op);
    if(op==0){
        for(i=1;i<=n;i++){
            scanf("%d %d",&A[i],&B[i]);
        }
    }
    else{
        ull x1,y1,z1,f1,f2;
        ull x2,y2,z2,g1,g2;
        ull a1,b1;
        scanf("%llu %llu %llu %llu %llu",&x1,&y1,&z1,&f1,&f2);
        scanf("%llu %llu %llu %llu %llu",&x2,&y2,&z2,&g1,&g2);
        i=-1;j=64;k=0;
        while(1){
            k++;
            j++;
            if(j==65){
                i++;
                j=1;
                f1=f1*x1+f2*y1+z1;
                swap(f1,f2);
                a1=f2;
                g1=g1*x2+g2*y2+z2;
                swap(g1,g2);
                b1=g2;
            }
            A[k]=a1&1;
            B[k]=b1&1;
            a1=a1>>1;
            b1=b1>>1;
            if(k>n){
                break;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(A[i]!=B[i]){ab=1;}
        else{ab=0;}
        a=0;
        if(A[i]){a=1;}
        wa[now]=(wa[old]+ab*sa[old]+ta0[old]*a+sa0[old]*ab*a)%P;
        sa[now]=(sa[old]+sa0[old]*a)%P;
        a = 1-a;
        ta0[now]=(ta0[old]+ab*sa0[old]+st[old]*a+po2*ab*a)%P;
        sa0[now]=(sa0[old]+po2*a)%P;
        st[now]=(st[old]+po2*ab)%P;
        b=1;
        if(B[i]){b=0;}
        wb[now]=(wb[old]+ab*sb[old]+b*tb1[old]+sb1[old]*ab*b)%P;
        sb[now]=(sb[old]+sb1[old]*b)%P;
        b=1-b;
        tb1[now]=(tb1[old]+ab*sb1[old]+st[old]*b+po2*ab*b)%P;
        sb1[now]=(sb1[old]+po2*b)%P;
        dp=(sum+wa[now]+wb[now])%P;
        sum=(sum+dp)%P;
        swap(now,old);
        po2=(po2*2)%P;
    }
    printf("%lld",dp);
    return 0;
}