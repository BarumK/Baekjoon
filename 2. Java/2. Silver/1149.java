import java.util.*;
import java.io.*;

/**
 * BOJ 1149
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read Input
 * 		1.1. N: Number Of Houses
 * 		1.2. costs: Painting Cost For Each Color (Red, Green, Blue)
 * 2. Apply Dynamic Programming
 * 		2.1. dpTable[i][j]: Minimum Cost To Paint Up To i-th House With j Color
 * 		2.2. Memory Optimization
 * 			2.2.1. Use Only Two Rows (Rolling Array)
 * 			2.2.2. Current Row: idx % 2
 * 			2.2.3. Previous Row: (idx - 1) % 2
 * 3. For Each House
 * 		3.1. Read Painting Cost
 * 		3.2. For Each Color
 * 			3.2.1. First House
 * 				dpTable[0][color] = costs[color]
 * 			3.2.2. Other Houses
 * 				Choose Minimum Among Previous Different Colors
 * 				dpTable[cur][color] =
 * 					min(dpTable[prev][otherColor] + costs[color])
 * 4. Find Minimum Cost Among Last House Colors
 * 5. Print Result
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 1000;
	
	// Class Variables
	private static int N, result;
	private static int[] costs = new int[3];
	private static int[][] dpTable = new int[2][3];
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
		System.out.println(result);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N
		N = Integer.parseInt(br.readLine().trim());
		
		// Initialize Variables
		result = Integer.MAX_VALUE;
	}
	
	private static void dp() throws Exception {
		for (int idx = 0; idx < N; idx++) {
			// Read Line
			st = new StringTokenizer(br.readLine().trim());
			for (int color = 0; color < 3; color++) costs[color] = Integer.parseInt(st.nextToken());
			
			// Fill DP Table
			for (int curColor = 0; curColor < 3; curColor++) {
				if (idx == 0) dpTable[idx % 2][curColor] = costs[curColor];
				else {
					dpTable[idx % 2][curColor] = Integer.MAX_VALUE;
					for (int prevColor = 0; prevColor < 3; prevColor++) {
						if (curColor == prevColor) continue;
						dpTable[idx % 2][curColor] = Math.min(dpTable[idx % 2][curColor], dpTable[(idx - 1) % 2][prevColor] + costs[curColor]);
					}
				}
				
				// Find Result
				if (idx == N - 1) result = Math.min(result, dpTable[idx % 2][curColor]);
			}
		}
	}
}
