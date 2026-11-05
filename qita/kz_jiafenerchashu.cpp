#include<iostream>
using namespace std;
int q2[32][32];
void print(int l,int r){
    cout<<q2[l][r]<<' ';
    if(q2[l][r]>l){
        print(l,q2[l][r]-1);
    }
    if(r>q2[l][r]){
        print(q2[l][r]+1,r);
    }
}
int main(){
    int n,*p,**q1,i,j,k,a,b,s,c,d;
    cin>>n;
    p = new int[n+1];
    q1 = new int*[n+2];
    for(i=1;i<=n;i++){
        cin>>p[i];
        q1[i] = new int[n+1];
    }
    q1[0] = new int[n+1];
    q1[n+1] = new int[n+1];
    q2[0][0] = 0;
    q1[1][0] = 1;
    q1[n+1][n] = 1;
    for(i=1;i<=n;i++){
        q1[i][i] = p[i];
        q1[i][i-1] = 1;
        q2[i][i] = i;
    }
    for(i=1;i<=n-1;i++){
        for(j=1;j+i<=n;j++){
            s = 0;
            for(k=j;k<=i+j;k++){
                a = q1[j][k-1]*q1[k+1][i+j]+p[k];
                c = q1[j][k-1];d = q1[k+1][i+j];
                if(a>s){
                    s = a;
                    b = k;
                }
            }
            q1[j][i+j] = s;
            q2[j][i+j] = b;
        }
    }
    cout<<q1[1][n]<<endl;
    print(1,n);
    return 0;
}