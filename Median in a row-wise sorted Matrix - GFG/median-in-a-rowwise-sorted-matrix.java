//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;


class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String S[] = read.readLine().split(" ");
            int R = Integer.parseInt(S[0]);
            int C = Integer.parseInt(S[1]);
            int matrix[][] = new int[R][C];
            int c = 0;
            for(int i = 0; i < R; i++){
                String line[]=read.readLine().trim().split(" ");
                for(int j = 0; j < C; j++){
                    matrix[i][j] = Integer.parseInt(line[j]);
                }
            }
            Solution ob = new Solution();
            int ans = ob.median(matrix, R, C);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution {
    boolean isInvalid(int[][] matrix, int potentialMed) {
        int pos = 0;
        for(int[] row: matrix) {
            int l = 0, h = row.length;
            while(l < h) {
                int mid = (l + (h - l) / 2);
                if(row[mid] > potentialMed) h = mid;
                else l = mid + 1;
            }
            
            pos += l;
        }
        
        // System.out.println(pos);
        
        return pos > (matrix.length * matrix[0].length) / 2;
    }
    int median(int matrix[][], int R, int C) {
        int l = 0, h = Integer.MAX_VALUE;
        
        while(l < h) {
            int mid = (l + (h - l) / 2);
            if(isInvalid(matrix, mid)) h = mid;
            else l = mid + 1;
        }
        
        // System.out.println(isValid(matrix, 5));
        
        return l;
    }
}