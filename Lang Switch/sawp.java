import java.util.*;
import java.io.*;

class Swap {
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
    
    public static void fun() {
        int temp = a;
        a = b;
        b = temp;
    }
    static int a = 20;
    static int b = 30;

    public static void main(String[] args) {
        System.out.println("A: " + a + " " + "B: " + b);
        fun();
        System.out.println("A: " + a + " " + "B: " + b);
    }
}