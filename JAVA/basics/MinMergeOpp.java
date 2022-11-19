import java.io.*;
import java.lang.*;
import java.util.*;


class MinMergeOpp {
	public static int minMergeOpperations(int[] arr) {
		int res=  0, i = 0, j = arr.length - 1;
		while(i<=j) {
			if(arr[i]==arr[j]) {
				i++;
				j--;
			}
			else if(arr[i] > arr[j]) {
				arr[j-1] += arr[j];
				j--;
				res++; 
			}
			else {
				arr[i+1] += arr[i];
				i++;
				res++;
			}
		}
		return res;
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
        int[] arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = scn.nextInt();
        int x = minMergeOpperations(arr);
        System.out.println(x); 
    }
}
