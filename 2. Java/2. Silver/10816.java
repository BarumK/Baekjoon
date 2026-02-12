import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 10816
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read N
 * 2. Read N Integers And Count Using Array
 *      2.1. Convert Value To Index (Value + MAX_RANGE)
 *      2.2. Increase Count
 * 3. Read M
 * 4. For Each Query Number
 *      4.1. Convert Value To Index
 *      4.2. Append Count To StringBuilder
 * 5. Print Result String
 */
public class Main {
	// Constant Variables
	public static final int MAX_RANGE = 10000000;
	
	// Class Variables
	private static int N, M;
	private static int[] hashMap = new int[2 * MAX_RANGE + 1];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Find Numbers
		find();
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Initialize Hash Map
		for (int idx = 0; idx < 2 * MAX_RANGE + 1; idx++) hashMap[idx] = 0;
		
		// Read N
		N = Integer.parseInt(br.readLine().trim());
		
		// Read N Integers
		st = new StringTokenizer(br.readLine().trim());
		for (int idx = 0; idx < N; idx++) {
			int temp = Integer.parseInt(st.nextToken());
			hashMap[temp + MAX_RANGE]++;
		}
	}
	
	public static void find() throws Exception {
		// Read M
		M = Integer.parseInt(br.readLine().trim());
		
		// Read M Integers
		st = new StringTokenizer(br.readLine().trim());
		for (int idx = 0; idx < M; idx++) {
			int temp = Integer.parseInt(st.nextToken());
			sb.append(hashMap[temp + MAX_RANGE] + " ");
		}
	}
}
