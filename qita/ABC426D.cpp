#include<iostream>
#include<cstdio>
using namespace std;
char s[500003];
int main(){
    int n,T,i,ml0,ml1,num0,num1,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s);
        m = 0;num0=num1=ml0=ml1=0;
        for(i=0;i<n;i++){
            m++;
            if(s[i]=='0')num0++;
            else num1++;
            if(s[i]!=s[i+1]){
                if(s[i]=='0'){ml0=max(ml0,m);}
                else{ml1=max(ml1,m);}
                m=0;
            }
        }
        printf("%d\n",min(2*num1+num0-2*ml1,2*num0+num1-2*ml0));
    }
    return 0;
}