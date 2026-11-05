#include<iostream>
#include<string>
const int WEI=100000000;
struct gaojing{
    int A[11]={0};
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
    for(i=0;i<=gao2.n+2;i++){
        gao3.A[i]=gao1.A[i]+gao2.A[i]+c;
        c = gao3.A[i]/WEI;
        gao3.A[i] %=WEI;
    }
    while(gao3.A[gao1.n+1]!=0){
        gao3.n++;
    }
}
gaojing max_(gaojing & gao1,gaojing & gao2){
    if(gao1.n != gao2.n){
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
/*void cheng2(gaojing & gao1,gaojing & gao2){
    gaojing g3,g4=gao1;
    int i,j;
    for(i=0;i<=gao1.n;i++){
        gao1.A[i]=0;
    }
    for(i=0;i<=gao2.n;i++){
        for(j=0;j<=g4.n;j++){
            g3.A[i+j]=g4.A[j];
        }
        for(j=0;j<i;j++){
            g3.A[j]=0;
        }
        g3.n=g4.n+i;
        cheng1(g3,gao2.A[i]);
        jia(gao1,g3);
    }
}*/
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
    int n,i,p=0,w=1,s;
    gaojing g1,g2;
    g1.A[0]=1;g2.A[0]=1;
    for(i=0;i<1000;i++){
        g1 = cheng1(g1,2);
    }
    /*for(i=0;i<500;i++){
        cheng1(g2,2);
    }*/
    print(g1);
    cout<<endl;
    /*print(g2);
    jia(g2,g1);
    cout<<endl;
    print(g1);*/
    return 0;
}