import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        long rank = 1;
        long modulo = 1234567891;
        long result = 0;
        long N;
        String arr;

        // Take Input
        N = sc.nextInt();
        arr = sc.next();

        // // Character-Integer Matching + Rank Multiplication
        for (int i = 0; i < N; i++) {
            result += (((long)arr.charAt(i) - 96) * rank) % modulo;
            rank = (rank * 31) % modulo;
        }

        // Print Result
        System.out.println(result % modulo);
    }
}