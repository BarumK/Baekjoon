import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        int result = 0;
        int temp;

        // Get Input
        for (int i = 0; i < 5; i++) {
            temp = sc.nextInt();
            result += temp * temp;
        }
        // Take Modulo Operation
        result %= 10;

        // Print Result
        System.out.println(result);
    }
}