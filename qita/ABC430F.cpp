#include<iostream>
#include<cstdio>
using namespace std;
const int N=300003;
const int INF=0x3f3f3f3f;
int ans[N];
char s[N];
int lef[N],rig[N];
int main(){
    int n,T,i,last,j;
    char c;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s+1);
        c = s[1];
        s[n]='y';last = 1;
        for(i=1;i<=n;i++){
            ans[i]=0;
            lef[i]=0;
            rig[i]=0;
            if(s[i]!=c){
                if(c=='L'){
                    for(j=last;j<=i;j++){
                        lef[j] += i-j;
                        rig[j] += j-last;
                    }
                }
                else{
                    for(j=last;j<=i;j++){
                        lef[j] += j-last;
                        rig[j] += i-j;
                    }
                }
                last = i;
                c = s[i];
            }
        }
        for(i=1;i<=n;i++){
            ans[lef[i]+1]++;
            ans[n-rig[i]+1]--;
        }
        for(i=1;i<=n;i++){
            ans[i] = ans[i]+ans[i-1];
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}