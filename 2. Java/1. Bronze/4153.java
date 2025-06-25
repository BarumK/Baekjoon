import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        int value[] = new int[3];

        while (true) {
            // Take Input & Square Values
            for (int i = 0; i < 3; i++) {
                value[i] = sc.nextInt();
                value[i] *= value[i];
            }
            
            // Loop Break Condition
            if ((value[0] == 0) && (value[1] == 0) && (value[2] == 0)) break;

            // Judgement
            if (value[0] == value[1] + value[2]) System.out.println("right");
            else if (value[1] == value[0] + value[2]) System.out.println("right");
            else if (value[2] == value[0] + value[1]) System.out.println("right");
            else System.out.println("wrong");
        }
    }
}