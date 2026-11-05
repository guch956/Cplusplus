#include<iostream>
int main(){
    using namespace std;
    int n,m,i,j,k,c,s,a,max_min,*p,**q;
    cin>>n>>m;
    p = new int[2*n];
    for(i=0;i<n;i++){
        cin>>p[i];
        p[i] = p[i]%10;
        if(p[i]<0){
            p[i]+=10;
        }
        p[i+n] = p[i];
    }
    q = new int*[n];
    for(i=0;i<n;i++){
        q[i] = new int[n];
        s = 0;
        for(j=0;j<n;j++){
            s += p[i+j];
			s = s%10;
            q[i][j] = s;
        }
    }
    for(k=2;k<=m;k++){
        for(i=0;i<n;i++){
            for(j=n-1;j>=k-1;j--){
                s = 0;
                max_min = 2000000000;
                for(c=i+j;c>=i+k-1;c--){
                    s+=p[c];
                    s = s%10;
                    a = s*q[i][c-1-i];
                    max_min = a<max_min?a:max_min;
                }
                q[i][j] = max_min;
            }
        }
    }
    s = 2000000000;
    for(i=0;i<n;i++){
        s = s<q[i][n-1]?s:q[i][n-1];
    }
    cout<<s<<endl;
	for(i=0;i<n;i++){
        s = 0;
        for(j=0;j<n;j++){
            s += p[i+j];
			s = s%10;
            q[i][j] = s;
        }
    }
    for(k=2;k<=m;k++){
        for(i=0;i<n;i++){
            for(j=n-1;j>=k-1;j--){
                s = 0;
                max_min = 0;
                for(c=i+j;c>=i+k-1;c--){
                    s+=p[c];
                    s = s%10;
                    a = s*q[i][c-1-i];
                    max_min = a>max_min?a:max_min;
                }
                q[i][j] = max_min;
            }
        }
    }
    s = 0;
    for(i=0;i<n;i++){
        s = s>q[i][n-1]?s:q[i][n-1];
    }
    cout<<s;
    return 0;
}