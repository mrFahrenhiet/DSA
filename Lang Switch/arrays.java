import java.util.*;
import java.io.*;

class Array {

    static class FastReader  {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
            try {
                br = new BufferedReader(
                new FileReader("input.txt"));
                PrintStream out = new PrintStream(new FileOutputStream("output.txt"));
                System.setOut(out);
            }
            catch(Exception e) {
                br = new BufferedReader(new InputStreamReader(System.in));
            }
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void fun(int[] arr) {
        System.out.print("Arr: ");
        for(int i=0;i<arr.length;i++) System.out.print(arr[i] + " ");
        System.out.println();
    }
    public static void printMat(int[][] mat) {
        mat[0][0] = -mat[0][0];
        System.out.print("Matrix: ");
        for(int i=0;i<mat.length;i++) {
            for(int j=0;j<mat[i].length;j++) System.out.print(mat[i][j] + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        FastReader scn = new FastReader();
        int[] arr = new int[5];
        for(int i=0;i<5;i++) arr[i] = scn.nextInt();
        fun(arr);
        for(int v: arr) System.out.print(v + " ");
        System.out.println();
        int[][] mat = new int[3][3];
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) mat[i][j] = scn.nextInt();
        }
        printMat(mat);
        int [][] jag = new int[2][];
        jag[0] = new int[3];
        jag[1] = new int[4];
        for(int i=0;i<jag.length;i++) {
            for(int j=0;j<jag[i].length;j++) jag[i][j] = scn.nextInt();
        }
        printMat(jag);
    }
}
