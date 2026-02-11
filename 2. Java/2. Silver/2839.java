import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 2839
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read N (total sugar weight)
 * 2. Greedy search for the minimum number of bags
 *    	2.1. While N is positive:
 *         2.1.1. If N is divisible by 5:
 *         		2.1.1.1. Use (N / 5) five-kilogram bags
 *              2.1.1.2. Add to result and stop
 *         2.1.2. Otherwise:
 *              2.1.2.1. Take one 3kg bag (N -= 3)
 *              2.1.2.2. Increase result count
 * 3. If a valid combination is found, print result
 * 4. Otherwise, print -1
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 5000;
	
	// Class Variables
	private static int TC, N, flag, result;
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Read N
		N = Integer.parseInt(br.readLine().trim());
		
		// Initialize Variables
		flag = 0;
		result = 0;
		
		// Calculate Minimum Bags
		while (N >= 0) {
			// If Divided by 5, Then Convert All Remain N's to 5 Sugar Bag
			if (N % 5 == 0) {
				flag = 1;
				result += (N / 5);
				break;
			}
			
			// Make 3 Sugar Bag
			result++;
			N -= 3;
		}
		
		// Print Result
		if (flag == 1) System.out.println(result);
		else System.out.println(-1);
	}
}
