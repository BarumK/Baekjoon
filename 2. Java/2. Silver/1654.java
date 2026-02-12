import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 1654
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read K, N
 * 2. Read K Cable Lengths
 * 3. Perform Parametric Search
 *      3.1. Set Start = 1
 *      3.2. Set End = Maximum Cable Length
 *      3.3. While Start <= End
 *              3.3.1. Calculate Mid
 *              3.3.2. If Possible Cable Count >= N
 *                      Increase Start (Try Longer Length)
 *              3.3.3. Else
 *                      Decrease End
 * 4. Return End (Maximum Possible Length)
 * 5. Print Result
 */
public class Main {
	// Constant Variables
	private static final int MAX_K = 10000;
	
	// Class Variables
	private static int K, N, result;
	private static int[] arr = new int[MAX_K];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Parametric Search
		sb.append(parametricSearch());
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read K, N
		st = new StringTokenizer(br.readLine().trim());
		K = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		// Read K Elements
		for (int idx = 0; idx < K; idx++) arr[idx] = Integer.parseInt(br.readLine().trim());
		
		// Sort Array
		Arrays.sort(arr, 0, K);
	}
	
	private static long parametricSearch() {
		// Local Variables
		long start = 1;
		long end = arr[K - 1];
		long mid = (start + end) / 2;
		
		// Parametric Search
		while (start <= end) {
			mid = (start + end) / 2;
			if (calculate(mid) >= N) start = mid + 1;
			else end = mid - 1;
		}
		
		return end;
	}
	
	private static long calculate(long range) {
		long result = 0;
		for (int idx = 0; idx < K; idx++) result += (arr[idx] / range);
		return result;
	}
}
