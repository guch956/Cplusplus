#include<iostream>
#include<cstdio>
using namespace std;
const int N=800003;
int zhi[N];
int zhan[N];
int main(){
    int i,q,top=0,typ,zuida=0;
    char c;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&typ);
        if(typ==1){
            c = getchar();c = getchar();
            if(c=='(')zhi[++zuida]=1;
            else zhi[++zuida]=-1;
            zhi[zuida]+=zhi[zuida-1];
            if(zhi[zuida]<0){zhan[++top]=zuida;}
        }
        else{
            if(zhan[top]==zuida)top--;
            zuida--;
        }
        if(top==0 && zhi[zuida]==0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}