#include<iostream>
#include<cstring>
using namespace std;
const int N=1003;
char str[N],pattern[N];
int Next[N];
int cnt;
void getnext(char * p,int plen){
    int i,j;
    Next[0]=Next[1]=0;
    for(i=1;i<plen;i++){
        j = Next[i];
        while(j && p[j]!=p[i]){j = Next[j];}
        if(p[j]==p[i]){Next[i+1]=j+1;}
        else{Next[i+1]=0;}
    }
}
void kmp(char * s,char * p){
    int i,j=0,slen=strlen(s),plen=strlen(p),last=-1;
    getnext(p,plen);
    for(i=0;i<slen;i++){
        while(j && p[j]!=s[i]){j = Next[j];}
        if(s[i]==p[j]){j++;}
        if(j==plen){
            if(i-last>=plen){
                cnt++;
                last=i;
            }
        }
    }
}
int main(){
    while(~scanf("%s",str)){
        if(str[0]=='#'){break;}
        scanf("%s",pattern);
        cnt=0;
        kmp(str,pattern);
        printf("%d\n",cnt);
    }
    return 0;
}