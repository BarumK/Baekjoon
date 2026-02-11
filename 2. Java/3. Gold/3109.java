import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 3109
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read R, C and the map
 *      1.1. '.' means empty cell
 *      1.2. 'x' means blocked cell
 *      1.3. '*' means visited / occupied by a pipe
 * 2. For each starting row on the leftmost column,
 *      2.1. Run DFS to find one valid path to the rightmost column
 *      2.2. Use greedy move order to maximize total number of pipes
 *           - up-right, right, down-right
 *      2.3. Mark cells as visited immediately when entering DFS
 *           - Prevent overlaps between different pipes
 *           - Prevent re-search on failed branches (avoid TLE)
 * 3. Count successful pipes and print result
 */
public class Main {
	// Constant Variables
	private static final int MAX_R = 10000;
	private static final int MAX_C = 500;
	
	// Class Variables
	private static int TC, R, C, result;
	private static char[][] map = new char[MAX_R][MAX_C];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	private static int[] next = {-1, 0, 1};
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
			
		// Get Result Value
		for (int row = 0; row < R; row++) {
			if (dfs(row, 0)) result++;
		}
			
		// Add Result
		sb.append(result + "\n");
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read R, C
		st = new StringTokenizer(br.readLine().trim());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		// Read Entire Map
		for (int row = 0; row < R; row++) {
			String line = br.readLine().trim();
			for (int col = 0; col < C; col++) map[row][col] = line.charAt(col);
		}
		
		// Initialize Variables
		result = 0;
	}

	private static boolean dfs(int row, int col) {
		// Mark as Visited
		map[row][col] = '*';
		
		// Break Condition
		if (col == C - 1) return true;
		
		// Check Next Path
		for (int idx = 0; idx < 3; idx++) {
			// Find Next Coordinate
			int nextRow = row + next[idx];
			int nextCol = col + 1;
			
			// Check Connect is Available
			if (inRange(nextRow, nextCol) && (map[nextRow][nextCol] == '.')) {
				if (dfs(nextRow, nextCol)) return true;
			}
		}
		return false;
	}
	
	private static boolean inRange(int row, int col) {
		if (row < 0 || row >= R) return false;
		if (col < 0 || col >= C) return false;
		return true;
	}
}
