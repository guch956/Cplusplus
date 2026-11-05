#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
char s[N];
int main(){
    int T,n,i,num1,num2,d;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s);
        num1 = num2 = 0;
        d = 0;
        s[n]=s[0];
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                num2++;
            }
            else{
                num1++;
            }
            if(s[i]!=s[i+1]){d++;}
        }
        if(d==0){
            if(s[0]=='0'){printf("Robin");}
            else{printf("Sunday");}
        }
        else if(d==2){
            printf("Robin");
        }
        else{
            if(num2>=num1)printf("Sunday");
            else printf("Robin");
        }
        printf("\n");
    }
    return 0;
}