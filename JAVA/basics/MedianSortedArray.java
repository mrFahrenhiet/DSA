import java.io.*;
import java.lang.*;
import java.util.*;


class MedianSortedArray {

    public static int median(int[] arr, int st, int en) {
        int len = en - st + 1;
        int mid = len/2;
        if(len%2==0) return (arr[st + mid] + arr[st + mid-1])/2;
        return arr[st + mid];
    }
    public statc int medianArrays(int[] arr1, int[] arr2) {
        int med1 = median(arr1, 0, arr1.length-1);
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
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        for(int i=0;i<n;i++) arr1[i] = scn.nextInt();
        for(int i=0;i<n;i++) arr2[i] = scn.nextInt();
        int x = medianArrays(arr1, arr2);
    }
}
