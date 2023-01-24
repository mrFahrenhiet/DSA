import java.io.*;
import java.lang.*;
import java.util.*;


class diff_arr {

    public static int[] diff(int[] arr1, int[] arr2) {
        int n = arr2.length;
        int[] res = new int[n];
        int c = 0;
        int i1 = arr1.length-1, i2 = arr2.length-1, i = res.length-1;
        while(i2 >= 0) {
            int digi = 0;
            if(i1 > 0 && i2 > 0) digi = arr1[i1] - arr2[i] + c;
        }
        return arr1;
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
        int n1 = scn.nextInt();
        int[] arr1 = new int[n1];
        for(int i=0;i<arr1.length;i++) arr1[i] = scn.nextInt();

        int n2 = scn.nextInt();
        int[] arr2 = new int[n2];
        for(int i=0;i<arr2.length;i++) arr2[i] = scn.nextInt();

        int[] ans = diff(arr1, arr2);
    }
}