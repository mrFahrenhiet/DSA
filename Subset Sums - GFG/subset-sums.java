//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            int N=sc.nextInt();
			ArrayList<Integer> arr = new ArrayList<>();
			for(int i = 0; i < N ; i++){
			    arr.add(sc.nextInt());
			}
            Solution ob = new Solution();
         
            ArrayList<Integer> ans = ob.subsetSums(arr,N);
            Collections.sort(ans);
            for(int sum : ans){
                System.out.print(sum+" ");
            }
            System.out.println();
        }  
    }
}

// } Driver Code Ends


//User function Template for Java//User function Template for Java
class Solution{
    private ArrayList<Integer> res;
    private int subsetS = 0;
    
    public int helper(ArrayList<Integer> arr, int n, int i) {
        if(i >= n) {
            res.add(subsetS);
            
            // subsetS = 0;
            
            return 0;
        }
        
        subsetS += (helper(arr, n, i+1) + arr.get(i));
        subsetS = helper(arr, n, i+1);
        
        return subsetS;
    }
    
    ArrayList<Integer> subsetSums(ArrayList<Integer> arr, int N){
        res = new ArrayList<Integer>();
        
        //ArrayList<Integer> temp = 
        
        helper(arr, N, 0);
        return res;
    }
}