#include<iostream>
int main(){
    using namespace std;
    int M,N,**p,*q,i,j,s;
    cin>>M>>N;
    p = new int*[N];
    for(i=0;i<N;i++){
        p[i] = new int[2];
        cin>>p[i][0]>>p[i][1];
    }
    q = new int[M+1];
    for(i=0;i<=M;i++){
        q[i] = 0;
    }
    for(i=0;i<N;i++){
        for(j=0;j<=M;j++){
            s = 0;
            if (j>=p[i][1]){
                s = q[j-p[i][1]]+p[i][0];
            }
            q[j] = s>q[j]?s:q[j];
        }
    }
    cout<<q[M];
    return 0;
}