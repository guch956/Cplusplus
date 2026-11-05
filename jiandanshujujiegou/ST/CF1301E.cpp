#include<iostream>
#include<cstdio>
using namespace std;
const int N=503;
int sum[4][N][N];
int zhi[N][9][N][9];
int log2[N];
int rect(int x1,int y1,int x2,int y2,int k){
    return sum[k][x2][y2]-sum[k][x2][y1]-sum[k][x1][y2]+sum[k][x1][y1];
}
bool check(int x,int y,int r){
    if(rect(x-r,y-r,x,y,0)<r*r){return 0;}
    if(rect(x-r,y,x,y+r,1)<r*r){return 0;}
    if(rect(x,y-r,x+r,y,2)<r*r){return 0;}
    if(rect(x,y,x+r,y+r,3)<r*r){return 0;}
    return 1;
}
inline int query(int x1,int y1,int x2,int y2){
    int a=log2[x2-x1+1],b=log2[y2-y1+1];
    return max(zhi[x1][a][y1][b],max(zhi[x2-(1<<a)+1][a][y2-(1<<b)+1][b],max(zhi[x2-(1<<a)+1][a][y1][b],zhi[x1][a][y2-(1<<b)+1][b])));
}
int main(){
    int n,m,j,i,q,k,l,r,mid,x,y,a,b;
    char c;
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            c = getchar();
            while(c!='G' && c!='Y' && c!='R' && c!='B'){c = getchar();}
            switch (c){
                case 'R':
                    sum[0][i][j]=1;
                    break;
                case 'G':
                    sum[1][i][j]=1;
                    break;
                case 'Y':
                    sum[2][i][j]=1;
                    break;
                case 'B':
                    sum[3][i][j]=1;
                    break;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            for(k=0;k<4;k++){
                sum[k][i][j]=sum[k][i][j]+sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1];
            }
        }
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            l = 0;r = min(i,min(j,min(n-i,m-j)));
            while(l<r){
                mid = (l+r+1)>>1;
                if(check(i,j,mid)){l = mid;}
                else{r = mid-1;}
            }
            zhi[i][0][j][0]=l;
        }
        printf("\n");
    }
    for(k=0;k<=8;k++){
        for(i=1;i<n;i++){
            if(i+(1<<k)>n){break;}
            for(l=0;l<=8;l++){
                for(j=1;j<m;j++){
                    if(k+l==0){break;}
                    if(j+(1<<l)>m){break;}
                    if(k==0){
                        zhi[i][k][j][l]=max(zhi[i][k][j+(1<<(l-1))][l-1],zhi[i][k][j][l-1]);
                        continue;
                    }
                    if(l==0){
                        zhi[i][k][j][l]=max(zhi[i][k-1][j][l],zhi[i+(1<<(k-1))][k-1][j][l]);
                        continue;
                    }
                    zhi[i][k][j][l]=max(zhi[i][k-1][j][l-1],max(zhi[i][k-1][j+(1<<(l-1))][l-1],max(zhi[i+(1<<(k-1))][k-1][j][l-1],zhi[i+(1<<(k-1))][k-1][j+(1<<(l-1))][l-1])));
                }
            }
        }
    }
    for(i=2;i<=500;i++){log2[i]=log2[i>>1]+1;}
    while(q--){
        scanf("%d %d %d %d",&a,&b,&x,&y);
        x--;y--;
        if(x<a || y<b){printf("0\n");}
        else{
            l = 0;r = min(x-a,y-b)/2+1;
            while(l<r){
                mid=(l+r+1)>>1;
                i = query(a+mid-1,b+mid-1,x-mid+1,y-mid+1);
                if(query(a+mid-1,b+mid-1,x-mid+1,y-mid+1)>=mid){l = mid;}
                else{r = mid-1;}
            }
            printf("%d\n",4*l*l);
        }
    }
    return 0;
}