#include<iostream>
int A[8][8];int n;/*0表空,-1表不能放，1表已放*/
int dfs(int k,int x,int y){
    int i,j,s=0;
    if(k==1){
        for(j=y;j<n;j++){
            if(A[x][j]==0){
                s++;
            }
        }
        for(i=x+1;i<n;i++){
            for(j=0;j<n;j++){
                if(A[i][j]==0){
                    s++;
                }
            }
        }
    	return s;
    }
    else{
        int c;
        for(j=y;j<n;j++){
            if(A[x][j]==0){
                    for(c=0;c<n;c++){
                        A[x][c]--;
                        A[c][j]--;
                    }
                    s+=dfs(k-1,x,j);
                    for(c=0;c<n;c++){
                        A[x][c]++;
                        A[c][j]++;
                    }
                }
        }
        for(i=x+1;i<n;i++){
            for(j=0;j<n;j++){
                if(A[i][j]==0){
                    for(c=0;c<n;c++){
                        A[i][c]--;
                        A[c][j]--;
                    }
                    s+=dfs(k-1,i,j);
                    for(c=0;c<n;c++){
                        A[i][c]++;
                        A[c][j]++;
                    }
                }
            }
        }
        return s;
    }
}
int main(){
    using namespace std;
    int x,y,k;
    char a;
    while(1){
    cin>>n>>k;
        if(n==-1){
            break;
        }
    for(x=0;x<n;x++){
        for(y=0;y<n;y++){
            cin>>a;
            if(a=='#'){
                A[x][y]=0;
            }
            else{
                A[x][y]=-1;
            }
        }
    }
    cout<<dfs(k,0,0)<<endl;}
    return 0;
}