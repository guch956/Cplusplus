#include<iostream>
int main(){
    using namespace std;
    int a1,a2,a3,a4,a5,a6,s,*p,i,j,A[7]={0,1,2,3,5,10,20},B[7];
    for(i=1;i<=6;i++){
        cin>>B[i];
    }
    s = 0;
    for(i=1;i<=6;i++){
        s += A[i]*B[i];
    }
    p = new int[s+1];
    p[0] = 1;
    for(i=1;i<=s;i++){
        p[i] = 0;
    }
    for(j=1;j<=6;j++){
        for(i=s;i>=0;i--){
            if (p[i]==1){
                for(A[0]=1;A[0]<=B[j];A[0]++){
                    p[i+A[0]*A[j]] = 1;
                }
            }
        }
    }
    A[0] = 0;
    for(i=1;i<=s;i++){
        A[0]+=p[i];
    }
    cout<<"Total="<<A[0];
    return 0;
}