import java.io.*;
import java.lang.*;
import java.util.*;


class bar_graph {
    public static void barGraph(int[] arr) {
        int mx = Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++) mx = Math.max(mx, arr[i]);
        for(int j=mx;j>0;j--) {
            for(int k=0;k<arr.length;k++) {
                if(arr[k] >= j) System.out.print("* ");
                else System.out.print("  ");
            }
            System.out.println();
        }
        return;
    }

    public static void main(String[] args) throws Exception
    {
        Scanner scn = new Scanner(System.in);
        // Online Judge
        if (System.getProperty("ONLINE_JUDGE") == null) {
            try {
                System.setOut(new PrintStream(
                    new FileOutputStream("output.txt")));
                scn = new Scanner(new File("input.txt"));
            }
            catch (Exception e) {
            }
        }

        int n = scn.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<arr.length;i++) arr[i] = scn.nextInt();
        barGraph(arr);
    }
}