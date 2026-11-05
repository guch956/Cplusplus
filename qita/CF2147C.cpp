#include<iostream>
#include<cstdio>
using namespace std;
const int N=200009;
char s[N];
int main(){
    int n,T,i,xing,zaik,geshu;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        xing=1;
        zaik=0;
        scanf("%s",s+1);
        for(i=1;i<=n;i++){
            if(zaik==0){
                if(s[i-1]!='0' && s[i]=='1'){
                    zaik=1;
                    geshu=0;
                }
            }
            else{
                if(s[i]==s[i-1]){
                    if(s[i]=='1'){
                        if(geshu&1){xing=0;}
                        geshu=0;
                    }
                    else{
                        zaik=0;
                    }
                }
                else{
                    if(s[i]=='0'){geshu++;}
                }
            }
        }
        if(zaik && s[n]=='1' && (geshu&1)){xing=0;}
        if(xing){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}