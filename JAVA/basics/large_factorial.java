import java.io.*;
import java.lang.*;
import java.util.*;


class large_factorial {
	public static int multiply(int[] m, int m_size, int n) {
		int c = 0;
		for(int i=0;i<m_size;i++) {
			int d = m[i]*n + c;
			c = d/10;
			m[i] = d%10;
		}
		while(c != 0) {
			m[m_size] = c % 10;
			c /= 10;
			m_size++; 
		}
		return m_size;
	}
	public static int factorial(int n, int[] res) {
		res[0] = 1;
		int res_size = 1;
		for(int i=2;i<=n;i++) {
			res_size = multiply(res, res_size, i);
		}
		return res_size;
	}
    public static void main(String[] args)
    {
        Scanner scn = new Scanner(System.in);
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
        int[] ans = new int[10000];
        int sz = factorial(n, ans);
        for(int d=sz-1;d>=0;d--) System.out.print(ans[d]);
    }
}
