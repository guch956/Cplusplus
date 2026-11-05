#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int rudu[N];
int edge[N][2];
int main(){
    int n,i,num=0,a=0,b=3;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&edge[i][0],&edge[i][1]);
        rudu[edge[i][0]]++;
        rudu[edge[i][1]]++;
    }
    for(i=1;i<=n;i++){
        if(rudu[i]==1){num++;}
    }
    if(num==2){
        for(i=0;i<n-1;i++){printf("%d\n",i);}
    }
    else{
        for(i=0;i<n-1;i++){
            if(rudu[edge[i][0]]==1 || rudu[edge[i][1]]==1){
                if(a<3){printf("%d\n",a++);}
                else{printf("%d\n",b++);}
            }
            else{printf("%d\n",b++);}
        }
    }
    return 0;
}