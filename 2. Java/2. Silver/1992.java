import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 1992
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read N
 * 2. Read N Lines And Build Map
 *      2.1. Convert Each Character To Integer (0 Or 1)
 *      2.2. Store Into 2D Array
 * 3. Build QuadTree String Using Divide And Conquer
 *      3.1. If Area Is Single Cell, Return Its Value
 *      3.2. If All Elements In Area Are Same, Return That Value
 *      3.3. Split Area Into 4 Quadrants Using Mid Points
 *      3.4. Recursively Build Strings For 4 Quadrants
 *      3.5. Merge As (S1 S2 S3 S4)
 * 4. Print Result String
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 64;
	
	// Class Variables
	private static int N;
	private static int[][] map = new int[MAX_N][MAX_N];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Get Result String Using Divide And Conquer Approach
		sb.append(getString(0, 0, N, N));
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N
		N = Integer.parseInt(br.readLine().trim());
		
		// Read Entire Map
		for (int row = 0; row < N; row++) {
			String line = br.readLine().trim();
			for (int col = 0; col < N; col++) map[row][col] = (line.charAt(col) - '0');
		}
	}
	
	private static String getString(int startRow, int startCol, int endRow, int endCol) {
		// Break Condition: Only One Element
		if ((startRow + 1 == endRow) && (startCol + 1 == endCol)) return ("" + map[startRow][startCol]);
		
		// Early Return Condition: All Elements are Same
		boolean flag = true;
		int prev = map[startRow][startCol];
		for (int row = startRow; row < endRow; row++) {
			for (int col = startCol; col < endCol; col++) {
				if (prev != map[row][col]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) return ("" + map[startRow][startCol]);
		
		// Local Varaiables
		String result;
		int midRow = (startRow + endRow) / 2;
		int midCol = (startCol + endCol) / 2;
		
		// Get Divided String Information
		String s1 = getString(startRow, startCol, midRow, midCol);
		String s2 = getString(startRow, midCol, midRow, endCol);
		String s3 = getString(midRow, startCol, endRow, midCol);
		String s4 = getString(midRow, midCol, endRow, endCol);
		
		return String.format("(%s%s%s%s)", s1, s2, s3, s4);
	}
}
