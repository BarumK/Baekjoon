import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        // Variables
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int number = 0;

        // Take Input
        for (int i = 0; i < 3; i++) {
            line = br.readLine();
            
            if ((line.charAt(0) == 'B') || (line.charAt(0) == 'F')) continue;
            else {
                number = Integer.parseInt(line) + (3 - i);
                break;
            }
        }

        // Print Result
        if (number % 3 == 0) {
            if (number % 5 == 0) System.out.println("FizzBuzz");
            else System.out.println("Fizz");
        }
        else {
            if (number % 5 == 0) System.out.println("Buzz");
            else System.out.println(number);
        }
    }
}