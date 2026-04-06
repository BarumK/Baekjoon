import java.util.*;
import java.io.*;

/**
 * BOJ 1463
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read Input
 * 		1.1. N: Target Number
 * 2. Apply Dynamic Programming
 * 		2.1. dpTable[i]: Minimum Number Of Operations To Make i To 1
 * 		2.2. Base Case
 * 			2.2.1. dpTable[1] = 0
 * 		2.3. For Each Number From 2 To N,
 * 			2.3.1. Subtract 1 Operation
 * 				dpTable[i] = dpTable[i - 1] + 1
 * 			2.3.2. Divide By 2 If Possible
 * 				dpTable[i] = min(dpTable[i], dpTable[i / 2] + 1)
 * 			2.3.3. Divide By 3 If Possible
 * 				dpTable[i] = min(dpTable[i], dpTable[i / 3] + 1)
 * 3. Print Minimum Operations For N
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 1000000;
	
	// Class Variables
	private static int N;
	private static int[] dpTable = new int[MAX_N + 1];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Perform DP
		dp();
		
		// Print Result
		System.out.println(dpTable[N]);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N
		N = Integer.parseInt(br.readLine().trim());
	}
	
	private static void dp() {
		// Base Condition
		dpTable[1] = 0;
		
		// Calculate
		for (int idx = 2; idx <= N; idx++) {
			dpTable[idx] = dpTable[idx - 1] + 1;
			if (idx % 2 == 0) dpTable[idx] = Math.min(dpTable[idx], dpTable[idx / 2] + 1);
			if (idx % 3 == 0) dpTable[idx] = Math.min(dpTable[idx], dpTable[idx / 3] + 1);
		}
	}
}
