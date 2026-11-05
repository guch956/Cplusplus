#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000003;
int nex[N];
char s1[N],s2[N];
void getnex(char * s){
    int i,l=strlen(s),j;
    nex[0]=nex[1]=0;
    for(i=1;i<l;i++){
        j=nex[i];
        while(j && s[i]!=s[j]){j = nex[j];}
        if(s[j]==s[i]){nex[i+1]=j+1;}
        else{nex[i+1]=0;}
    }
}
int main(){
    int i,j=0,l2,l1;
    scanf("%s",s1);
    scanf("%s",s2);
    l1=strlen(s1);
    l2=strlen(s2);
    getnex(s2);
    for(i=0;i<l1;i++){
        while(j && s1[i]!=s2[j]){j = nex[j];}
        if(s1[i]==s2[j]){j++;}
        if(j==l2){
            printf("%d\n",i-l2+2);
        }
    }
    for(i=1;i<=l2;i++){
        printf("%d ",nex[i]);
    }
    return 0;
}