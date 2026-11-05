#include<iostream>
bool A[201][201];
int B[201];
int C[201];
int D[201];
int main(){
    using namespace std;
    int n,i,x=1,y,j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>B[i];
    }
    while(x!=0){
        cin>>x>>y;
        A[x][y]=1;
    }
    C[n] = B[n];
    for(i=n-1;i>=1;i--){
        C[i]=0;
        for(j=i+1;j<=n;j++){
            if(A[i][j]){
                if(C[j]>C[i]){
                    D[i]=j;
                    C[i] = C[j];
                }
            }
        }
        C[i]+=B[i];
    }
    y = 0;
    for(i=1;i<=n;i++){
        if(C[i]>y){
            y = C[i];
            x = i;
        }
    }
    while(1){
        cout<<x;
        if(D[x]!=0){
            cout<<'-';
            x = D[x];
        }
        else{
            break;
        }
    }
    cout<<endl<<y;
    return 0;
}