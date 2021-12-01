import java.io.*;
import java.lang.*;
import java.util.*;


class sum_arr {

	public static int[] sumArr(int[] arr1, int[] arr2) {
		int n = Math.max(arr1.length, arr2.length) + 1;
		int[] res = new int[n];
		int c = 0;
		int i1 = arr1.length-1, i2 = arr2.length-1, i = n-1;
		while(i1>=0 || i2>=0 || i >= 0) {
			int digi = 0;
			if(i1 < 0 && i2 < 0) digi = c;
			else if(i1 < 0) digi = (arr2[i2] + c);
			else if(i2 < 0) digi = (arr1[i1] + c);
			else digi = (arr1[i1] + arr2[i2] + c);
			res[i] = digi % 10;
			c = digi / 10;
			i1--;
			i2--;
			i--;
		}
		return res;
	}

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        if (System.getProperty("ONLINE_JUDGE") == null) {
            try {
                System.setOut(new PrintStream(new FileOutputStream("output.txt")));
                scn = new Scanner(new File("input.txt"));
            }
            catch (Exception e) {
            }
        }

        int n = scn.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<arr.length;i++) arr[i] = scn.nextInt();

        int n2 = scn.nextInt();
    	int[] arr2 = new int[n2];
    	for(int i=0;i<arr2.length;i++) arr2[i] = scn.nextInt();

    	int[] ans = sumArr(arr, arr2); 
    	for(int i=0;i<ans.length;i++) {
    		if(ans[i]==0 && i==0) continue;
    		System.out.print(ans[i]);
    	}
    	System.out.println();
    }
}