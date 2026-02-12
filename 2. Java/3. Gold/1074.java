import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 1074
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read N, R, C
 *      1.1. N: exponent for board size (2^N x 2^N)
 *      1.2. R: target row index
 *      1.3. C: target column index
 * 2. Initialize Size = 2^N And Result = 0
 * 3. Repeat Until Size Becomes 1
 *      3.1. Find Which Quadrant (1~4) Contains (R, C)
 *      3.2. Add Skipped Cell Count By Quadrant Order
 *              3.2.1. Quadrant 1: +0
 *              3.2.2. Quadrant 2: +(Size/2)^2
 *              3.2.3. Quadrant 3: +2*(Size/2)^2
 *              3.2.4. Quadrant 4: +3*(Size/2)^2
 *      3.3. Move (R, C) Into The Selected Quadrant Coordinate System
 * 4. Print Result
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 15;
	
	// Class Variables
	private static int N, row, col, size, result;
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Get Result String Using Divide And Conquer Approach
		findNumber();
		
		// Print Result
		System.out.println(result);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
		
		// Initialize variables
		result = 0;
		
		// Convert N to 2^N, Store to "size"
		size = 1;
		for (int idx = 0; idx < N; idx++) size *= 2;
	}
	
	private static int findRegion() {
		int mid = size / 2;
		
		if (row < mid && col < mid) return 1;
		else if (row < mid && col >= mid) return 2;
		else if (row >= mid && col < mid) return 3;
		else return 4;
	}
	
	private static void findNumber() {
		while (size >= 1) {
			switch (findRegion()) {
				case 1:
					size /= 2;
					break;
				case 2:
					size /= 2;
					result += size * size;
					col -= size;
					break;
				case 3:
					size /= 2;	
					result += size * size * 2;
					row -= size;
					break;
				case 4:
					size /= 2;
					result += size * size * 3;
					col -= size;
					row -= size;
					break;
			}
		}
	}
}
