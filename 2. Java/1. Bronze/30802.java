import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        int num, T, P;
        int var[] = new int[6];
        int result = 0;

        // Take Input
        num = sc.nextInt();
        for (int i = 0; i < 6; i++) var[i] = sc.nextInt();
        T = sc.nextInt();
        P = sc.nextInt();

        // Calculate T-Shirt
        for (int i = 0; i < 6; i++) {
            if (var[i] % T == 0) result += (var[i] / T);
            else result += (var[i] / T) + 1;
        }

        // Print Result
        System.out.println(result);
        System.out.printf("%d %d\n", num / P, num % P);
    }
}