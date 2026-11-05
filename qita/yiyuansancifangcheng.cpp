#include<cstdio>
double f[4];
inline double fx(double x){
    double t=0,s = 1;
    for(int i=0;i<=3;i++){
        t+=f[i]*s;
        s = s*x;
    }
    return t;
}
double erfen(double a,double b){
    double p = (b-a)*1000,s = 1,m1,a1=a,b1=b;
    while(s<p){
        m1 = (a1+b1)/2;
        if (fx(a1)*fx(m1)>0){
            a1 = m1;
        }
        else{
            b1 = m1;
        }
        s = s*2;
    }
    return a1;
}
int main(){
    using namespace std;
    int i;
    double n,l,r,c;
    for(i=3;i>=0;i--){
        scanf("%lf",&f[i]);
    }
    l = -100;
    n = fx(l);
    for(r=-99;r<=100;r++){
        if (fx(r)*n<=0){
            c = erfen(l,r+0.5);
            printf("%.2f ",c);
            l = r+0.5;
            n = fx(l);
        }
    }
    return 0;
}