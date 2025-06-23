import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        String a, b;

        while(true) {
            // Take Input
            a = sc.next();
            b = a;

            // Loop Break Condition
            if ((a.length() == 1) && (a.charAt(0) == '0')) break;

            // Reverse
            StringBuffer str = new StringBuffer(a);
            b = str.reverse().toString();

            // Print Result
            if (a.equals(b)) System.out.println("yes");
            else System.out.println("no");
        }
    }
}