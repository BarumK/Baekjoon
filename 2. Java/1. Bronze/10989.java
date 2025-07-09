import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main {
    public static void main(String[] args) throws IOException {
        // Variables
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N, temp;
        int res[] = new int[10001];

        // Take Inputs
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            temp = Integer.parseInt(br.readLine());
            res[temp] += 1;
        }
        br.close();

        // Print Result
        for (int i = 0; i < 10001; i++) {
            for (int j = 0; j < res[i]; j++) sb.append(i).append('\n');
        }
        System.out.println(sb);
    }
}