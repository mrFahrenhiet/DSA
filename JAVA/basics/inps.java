import java.util.*;
import java.io.*;

class Inps {
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
	public static void main (String[] args) throws java.lang.Exception {
        FastReader scn = new FastReader();
		System.out.println("Hello World!");
        int x = scn.nextInt();
        System.out.println("Number: " + x);
        String s = scn.nextLine();
        System.out.println("String: " + s);
        String s2 = scn.next();
        System.out.println("String 2: " + s2);
        String s3 = scn.next();
        System.out.println("String 3: " + s3);
	}
}

