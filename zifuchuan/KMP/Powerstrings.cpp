#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000003;
char s[N];
int Next[N];
void getnext(char * s,int slen){
    int i,j=0;
    Next[0]=Next[1]=0;
    for(i=1;i<slen;i++){
        j = Next[i];
        while(j && s[i]!=s[j]){j=Next[j];}
        if(s[i]==s[j]){Next[i+1]=j+1;}
        else{Next[i+1]=j;}
    }
}
int main(){
    int n,a;
    while(~scanf("%s",s)){
        if(s[0]=='.'){break;}
        n = strlen(s);
        getnext(s,n);
        a = n-Next[n];
        if(n%a==0){
            printf("%d\n",n/a);
        }
        else{
            printf("1\n");
        }
    }
    return 0;
}