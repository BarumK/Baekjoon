import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 2961
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Initialize
 *    1.1. Read N
 *    1.2. Read taste information for each ingredient
 *         1.2.1. Each ingredient has (sour, bitter)
 * 2. Enumerate all non-empty subsets using recursion
 *    2.1. For each ingredient index cnt,
 *         2.1.1. Select the ingredient and recurse
 *         2.1.2. Do not select the ingredient and recurse
 *    2.2. When all decisions are made (cnt == N),
 *         2.2.1. If at least one ingredient is selected,
 *                - Multiply sour values
 *                - Sum bitter values
 *         2.2.2. Compute absolute difference between sour product and bitter sum
 *         2.2.3. Update minimum difference
 * 3. Print the minimum difference
 */
public class Main {
	// Constant Variables
	public static final int MAX_N = 10;
	
	// Class Variables
	private static int N;
	private static int resultMin = 1000000000;
	private static int[][] componentInfo = new int[MAX_N][2];
	private static boolean[] selected = new boolean[MAX_N];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Calculate Minimum Value Using Combination
		combination(0, 0);
		
		// Add Result
		sb.append(resultMin);
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N
		N = Integer.parseInt(br.readLine().trim());
		
		// Read Taste Information
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine().trim());
			componentInfo[i][0] = Integer.parseInt(st.nextToken());
			componentInfo[i][1] = Integer.parseInt(st.nextToken());
		}
	}

	
	private static void combination(int cnt, int selectedNum) {
		// Break Condition
		if (cnt == N) {
			if (selectedNum > 0) {
				// Temporal Variables
				int sourMultiplication = 1;
				int bitterSum = 0;
				int difference;
				
				// Calculate Sum & Multiplication
				for (int i = 0; i < N; i++) {
					if (selected[i]) {
						sourMultiplication *= componentInfo[i][0];
						bitterSum += componentInfo[i][1];
					}
				}
				
				// Calculate Difference
				difference = (sourMultiplication > bitterSum) ? (sourMultiplication - bitterSum) : (bitterSum - sourMultiplication);
				
				// If Bigger Than Current Minimum Sum, Update
				if (difference < resultMin) resultMin = difference;	
			}
			return;
		}
		
		
		// Select
		selected[cnt] = true;
		combination(cnt + 1, selectedNum + 1);
		
		// Not Select
		selected[cnt] = false;
		combination(cnt + 1, selectedNum);
	}
}
