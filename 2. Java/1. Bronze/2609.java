import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        int var[] = new int[2];
        int gcd_val;

        // Take Input
        for (int i = 0; i < 2; i++) var[i] = sc.nextInt();

        // Calculate GCD
        if (var[0] >= var[1]) gcd_val = gcd(var[0], var[1]);
        else gcd_val = gcd(var[1], var[0]);

        // Print Result
        System.out.println(gcd_val);
        System.out.println(var[0] * var[1] / gcd_val);
    }

    public static int gcd(int a, int b) {
        int temp;
        while (true) {
            if (a % b == 0) return b;
            else {
                temp = a;
                a = b;
                b = temp % b;
            }
        }
    }
}