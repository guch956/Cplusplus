#include<iostream>
#include<string>
int p[1000][200][201];
using namespace std;
int n,m,k;
string s1,s2;
int jisuan(int n,int m,int k){
    if(p[n][m][k]!=-1){
        return p[n][m][k];
    }
    if(k==1){
        int i=-1;
        p[n][m][k]=0;
        while (1)
        {
            i = s1.find(s2.substr(0,m+1),i+1);
            if(i>n-m || i==string::npos){
                break;
            }
            p[n][m][k]++;
        }
        
        return p[n][m][k];    
    }
    else{
        p[n][m][k]=0;
        int i,s=0;
        for(int c=n;c>=m;c--){ 
            for(i=m;i>=1;i--){
                if(s1[c+i-m]==s2[i]){
                    s = (s+jisuan(c+i-m-1,i-1,k-1))%1000000007;
                }
                else{
                    break;
                }
            }
        }
        p[n][m][k]=s;
        return s;
    }
}
int main(){
    int answer=0;
    cin>>n>>m>>k;
    cin>>s1>>s2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int l=0;l<=k;l++){
                p[i][j][l]=-1;
            }
        }
    }
    answer = jisuan(n-1,m-1,k);
    cout<<answer;
    return 0;
}