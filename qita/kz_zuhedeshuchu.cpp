#include<cstdio>
int jin(int A[],int n,int r){
    int k=r;
    while(k>=1){
        if (A[k]<n-r+k){
            A[k]++;
            break;
        }
        else{
            k--;
        }
    }
    if (k==0){
        return 0;
    }
    else{
        for(int i=k+1;i<=r;i++){
            A[i] = A[i-1]+1;
        }
        return 1;
    }
}
int main(){
    int n,r,p[23],i,c;
    scanf("%d %d",&n,&r);
    for(i=1;i<=r;i++){
        p[i] = i;
    }
    while(1){
        for(i=1;i<=r;i++){
            printf("%3d",p[i]);
        }
        printf("\n");
        c = jin(p,n,r);
        if(c==0){
            break;
        }
    }
    return 0;
}