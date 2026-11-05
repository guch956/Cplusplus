#include<iostream>
int dp[300][300],p[300],q[500][2],head=0,tail=0;
int dian[300][300];
int main(){
    using namespace std;
    int n,i,j,k,a,b;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>p[i];
    }
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            for(k=j;k<i+j;k++){
                a = dp[j][k]+dp[k+1][i+j]+(p[j]+p[i+j])*p[k];
                if(a>dp[j][i+j]){
                    dp[j][i+j] = a;
                    dian[j][i+j] = k;
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    q[tail][0] = 0;q[tail][1] = n-1;
    tail++;
    while(head<tail){
        a = q[head][0];
        b = q[head][1];
        head++;
        cout<<dian[a][b]+1<<' ';
        if(a<dian[a][b]){
            q[tail][0] = a;
            q[tail][1] = dian[a][b];
            tail++;
        }
        if(dian[a][b]+1<b){
            q[tail][0] = dian[a][b]+1;
            q[tail][1] = b;
            tail++;
        }
    }
    return 0;
}