#include<iostream>
const int WEI=100000000;
int cheng(int A[],int n,int x){
    int i,c=0,j,k,a,x1,b,d;
    for(i=0;i<=n;i++){
        a = WEI;
        x1 = x;
        k = 0;
        j = 0;
        d = 1;
        while(x1>0){
            b = (x1%10)*A[i];
            k += b/a;
            j += (b%a)*d;
            x1 = x1/10;
            a = a/10;
            d = d*10;
        }
        j+=c;
        k+=j/WEI;
        j = j%WEI;
        A[i] = j;
        c = k;
    }
    if(c>0){
        A[n+1] = c;
        return n+1;
    }
    return n;
}
void print(int A[],int n){
    int i,a,k;
    std::cout<<A[n];
    for(i=n-1;i>=0;i--){
        k = 0;
        a = A[i];
        while(a>0){
            a = a/10;
            k++;
        }
        k = 8-k;
        while(k>0){
            std::cout<<'0';
            k--;
        }
        std::cout<<A[i];
    }
}
int main(){
    using namespace std;
    int n,i,N,A[999];
    cin>>N;
    A[0] = 1;n = 0;
    for(i=0;i<=N;i++){
        n = cheng(A,n,2);
    }
    A[0]-=2;
    print(A,n);
    return 0;
}