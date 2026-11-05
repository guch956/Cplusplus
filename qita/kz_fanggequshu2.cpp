#include<iostream>
int main(){
    using namespace std;
    int n,m,**p,*q,*r1,*r2,s,a,i,j;
    cin>>n>>m;
    p = new int*[n];
    q = new int[n];
    r1 = new int[n];
    r2 = new int[n];
    for(i=0;i<n;i++){
        p[i] = new int[m];
        for(j=0;j<m;j++){
            cin>>p[i][j];
        }
    }
    s = 0;
    for(i=0;i<n;i++){
        s+=p[i][0];
        q[i] = s;
    }
    for(j=1;j<m;j++){
        r1[0] = q[0]+p[0][j];
        for(i=1;i<n;i++){
            r1[i] = r1[i-1]>q[i]?r1[i-1]:q[i];
            r1[i]+=p[i][j];
        }
        r2[n-1] = q[n-1]+p[n-1][j];
        for(i=n-2;i>=0;i--){
            r2[i] = r2[i+1]>q[i]?r2[i+1]:q[i];
            r2[i]+=p[i][j];
        }
        for(i=0;i<n;i++){
            q[i] = r1[i]>r2[i]?r1[i]:r2[i];
        }
    }
    cout<<q[n-1];
    return 0;
}