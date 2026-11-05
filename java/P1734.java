import java.util.*;
public class P1734{
    static int[] dp;
    static int[] s;
    public static void main(String[] args){
        dp = new int[1003];
        s = new int[1003];
        int n,i,j;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(i=1;i<=n;i++){
            s[i] = sum(i);
        }
        for(i=1;i<=n;i++){
            for(j=n;j>=i;j--){
                dp[j] = Math.max(dp[j],dp[j-i]+s[i]);
            }
        }
        System.out.println(dp[n]);
    }
    static int sum(int x){
        int a = 0,i;
        for(i=1;i*i<x;i++){
            if (x%i ==0 ){
                a = a+i;
                a = a+x/i;
            }
        }
        if(x == i*i){a+=i;}
        a = a-x;
        return a;
    }
    
}