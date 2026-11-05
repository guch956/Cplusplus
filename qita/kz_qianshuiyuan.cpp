#include<iostream>
int main(){
    using namespace std;
    int m,n,k,**p,**q,i,j,c,s,x,y;
    cin>>m>>n;
    cin>>k;
    p = new int*[k];
    for(i=0;i<k;i++){
        p[i] = new int[3];
        cin>>p[i][0]>>p[i][1]>>p[i][2];
    }
    q = new int*[m+1];
    for(i=0;i<=m;i++){
        q[i] = new int[n+1];
        for(j=0;j<=n;j++){
            q[i][j] = 99999999;
        }
    }
    q[0][0] = 0;
    for(c=0;c<k;c++){
        for(i=m;i>=0;i--){
            for(j=n;j>=0;j--){
                x = i-p[c][0]>=0?i-p[c][0]:0;
                y = j-p[c][1]>=0?j-p[c][1]:0;
                s = q[x][y]+p[c][2];
                q[i][j] = s>q[i][j]?q[i][j]:s;
            }
        }
    }
    cout<<q[m][n];
    return 0;
}