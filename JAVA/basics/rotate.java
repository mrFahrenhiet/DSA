import java.io.*;
import java.lang.*;
import java.util.*;


class rotate {
	public static void swap(int[] arr, int i, int j) {
		arr[i] = arr[i] ^ arr[j];
		arr[j] = arr[i] ^ arr[j];
		arr[i] = arr[i] ^ arr[j];
		return;
	}
    public static void reverseArrBrute(int[] arr, int x) {
        int pos = arr.length - x + 1;
        for(int i=0;i<pos;i++) {
            int lst = arr.length - 1;
            while(lst > 0) {
                swap(arr, lst, lst - 1);
                lst--;
            }
        }
        return;
    }

    public static void rotateArr(int [] arr, int x) {
        int pos = x - 1, i = 0;
        while(pos < arr.length) {
            swap(arr, pos, i);
            i++;
            pos++;
        }
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
        int arr[] = new int[n];
        for(int i=0;i<arr.length;i++) arr[i] = scn.nextInt();
        int x = scn.nextInt();
        rotateArr(arr, x);
        for(int i=0;i<arr.length;i++) System.out.print(arr[i] + " ");
        System.out.println();    
    }
}
