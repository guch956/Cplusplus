#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2200000;
struct node{
    int val;
    int isend;
}p[2][N];
int m,k;
int ent[2];
int A[2][33];
int n[2];
int sum,is;
bool bijiao(node & n1,node & n2){
    return n1.val<n2.val;
}
void dfs(int last){
    if(last<=0){
        if(k==1 && sum==0)sum=m;
        p[k][++ent[k]].val=sum;
        p[k][ent[k]].isend=is;
        return ;
    }
    dfs(last-1);
    sum = (sum+A[k][last])%m;
    dfs(last-2);
    sum = (sum-A[k][last]+m)%m;
}
int main(){
    int nn,i,j;
    long long ans=0,num0,num00,num1,num11;
    scanf("%d %d",&nn,&m);
    n[0]=(nn+1)>>1;n[1]=nn>>1;
    for(i=1;i<=n[0];i++)scanf("%d",&A[0][i]);
    for(i=n[1];i>=1;i--)scanf("%d",&A[1][i]);
    if(nn==1){
        if(A[0][1]==0){ans=2;}
        else ans = 1;
    }
    else{
        sum = 0;is = 0;
        dfs(n[0]-1);
        sum = A[0][n[0]];is = 1;
        dfs(n[0]-2);
        k = 1;
        sum = 0;is = 0;
        dfs(n[1]-1);
        sum = A[1][n[1]];is = 1;
        dfs(n[1]-2);
        sort(p[0]+1,p[0]+ent[0]+1,bijiao);
        sort(p[1]+1,p[1]+ent[1]+1,bijiao);
        p[0][ent[0]+1].val=m;
        p[1][0].val=0;
        j = ent[1];
        for(i=1;i<=ent[0];i++){
            num0=1;num00=p[0][i].isend;
            while(p[0][i].val==p[0][i+1].val){i++;num0++;num00+=p[0][i].isend;}
            while(p[1][j].val+p[0][i].val>m){j--;}
            num1=0;num11=0;
            while(p[1][j].val+p[0][i].val==m){num1++;num11+=p[1][j].isend;j--;}
            ans += num1*num0-num11*num00;
        }
    }
    printf("%lld",ans);
    return 0;
}