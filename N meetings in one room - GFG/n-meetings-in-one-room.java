//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.lang.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            String inputLine[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);

            int start[] = new int[n];
            int end[] = new int[n];

            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++)
                start[i] = Integer.parseInt(inputLine[i]);

            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) 
                end[i] = Integer.parseInt(inputLine[i]);
                
            int ans = new Solution().maxMeetings(start, end, n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends

class MeetingTimmings {
    private int start;
    private int end;
    
    public MeetingTimmings(int st, int en) {
        this.start = st;
        this.end = en;
    }
    
    public int getStartTime() {
        return this.start;
    }
    
    public int getEndTime() {
        return this.end;
    }
}

class Solution 
{
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    public static int maxMeetings(int start[], int end[], int n)
    {
        MeetingTimmings[] timmings = new MeetingTimmings[n];
        
        for(int i=0;i<n;i++) {
            timmings[i] = new MeetingTimmings(start[i], end[i]);
        }
        
        Arrays.sort(timmings, (a, b) -> a.getEndTime() - b.getEndTime());
        
        int res = 1;
        MeetingTimmings lastMeeting = timmings[0];
        
        for(int i=1;i<n;i++) {
            if(timmings[i].getStartTime() > lastMeeting.getEndTime()) {
                lastMeeting = timmings[i];
                res++;
            }
        }
        
        return res;
    }
}
