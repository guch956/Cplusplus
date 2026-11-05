#include<iostream>
#include<cstdio>
int C[32][32];
int num[33];
int k,b;
using namespace std;
void jisuan(){
    int i,j;
    for(i=0;i<=31;i++){
        C[i][0]=1;
    }
    for(j=1;j<=31;j++){
        for(i=j;i<=31;i++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
int dfs(int pos,int k,bool limit){
    if(!pos){
        return k==0;
    }
    if(!limit){return C[pos][k];}
    int i,up=limit?num[pos]:1,ans=0;
    for(i=0;i<=up;i++){
        ans+=dfs(pos-1,k-(i==1),limit && i==up);
    }
    return ans;
}
int solve(int x){
    int len=0,pow=1,a=k,i;
    while(pow<=x){
        len++;
        pow=pow*b;
    }
    pow=pow/b;
    for(i=len;i>=1;i--){
        if(x>=pow && a){
            num[i]=1;
            x = x-pow;
            a--;
        }
        else{num[i]=0;}
        pow=pow/b;
    }
    if(a){return 0;}
    return dfs(len,k,1);
}
int main(){
    int x,y;
    cin>>x>>y>>k>>b;
    jisuan();
    cout<<solve(y)-solve(x-1);
    return 0;
}