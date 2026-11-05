#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=15003;
int Next[N];
int xing[N];
char s[N];
int ans=0,k;
void getNext(char * s,int slen){
    int i,j=0;
    Next[0]=Next[1]=0;
    for(i=1;i<slen;i++){
        j = Next[i];
        while(j && s[j]!=s[i]){j = Next[j];}
        if(s[j]==s[i]){Next[i+1]=j+1;}
        else{Next[i+1]=j;}
        if(xing[Next[i+1]]){
            xing[i+1]=xing[Next[i+1]];
        }
        else{
            if(Next[i+1]>=k){
                xing[i+1]=Next[i+1];
            }
            else{
                xing[i+1]=0;
            }
        }
        if(xing[i+1] && i>=2*xing[i+1]){
            ans++;
        }
    }
}
int main(){
    int n,i;
    scanf("%s",s);
    scanf("%d",&k);
    n = strlen(s);
    for(i=0;i<n;i++){
        getNext(s+i,n-i);
    }
    printf("%d",ans);
    return 0;
}