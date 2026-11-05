#include<iostream>
const int WEI=100000000;
struct gaojing{
    int A[15]={0};
    int n=0;
};
gaojing cheng1(gaojing & gao,int x){
    int i,c=0,j,k,a,x1,b,d;
    gaojing gao2;
    gao2.n=gao.n;
    for(i=0;i<=gao.n;i++){
        a = WEI;
        x1 = x;
        k = 0;
        j = 0;
        d = 1;
        while(x1>0){
            b = (x1%10)*gao.A[i];
            k += b/a;
            j += (b%a)*d;
            x1 = x1/10;
            a = a/10;
            d = d*10;
        }
        j+=c;
        k+=j/WEI;
        j = j%WEI;
        gao2.A[i] = j;
        c = k;
    }
    if(c>0){
        gao2.n++;
        gao2.A[gao2.n] = c;
    }
    return gao2;
}
gaojing jia(gaojing & gao1,gaojing & gao2){
    int i,c=0,x;
    gaojing gao3;
    gao3.n=gao1.n;
    for(i=0;i<=14;i++){
        gao3.A[i]=gao1.A[i]+gao2.A[i]+c;
        c = gao3.A[i]/WEI;
        gao3.A[i] %=WEI;
    }
    while(gao3.A[gao3.n+1]!=0){
        gao3.n++;
    }
    return gao3;
}
gaojing max_(gaojing & gao1,gaojing & gao2){
    if(gao1.n == gao2.n){
        int i=gao1.n;
        while(gao1.A[i]==gao2.A[i]){
            i--;
            if(i==-1){
                return gao1;
            }
        }
        if(gao1.A[i]>gao2.A[i]){
            return gao1;
        }
        return gao2;
    }
    else{
        if(gao1.n>gao2.n){
            return gao1;
        }
        else{
            return gao2;
        }
    }
}
void chongzhi(gaojing & g){
    for(int i=0;i<=g.n;i++){
        g.A[i]=0;
    }
    g.n=0;
}
void print(gaojing & gao){
    int i,a,k;
    std::cout<<gao.A[gao.n];
    for(i=gao.n-1;i>=0;i--){
        k = 0;
        a = gao.A[i];
        while(a>0){
            a = a/10;
            k++;
        }
        k = 8-k;
        while(k>0){
            std::cout<<'0';
            k--;
        }
        std::cout<<gao.A[i];
    }
}
int main(){
    using namespace std;
    int n,m,i,j,k,*q;
    gaojing a,**p,b,c,d,s,total;
    cin>>n>>m;
    q = new int[m+1];
    p = new gaojing*[m+1];
    for(i=0;i<=m;i++){
        p[i] = new gaojing[m+1];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>q[j];
        }
        a.A[0] = 2;
        for(j=1;j<=m;j++){
            c = cheng1(a,q[j]);
            p[j][0] = jia(p[j-1][0],c);
            c = p[j][0];
            c = cheng1(a,q[m+1-j]);
            p[0][j] = jia(p[0][j-1],c);
            a = cheng1(a,2);
        }
        chongzhi(a);
        a.A[0] = 4;
        chongzhi(c);
        for(j=1;j<=m-1;j++){
            b = a;
            for(k=1;k<=m-j;k++){
                c = cheng1(b,q[j]);c = jia(c,p[j-1][k]);
                d = cheng1(b,q[m+1-k]);d = jia(d,p[j][k-1]);
                p[j][k] = max_(c,d);
                b = cheng1(b,2);
            }
            a = cheng1(a,2);
        }
        for(j=0;j<=m;j++){
            s = max_(s,p[j][m-j]);
        }
        total=jia(s,total);
        chongzhi(s);
        chongzhi(c);
        chongzhi(d);
        chongzhi(a);
        chongzhi(b);
    }
    print(total);
    return 0;
}