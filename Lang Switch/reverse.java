import java.io.*;
import java.lang.*;
import java.util.*;


class reverse {
	public static void reverseArr(int[] arr) {
		int i = 0, j = arr.length - 1;
		while(i<j) {
			arr[i] = arr[i] ^ arr[j];
			arr[j] = arr[i] ^ arr[j];
			arr[i] = arr[i] ^ arr[j];
			i++;
			j--;
		}
		for(int k = 0; k < arr.length; k++) System.out.print(arr[k] + " ");
		return;
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
        for(int i=0;i<arr.length;i++) arr[i] = scn.nextInt();

        reverseArr(arr);
    }
}
