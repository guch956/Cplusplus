#include<iostream>
#include<algorithm>
#include<cstring>
#define ull unsigned long long
using namespace std;
const ull P=131;
ull a[10003];
char s[1505];
ull BDKhash(char * s){
    ull H=0;
    int n=strlen(s),i;
    for(i=0;i<n;i++){
        H = H*P+s[i];
    }
    return H;
}
int main(){
    
}