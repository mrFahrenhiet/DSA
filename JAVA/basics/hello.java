import java.io.*;
import java.lang.*;
import java.util.*;


class hello {

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
        String inp = scn.nextLine();
        System.out.println(inp + " World!");
    }
}
