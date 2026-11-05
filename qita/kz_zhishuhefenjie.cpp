#include<iostream>
int A[201] = {0,0,1};
int jisuan(int n,int max){
    int s=0,i;
    if(n==0){
        return 1;
    }
    for(i=max;i>=2;i--){
        if(A[i] && i<=n && n!=i+1){
            s+=jisuan(n-i,i);
        }
    }
    return s;
}
int main(){
    using namespace std;
    int i,j,n;
    for(i=3;i<=200;i++){
        A[i]=1;
    }
    for(i=2;i<=200;i++){
        if(A[i]){
            for(j=2*i;j<=200;j+=i){
                A[j] = 0;
            }
        }
    }
    while(cin>>n && n!=EOF){
        cout<<n<<' ';
        cout<<jisuan(n,n)<<endl;
    }
    return 0;
}