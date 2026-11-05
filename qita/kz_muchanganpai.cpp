#include<iostream>
int A[1000],d=0, di[20],dp[15][500];
void jisuan(int n){
    int i;
    for(i=0;i<1<<n;i++){
        if(((i<<1)&i) == 0){
            A[d]=i;
            d++;
        }
    }
}
int main(){
    using namespace std;
    int n,m,i,j,a,b,s;
    cin>>m>>n;
    jisuan(n);
    for(j=0;j<m;j++){
        a = 1;
        s=0;
        for(i=0;i<n;i++){
            cin>>b;
            b = 1-b;
            s+=a*b;
            a = a*2;
        }
        di[j]=s;
    }
    for(i=0;i<d;i++){
        if((A[i]&di[0]) == 0){
            dp[0][i]=1;
        }
    }
    for(i=1;i<m;i++){
        for(j=0;j<d;j++){
            if( (A[j]&di[i]) == 0){
                for(a=0;a<d;a++){
                    if ((A[j]&A[a]) == 0){
                        dp[i][j] = (dp[i-1][a]+dp[i][j])%100000000;
                    }
                }
            }
        }
    }
    s = 0;
    for(i=0;i<d;i++){
        s+=dp[m-1][i];
        s = s% 100000000;
    }
    cout<<s;
    return 0;
}