import java.util.*;
import java.io.*;

/**
 * BOJ 1010
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read Number Of Test Cases
 * 2. Precompute Combination Table
 * 		2.1. comb[n][r]: Number Of Ways To Choose r From n
 * 		2.2. Base Cases
 * 			2.2.1. comb[n][0] = 1
 * 			2.2.2. comb[n][n] = 1
 * 		2.3. Pascal Triangle Relation
 * 			2.3.1. comb[n][r] = comb[n-1][r-1] + comb[n-1][r]
 * 		2.4. Precompute Up To MAX_N
 * 3. For Each Test Case
 * 		3.1. Read N And M
 * 		3.2. Calculate Number Of Bridge Construction Cases
 * 			3.2.1. Choose N Sites From M Sites
 * 			3.2.2. Result = comb[M][N]
 * 		3.3. Append Result To Output
 * 4. Print Final Output
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 30;
	
	// Class Variables
	private static int TC, N, M;
	private static long[][] comb = new long[MAX_N + 1][MAX_N + 1];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Read # of Test Cases
		TC = Integer.parseInt(br.readLine().trim());
		
		// Initialization
		init();
		
		// Loop For Each Cases
		for (int tc = 1; tc <= TC; tc++) {
			// Read N, M
			st = new StringTokenizer(br.readLine().trim());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			// Add Result
			sb.append(comb[M][N] + "\n");
		}
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Make Combination Table
		for (int i = 0; i <= MAX_N; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 ||  j == i) comb[i][j] = 1;
				else comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
			}
		}
	}
}
