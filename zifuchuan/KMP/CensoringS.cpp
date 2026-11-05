#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000003;
char s[N],pattern[N];
int Next[N];
int zhan[N];
int pipei[N];
void getNext(char * p,int plen){
    int i,j;
    Next[0]=Next[1]=0;
    for(i=1;i<plen;i++){
        j = Next[i];
        while(j && p[i]!=p[j]){j = Next[j];}
        if(p[i]==p[j]){Next[i+1]=j+1;}
        else{Next[i+1]=j;}
    }
}
int main(){
    int n,i=0,j=0,top=0,pl;
    scanf("%s",s);
    n = strlen(s);
    scanf("%s",pattern);
    pl = strlen(pattern);
    getNext(pattern,pl);
    for(i=0;i<n;i++){
        zhan[++top]=i;
        while(j && s[i]!=pattern[j]){
            j=Next[j];
        }
        if(s[i]==pattern[j]){j++;}
        if(j==pl){
            top = top-pl;
            j = pipei[zhan[top]];
        }
        else{
            pipei[i]=j;
        }
    }
    for(i=1;i<=top;i++){
        printf("%c",s[zhan[i]]);
    }
    return 0;
}
