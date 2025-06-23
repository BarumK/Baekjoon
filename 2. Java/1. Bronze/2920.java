import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

class Main {
    public static void main(String[] args) {
        // Variables
        Scanner sc = new Scanner(System.in);
        Integer var[] = new Integer[8];
        Integer val[] = new Integer[8];

        // Get Input
        for (int i = 0; i < 8; i++) {
            var[i] = sc.nextInt();
            val[i] = var[i];
        }

        // Sort List
        Arrays.sort(val);

        // Print Result
        if (Arrays.equals(var, val)) System.out.println("ascending");
        else {
            Arrays.sort(val, Collections.reverseOrder());
            if (Arrays.equals(var, val)) System.out.println("descending");
            else System.out.println("mixed");
        }
    }
}