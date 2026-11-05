#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",2*n%3);
    }
    return 0;
}