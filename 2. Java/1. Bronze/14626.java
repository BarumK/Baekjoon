import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        // Variables
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] ISBN;
        int res = 0;
        int mul;
        int saved_mul = -1;

        // Take Input
        ISBN = br.readLine().toCharArray();

        // Calculate
        for(int i = 0; i < 13; i++) {
            if (i % 2 == 0) mul = 1;
            else mul = 3;
            
            if (ISBN[i] == '*') saved_mul = mul;
            else res += mul * (int)(ISBN[i] - 48);
        }

        // Print Result
        for (int x = 0; x < 10; x++) {
            if ((res + saved_mul * x) % 10 == 0) {
                System.out.println(x);
                break;
            }
        }
    }
}