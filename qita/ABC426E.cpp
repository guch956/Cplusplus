#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-8;
inline double dairu(double a,double b,double c,double x){
    return a*x*x+b*x+c;
}
double erci(double a,double b,double c,double l,double r){
    if(fabs(a)<eps){return min(dairu(0,b,c,l),dairu(0,b,c,r));}
    double t=-b/(2*a);
    if(l<=t && t<=r){return dairu(a,b,c,t);}
    else{return min(dairu(a,b,c,l),dairu(a,b,c,r));}
}
int main(){
    int T;
    double x1,y1,x2,y2,x3,y3,x4,y4,ans,d1,d2,a1,b1,c1,a2,b2,c2,p1,p2;
    scanf("%d",&T);
    while(T--){
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        scanf("%lf %lf %lf %lf",&x3,&y3,&x4,&y4);
        d1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        d2 = sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
        p1 = (x2-x1)/d1-(x4-x3)/d2;
        a1 = p1*p1;
        b1 = 2*p1*(x1-x3);
        c1 = (x1-x3)*(x1-x3);
        p2 = (y2-y1)/d1-(y4-y3)/d2;
        a2 = p2*p2;
        b2 = 2*p2*(y1-y3);
        c2 = (y1-y3)*(y1-y3);
        ans = erci(a1+a2,b1+b2,c1+c2,0,min(d1,d2));
        if(d1>d2){
            swap(d1,d2);
            swap(x1,x3);
            swap(x2,x4);
            swap(y1,y3);
            swap(y2,y4);
        }
        a1 = (x4-x3)/d2;
        b1 = 2*a1*(x3-x2);
        c1 = (x3-x2)*(x3-x2);
        a1 = a1*a1;
        a2 = (y4-y3)/d2;
        b2 = 2*a2*(y3-y2);
        c2 = (y3-y2)*(y3-y2);
        a2 = a2*a2;
        ans = min(ans,erci(a1+a2,b1+b2,c1+c2,d1,d2));
        if(ans<=0)ans=0;
        ans = sqrt(ans);
        printf("%.15lf\n",ans);
    }
    return 0;
}