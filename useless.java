import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private void run(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] d = new int[n];
        for(int i=0;i<n;i++){
            d[i] = sc.nextInt();
        }
        
        int inf = Integer.MAX_VALUE/2;
        int[][] dp = new int[n+1][3];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],inf);
        }
        Arrays.fill(dp[0],0);
        for(int i=1;i<=n;i++){
            
            if(d[i-1] == 0){
                
                dp[i][0] = Math.min(dp[i][0],dp[i-1][0]+1);
                dp[i][0] = Math.min(dp[i][0],dp[i-1][1]+1);
                dp[i][0] = Math.min(dp[i][0],dp[i-1][2]+1);
                
                dp[i][1] = inf;
                dp[i][2] = inf;
                
            }else if(d[i-1] == 1){
                
                dp[i][0] = Math.min(dp[i][0],dp[i-1][0]+1);
                dp[i][0] = Math.min(dp[i][0],dp[i-1][1]+1);
                dp[i][0] = Math.min(dp[i][0],dp[i-1][2]+1);
                
                dp[i][1] = Math.min(dp[i][1],dp[i-1][0]);
                dp[i][1] = Math.min(dp[i][1],dp[i-1][2]);
                
                dp[i][2] = inf;
            }else if(d[i-1] == 2){
                
                dp[i][0] = Math.min(dp[i][0],dp[i-1][0]+1);
                dp[i][0] = Math.min(dp[i][0],dp[i-1][1]+1);
                dp[i][0] = Math.min(dp[i][0],dp[i-1][2]+1);
                
                dp[i][1] = inf;
                
                dp[i][2] = Math.min(dp[i][2],dp[i-1][0]);
                dp[i][2] = Math.min(dp[i][2],dp[i-1][1]);
                
            }else if(d[i-1] == 3){
                
                dp[i][0] = Math.min(dp[i][0],dp[i-1][0]+1);
                dp[i][0] = Math.min(dp[i][0],dp[i-1][1]+1);
                dp[i][0] = Math.min(dp[i][0],dp[i-1][2]+1);
                
                dp[i][1] = Math.min(dp[i][1],dp[i-1][0]);
                dp[i][1] = Math.min(dp[i][1],dp[i-1][2]);
                
                dp[i][2] = Math.min(dp[i][2],dp[i-1][0]);
                dp[i][2] = Math.min(dp[i][2],dp[i-1][1]);
            }
            
        }
        
        int ans = inf;
        ans = Math.min(ans,dp[n][0]);
        ans = Math.min(ans,dp[n][1]);
        ans = Math.min(ans,dp[n][2]);
        
        System.out.println(ans);
    }
    
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        new Solution().run();
    }
}