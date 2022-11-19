import java.io.*;
import java.lang.*;
import java.util.*;


class move_all_negs {
	public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
		return;
	}
	public static void mov_negs(int[] arr) {
		int maxNeg = 0;
		for(int i=0;i<arr.length;i++) {
			if(arr[i] < 0 && arr[maxNeg] < arr[i]) maxNeg = i;
		}
		swap(arr, maxNeg, arr.length - 1);
		int s = -1;
		for(int i=0;i<arr.length-1;i++) {
			if(arr[i] < arr[arr.length-1]) {
				s++;
				swap(arr, s, i);
			}
		}
		swap(arr, arr.length - 1, s+1);
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
        for(int i=0;i<n;i++) arr[i] = scn.nextInt();
        mov_negs(arr);
    	for(int el: arr) System.out.print(el + " ");
    }
}
