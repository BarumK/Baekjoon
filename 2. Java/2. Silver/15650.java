import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 15650
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read N, M
 * 2. Perform combination calculation
 * 		2.1. Recursively select one elements from given range
 * 		2.2. After select one, recursively call function, giving range start from chosen number + 1
 *		2.3. If reaches M elements, add result to result string
 * 3. Print result string
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 8;
	
	// Class Variables
	private static int N, M;
	private static int[] selected = new int[MAX_N];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Read N, M
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		// Take Combination
		combination(0, 1);
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void combination(int count, int start) {
		// Completed Condition: Print and Return
		if (count == M) {
			for (int i = 0; i < M; i++) sb.append(selected[i] + " ");
			sb.append('\n');
			return;
		}
		
		for (int i = start; i <= N; i++) {
			selected[count] = i;
			combination(count + 1, i + 1);
		}
	}
}
