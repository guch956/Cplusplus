#include<iostream>
int wei[7] = {1,3,9,27,81,243,729};
int A[50],d,m;
int dp[10005][50];
bool anweihe(int a,int b,int p){
    int i=p,x=a,y=b;
    while(i>0){
        i--;
        if(x%3==y%3){
            return 1;
        }
        x = x/3;
        y = y/3;
    }
    return 0;
}
void jisuan(int n){
    int i;
    for(i=0;i<wei[n];i++){
        if(anweihe(i/3,i,m-1)==0){
            A[d] = i;
            d++;
        }
    }
}
int main(){
    using namespace std;
    int n,i,j,k,x=0,a,y=-1,ans=0;
    cin>>n>>m>>k;
    jisuan(m);
    for(i=0;i<m;i++){
        cin>>a;
        x = x*3+(a-1);
    }
    for(i=0;i<d;i++){
        dp[1][i] = 1;
        if(A[i]==x){
            y = i;
        }
    }
    if(y==-1){
        cout<<0;
        return 0;
    }
    for(i=2;i<k;i++){
        for(j=0;j<d;j++){
            for(a=0;a<d;a++){
                if(anweihe(A[a],A[j],m)==0){
                    dp[i][j]=(dp[i][j]+dp[i-1][a])%1000000;
                }
            }
        }
    }
    for(i=0;i<d;i++){
        if(A[i]!=x){
            dp[k][i] = 0;
        }
    }
    for(a=0;a<d;a++){
        if(anweihe(x,A[a],m)==0){
            dp[k][y]=(dp[k][y]+dp[k-1][a])%1000000;
        }
    }
    for(i=k+1;i<=n;i++){
        for(j=0;j<d;j++){
            for(a=0;a<d;a++){
                if(anweihe(A[j],A[a],m)==0){
                    dp[i][j]=(dp[i][j]+dp[i-1][a])%1000000;
                }
            }
        }
    }
    for(i=0;i<d;i++){
        ans = (ans+dp[n][i])%1000000;
    }
    cout<<ans;
    return 0;
}