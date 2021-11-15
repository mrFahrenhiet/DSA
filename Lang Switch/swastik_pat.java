import java.util.*;
import java.io.*;

class Pattern {
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
    
    public static void pattern(int n) {
        // upper
        int rws = (n / 2) + 1;
        for (int i = 0; i < rws; i++) {
          for (int j = 0; j < n; j++) {
            if (i == 0) {
              if (j < rws || j == n - 1) System.out.print("*\t");
              else System.out.print("\t");
            }
            else if (i == rws - 1) System.out.print("*\t");
            else {
              if (j == rws - 1 || j == n - 1) System.out.print("*\t");
              else System.out.print("\t");
            }
          }
          System.out.println();
        }
    
        // lower
        for (int i = 1; i < rws; i++) {
          for (int j = 0; j < n; j++) {
            if (i == rws - 1) {
              if (j == 0 || j >= rws - 1) System.out.print("*\t");
              else System.out.print("\t");
            }
            else {
              if (j == rws - 1 || j == 0) System.out.print("*\t");
              else System.out.print("\t");
            }
          }
          System.out.println();
        }
    }
    public static void main(String[] args) {
        FastReader scn = new FastReader();
        int x = scn.nextInt();
        pattern(x);   
    }
}
