#include<iostream>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1003;
int A[N][N];
int ma[N][N],mi[N][N];
int q1[N],head1,tail1;
int q2[N],head2,tail2;
int main(){
    int a,b,n,i,j,ans=INF;
    scanf("%d %d %d",&a,&b,&n);
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(i=1;i<=a;i++){
        head1=head2=1;
        tail1=tail2=0;
        for(j=1;j<n;j++){
            while(head1<=tail1 && A[i][q1[tail1]]<=A[i][j]){tail1--;}
            while(head2<=tail2 && A[i][q2[tail2]]>=A[i][j]){tail2--;}
            tail1++;tail2++;
            q1[tail1]=q2[tail2]=j;
        }
        for(j=n;j<=b;j++){
            while(head1<=tail1 && A[i][q1[tail1]]<=A[i][j]){tail1--;}
            while(head2<=tail2 && A[i][q2[tail2]]>=A[i][j]){tail2--;}
            tail1++;tail2++;
            q1[tail1]=q2[tail2]=j;
            while(q1[head1]<=j-n){head1++;}
            while(q2[head2]<=j-n){head2++;}
            ma[i][j]=A[i][q1[head1]];
            mi[i][j]=A[i][q2[head2]];
        }
    }
    for(j=n;j<=b;j++){
        head1=head2=1;
        tail1=tail2=0;
        for(i=1;i<n;i++){
            while(head1<=tail1 && ma[q1[tail1]][j]<=ma[i][j]){tail1--;}
            while(head2<=tail2 && mi[q2[tail2]][j]>=mi[i][j]){tail2--;}
            tail1++;tail2++;
            q1[tail1]=q2[tail2]=i;
        }
        for(i=n;i<=a;i++){
            while(head1<=tail1 && ma[q1[tail1]][j]<=ma[i][j]){tail1--;}
            while(head2<=tail2 && mi[q2[tail2]][j]>=mi[i][j]){tail2--;}
            tail1++;tail2++;
            q1[tail1]=q2[tail2]=i;
            while(q1[head1]<=i-n){head1++;}
            while(q2[head2]<=i-n){head2++;}
            ans = min(ans,ma[q1[head1]][j]-mi[q2[head2]][j]);
            
        }
    }
    printf("%d",ans);
    return 0;
}