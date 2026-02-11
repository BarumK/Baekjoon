import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 6987
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. There are 4 independent test cases
 * 2. Each test case provides 18 integers
 *      2.1. For team i (0..5),
 *           - input[3*i + 0]: wins
 *           - input[3*i + 1]: draws
 *           - input[3*i + 2]: losses
 * 3. Precompute all match pairs (6C2 = 15 matches)
 * 4. Try all possible outcomes for each match by DFS
 *      4.1. For match (a, b), select one of 3 outcomes:
 *           - a win,  b loss
 *           - a draw, b draw
 *           - a loss, b win
 *      4.2. Update simulation[] accordingly and recurse to next match
 *      4.3. When depth reaches 15, compare simulation[] with input[]
 * 5. Output 1 if any valid schedule exists, otherwise 0
 */
public class Main {
	// Constant Variables

	
	// Class Variables
	private static int TC, result, combinationCount;
	private static int[] input = new int[18];
	private static int[] simulation = new int[18];
	private static int[][] combinations = new int[15][2];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Read # of Test Cases
		TC = 4;
		
		// Calculate Combination: 6C2
		combinationCount = 0;
		combination(0, 0, new int[2]);
		
		// Loop for Each Test Eases
		for (int tc = 1; tc <= TC; tc++) {
			// Initialization
			init();
			
			// Calculate Result
			calculate(0);
			
			// Add Result
			sb.append(result + " ");
		}
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void combination(int count, int start, int[] selected) {
		// Break Condition
		if (count == 2) {
			combinations[combinationCount][0] = selected[0];
			combinations[combinationCount][1] = selected[1];
			combinationCount++;
			return;
		}
		
		// Select
		for (int idx = start; idx < 6; idx++) {
			selected[count] = idx;
			combination(count + 1, idx + 1, selected);
		}
	}
	
	private static void init() throws Exception {
		// Read Input
		st = new StringTokenizer(br.readLine().trim());
		for (int idx = 0; idx < 18; idx++) {
			input[idx] = Integer.parseInt(st.nextToken());
			simulation[idx] = 0;
		}
		
		// Initialize Variables
		result = 0;
	}
	
	private static void calculate(int depth) {
		// Early Stopping
		if (result == 1) return;
		
		// Break Condition
		if (depth == 15) {
			// Check
			boolean flag = true;
			for (int idx = 0; idx < 18; idx++) {
				if (input[idx] != simulation[idx]) {
					flag = false;
					break;
				}
			}
			
			// If Same, Mark result as 1
			if (flag) result = 1;
			return;
		}
		
		// Select: Left one Wins
		simulation[3 * combinations[depth][0]]++;
		simulation[3 * combinations[depth][1] + 2]++;
		calculate(depth + 1);
		simulation[3 * combinations[depth][0]]--;
		simulation[3 * combinations[depth][1] + 2]--;
		
		// Select: Draw
		simulation[3 * combinations[depth][0] + 1]++;
		simulation[3 * combinations[depth][1] + 1]++;
		calculate(depth + 1);
		simulation[3 * combinations[depth][0] + 1]--;
		simulation[3 * combinations[depth][1] + 1]--;
		
		// Select: Right one Wins
		simulation[3 * combinations[depth][0] + 2]++;
		simulation[3 * combinations[depth][1]]++;
		calculate(depth + 1);
		simulation[3 * combinations[depth][0] + 2]--;
		simulation[3 * combinations[depth][1]]--;
	}
}
