
import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
    public static boolean allocateStalls(int[] stalls, int c, int dist) {
        int cowsAllocated = 1, lastAllocated = stalls[0];
        for(int i=1;i<stalls.length;i++) {
            if(Math.abs(stalls[i] - lastAllocated) >= dist) {
                cowsAllocated++;
                lastAllocated = stalls[i];
            }
        }
        return cowsAllocated >= c;
    }

    public static int getLargestMinDist(int[] stalls, int c) {
        int minDist = 0, maxDist = stalls[stalls.length - 1], res = 0;
        while(minDist <= maxDist) {
            int midDist = ((maxDist - minDist) / 2) + minDist;
            if(allocateStalls(stalls, c, midDist)) {
                res = midDist;
                minDist = midDist + 1;
            }
            else maxDist = midDist - 1;
        }
        return res;
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scn = new Scanner(System.in);
        int nosTestCases = scn.nextInt();
        while(nosTestCases > 0) {
            int nosStalls = scn.nextInt(), cows = scn.nextInt();
            int[] stalls = new int[nosStalls];
            for(int i=0;i<nosStalls;i++) stalls[i] = scn.nextInt();
            Arrays.sort(stalls);
            int largestMinDist = getLargestMinDist(stalls, cows);
            System.out.println(largestMinDist);
            nosTestCases--;
        }
	}
}

