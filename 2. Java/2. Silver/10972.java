import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 10972
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Initialize
 *    1.1. Read N
 *    1.2. Read permutation array (size N)
 * 2. Compute next permutation
 *    2.1. Find pivot index from right
 *         2.1.1. Find the largest index pivot such that input[pivot] < input[pivot + 1]
 *    2.2. If pivot does not exist, no next permutation
 *         2.2.1. Print -1 and terminate
 *    2.3. Find swap index from right
 *         2.3.1. Find the largest index i such that input[pivot] < input[i]
 *    2.4. Swap input[pivot] and input[i]
 *    2.5. Reorder suffix to the smallest arrangement
 *         2.5.1. Sort input[pivot + 1 .. N - 1] in ascending order
 * 3. Print result
 *    3.1. If next permutation exists, print the updated array
 *    3.2. Otherwise, print -1
 */
public class Main {
	// Constant Variables
	public static final int MAX_N = 10000;
	
	// Class Variables
	private static int TC, N;
	private static int[] input = new int[MAX_N];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Calculate Next Permutation & Add Result
		if (nextPermutation()) {
			for (int i = 0; i < N; i++) sb.append(input[i] + " ");
		}
		else sb.append(-1);
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N;
		N = Integer.parseInt(br.readLine().trim());
		
		// Read Points & Calories
		st = new StringTokenizer(br.readLine().trim());
		for (int idx = 0; idx < N; idx++) input[idx] = Integer.parseInt(st.nextToken());
	}
	
	private static boolean nextPermutation() {
		// Variables
		int pivot = -1;
		
		// Find Pivot
		for (int i = N - 2; i >= 0; i--) {
			if (input[i] < input[i + 1]) {
				pivot = i;
				break;
			}
		}
		
		// Early Stop
		if (pivot == -1) return false;
		
		// Find Index to Swap & Do Swap
		for (int i = N - 1; i > pivot; i--) {
			if (input[pivot] < input[i]) {
				int temp = input[pivot];
				input[pivot] = input[i];
				input[i] = temp;
				Arrays.sort(input, pivot + 1, N);
				break;
			}
		}
		return true;
	}
}
