#include<iostream>
int main(){
    using namespace std;
    int n,i,j,m,k,g,a,h,**p,*q,**r1,**r2,*t;
    cin>>n>>m;
    p = new int*[n];
    t = new int[n];
    for(i=n-1;i>=0;i--){
        cin>>t[i]>>j;
        p[i] = new int[j+1];
        for(k=1;k<=j;k++){
            cin>>p[i][k];
        }
        p[i][0] = j;
    }
    q = new int[m+1];
    r1 = new int*[m+1];
    r2 = new int*[m+1];
    r1[0] = 0;r2[0] = 0;
    for(i=0;i<=m;i++){
        q[i] = 0;
        r1[i] = new int[n];
        r2[i] = new int[n];
    }
    for(i=0;i<n;i++){
        for(j=m;j>=0;j--){
            k = 1;
            h = 0;
            g = 0;
            a = 0;
            while(k<=p[i][0] && k*t[i]<=j){
                a = q[j-k*t[i]]+p[i][k];
                if(a>h){
                    h = a;
                    g = k;
                }
                k++;
            }
            if(h>q[j]){
                r1[j][i] = i+1;
                r2[j][i] = g;
                q[j] = h;
            }
            else{
                r1[j][i] = r1[j][i-1];
                r2[j][i] = r2[j][i-1];
            }
        }
    }
    cout<<q[m]<<endl;
    g = m;
    while(q[g]==q[m]){
        g--;
    }
    g++;
    k = n-1;
    while(g>0){
        h = k;
        for(j=r1[g][h];j<=h;j++){
            cout<<0<<endl;
            k--;
        }
        cout<<r2[g][h]<<endl;
        a = g-t[r1[g][h]-1]*r2[g][h];
        i = g;
        g = a;
        k--;
    }
    for(j=0;j<=k;j++){
        cout<<0<<endl;
    }
    return 0;
}