#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int s,deep,d;
    while(1){
        scanf("%d",&s);
        if(s/10000){
            printf("up\n");
            fflush(stdout);
        }
        else{break;}
    }
    printf("app\n");
    fflush(stdout);
    scanf("%d",&deep);
    while(deep--){
        if((s/100%10)==0){
            printf("downleft\n");
            fflush(stdout);
            scanf("%d",&s);
        }
        else if((s/10%10)==0){
            printf("downright\n");
            fflush(stdout);
            scanf("%d",&s);
        }
        else{
            printf("downright\n");
            fflush(stdout);
            scanf("%d",&s);
            printf("app\n");
            fflush(stdout);
            scanf("%d",&d);
            if(d!=deep){
                printf("left\n");
                fflush(stdout);
                scanf("%d",&s);
            }
        }
    }
    printf("here\n");
    fflush(stdout);
    return 0;
}