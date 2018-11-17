import java.math.*;
import java.util.*;
import java.io.*;

class NumArray {

    int[] seg;
    int height;
    
    public NumArray(int[] nums) {
        
        int n = nums.length;
        int k = (int)(Math.log(n)/Math.log(2));
        int size = (int)(2*Math.pow(2,k+1));
        
        seg = new int[size];
        height = (int)(Math.log(size)/Math.log(2))-1;
        
        for(int i=size/2;i<=size;i++){
            if(i-size/2 < nums.length){
                seg[i] = num[i-size/2];
            }else break;
        }
        
        for(int i=size/2-1;i>0;i--){
            seg[i] = seg[i*2]+seg[i*2+1];
        }
        
    }
    
    public void update(int i, int val) {
        
        int size = seg.length;
        seg[size/2+i] = val;
        rec((size/2+i)/2);
        
    }
    
    private void rec(int root){
        if(root < 1){
            return;
        }else{
            int left = 2*root;
            int right = 2*root+1;
            seg[root] = seg[left]+seg[right];
            rec(root/2);
        }
    }
    
    public int sumRange(int i, int j) {
        
        return val(1,i,j);
    }
     
    private int val(int root,int left, int right){
        
        if(root >= size/2){
            if(left== root-size/2 || right == root-size/2 ){
            return seg[root];    
            }
            else
                return 0;
            
        }
        
        int level = (int)(Math.log(root)/Math.log(2));
        int nodes = (int)Math.pow(2,level);
        
        int p = root%nodes;
        int range = (int)(Math.pow(2,height-level));
        int start = p*range+1;
        int end = (p+1)*range;
        
        if(start >= left && end <= right){
            return seg[root];
        }else if(end < left || start > right){
            return 0;
        }
        else
        {
            return val(2*root,left,right) + return (2*root+1,left,right);
        }
        
    }
    
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
