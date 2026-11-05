#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000003;
int nex[N];
char s1[N],s2[N];
void getnex(char * s,int slen){
    int i,j;
    nex[0]=nex[1]=0;
    for(i=1;i<slen;i++){
        j = nex[i];
        while(j && s[i]!=s[j]){j = nex[j];}
        if(s[i]==s[j]){nex[i+1]=j+1;}
        else{nex[i+1]=0;}
    }
}
int main(){
    int i,j,n,t=0,k=0,l;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s2);
        l = strlen(s2);
        getnex(s2,l);
        t = max(0,k-l);
        j = 0;
        for(i=t;i<k;i++){
            while(j && s1[i]!=s2[j]){j = nex[j];}
            if(s1[i]==s2[j]){j++;}
        }
        i-=j;
        for(j=0;j<l;j++){
            s1[j+i]=s2[j];
        }
        k = i+l;
    }
    for(i=0;i<k;i++){
        printf("%c",s1[i]);
    }
    return 0;
}
