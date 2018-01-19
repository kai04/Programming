import java.util.*;
import java.math.*;

class Solution {
    
    int size;
    int height;
    int[] seg;
    int nS;
    
    private int[] range(int root){
        
        int level = (int)(Math.log(root)/Math.log(2))+1;
        int range = (int)(Math.pow(2,height-level));
        int nodes = (int)(Math.pow(2,level-1));
        int p = root%nodes;
        int left = Math.min(p*range+1,nS);
        //System.out.println("p*(range+1) = "+(p+1)*range+" ns = "+nS);
        int right = Math.min((p+1)*range,nS);
        
        //System.out.println("@@ root "+root+" level = "+level+" range = "+range+" nodes = "+nodes+" p = "+p);
        
        //System.out.println("@@Range for "+root+" "+left+" "+right);
        
        return new int[]{left,right};
    }
    
    private void print(String s){
        System.out.println(s);
    }
    
    private int search(int root, int index){
        
        print("@@@@ root"+root+" index = "+index);
        
        if(root >= size){
            print("@@@@@4");
            return 0;
        } 
        
        int[] r = range(root);
        int left = r[0];
        int right = r[1];
        
        print("right = "+right);
        print("left = "+left);
        if(right <= index){
            print ("@@@@@@3 right = "+right+" index = "+(index));
            return 0;
        } 
        
        if(2*seg[root] < seg[size/2+index]){
            
            print("@@@@@1 right - Math.max(index+1,left)+1 = "+(right - Math.max(index+1,left)+1));
            return right - Math.max(index+1,left)+1;
            
        }else{
            
            print("@@@@2");
            return search(2*root,index)+search(2*root+1,index);
        }
        
    }
    
    public int reversePairs(int[] nums) {
        
        int n = nums.length;
        nS = n;
        int k = (int)(Math.log(n)/Math.log(2));
        size = 2*((int)(Math.pow(2,k+1)));
        height = (int)(Math.log(size/2)/Math.log(2))+1;
        seg = new int[size];
        int i=size/2;
        int j=0;
        
        //System.out.println("n = "+n+ " k = "+k+" size="+size+" height = "+height);
        
        while(i < size){
            
            if(j < n){
                seg[i] = nums[j];
                i++;
                j++;
            }else{
                seg[i] = Integer.MIN_VALUE;
                i++;
            }
            
        }
        
        for(i=size/2-1;i>0;i--){
            
            int left = i*2;
            int right = i*2+1;
            seg[i] = Math.max(seg[left],seg[right]);
            
        }
        
        //for(i=1;i<size;i++){
          //  System.out.print(seg[i]+" ");
        //}
        //System.out.println();
        
        int sum = 0;
        
        for(i=0;i<n;i++){
            
            
            
            sum+=search(1,i);
            print("sum= "+sum);
            
        }
        
        return sum;
        
    }
}