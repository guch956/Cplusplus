#include<iostream>
#include<cstdio>
using namespace std;
int num[26];
int gcd(int a,int b){
    if(b==0){return a;}
    return gcd(b,a%b);
}
int main(){
    int T,i,n,k,j,nu,g,ans,p;
    char c;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        ans = 0;
        for(i=1;i<=n;i++){
            c = getchar();
            while(c<'a' || c>'z'){c = getchar();}
            num[c-'a']++;
        }
        for(i=1;i<=n;i++){
            g = gcd(i,k%i);
            p = i/g;
            nu=0;
            for(j=0;j<26;j++){
                nu += num[j]/p;
            }
            if(nu>=g){ans = i;}
        }
        printf("%d\n",ans);
        for(i=0;i<26;i++){num[i]=0;}
    }
    return 0;
}