#include<iostream>
#include<algorithm>
int p[25001],a[100],b[100];
int main(){
    using namespace std;
    int n,t,m,i,j;
    cin>>t;
    while(t>0){
        cin>>n;m=0;
        for(i=0;i<n;i++){
            cin>>a[i];
            b[i]=1;
        }
        sort(a,a+n);
        for(i=1;i<=a[n-1];i++){
            p[i]=0;
        }
        p[0]=1;
        for(i=0;i<n;i++){
            if(b[i]){
                for(j=a[i];j<=a[n-1];j++){
                    if(p[j-a[i]]){
                        p[j]=1;
                    }
                }
                for(j=i+1;j<n;j++){
                    if(p[a[j]]==1){
                        b[j]=0;
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            m+=b[i];
        }
        cout<<m<<endl;
        t--;
    }
}