import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        int N, K, max, min;
        int result = 1;

        // Take Input
        N = sc.nextInt();
        K = sc.nextInt();

        if (N - K > K) {
            max = N - K;
            min = K;
        }
        else {
            max = K;
            min = N - K;
        }

        // Calculate Factorial
        for (int i = N; i > max; i--) result *= i;
        for (int i = min; i > 1; i--) result /= i;
        
        // Print Result
        System.out.println(result);
    }
}