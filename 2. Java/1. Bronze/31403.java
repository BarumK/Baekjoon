import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        int result[] = new int[3];

        // Get Input
        for (int i = 0; i < 3; i++) {
            result[i] += sc.nextInt();
        }

        // Print Result
        System.out.println(result[0] + result[1] - result[2]);
        System.out.println(Integer.parseInt(result[0] + "" + result[1]) - result[2]);
    }
}