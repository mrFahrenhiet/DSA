import java.util.*;
import java.io.*;

class Point {
    public int x;
    public int y;

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point(int xx, int yy) {
        this.x = xx;
        this.y = yy;
    }
}

class Rectange {
    public Point tl;
    public Point br;
    
    public Rectange(Point t, Point b) {
        this.tl = t;
        this.br = b;
    }

    public Rectange() {
        this.tl = new Point();
        this.br = new Point();
    }
}

class CObjs {
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
    public static void main(String[] args) {
        FastReader scn = new FastReader();
        Point origin = new Point();
        int x = scn.nextInt();
        int y = scn.nextInt();
        Point d1 = new Point(x, y);
        System.out.println(d1.x + " " + d1.y);
        System.out.println(origin.x + " " + origin.y);

        
    }
}
