//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a, n);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++)
                    System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}

// } Driver Code Ends


// User function Template for Java

// m is the given matrix and n is the order of matrix
class Solution {
    private static ArrayList<String> res;
    private static int[] dx = {1, 0, -1, 0};
    private static int[] dy = {0, 1, 0, -1};
    private static char[] mp = {'R', 'D', 'L', 'U'}; 
    private static boolean isSafe(int n, int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
    private static void helper(int[][] m, boolean[][] visited, StringBuilder temp, int r, int c) {
        if(r >= m.length - 1 && c >= m[0].length - 1) {
            
            res.add(new String(temp.toString()));
            return;
        }
        for(int i=0;i<4;i++) {
            if(isSafe(m.length, r + dy[i], c + dx[i]) && !visited[r + dy[i]][c + dx[i]] && m[r + dy[i]][c + dx[i]] == 1) {
                temp.append(mp[i]);
                visited[r + dy[i]][c + dx[i]] = true;
                
                helper(m, visited, temp, r + dy[i], c + dx[i]);
                
                visited[r + dy[i]][c + dx[i]] = false;
                temp.deleteCharAt(temp.length() - 1);
            }
        }
        
        return;
    }
    public static ArrayList<String> findPath(int[][] m, int n) {
        res = new ArrayList<String>();
        boolean[][] visited = new boolean[n][n];
        
        StringBuilder temp = new StringBuilder();
        
        if(m[0][0] == 1) {
            visited[0][0] = true;
            helper(m, visited, temp, 0, 0);
        }
        
        return res;
    }
}