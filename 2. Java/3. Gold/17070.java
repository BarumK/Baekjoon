import java.util.*;
import java.io.*;

/**
 * BOJ 17070
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read Input
 * 		1.1. N: Size Of Map
 * 		1.2. map: Wall And Empty Space Information
 * 		1.3. dpTable[row][col][state]: Number Of Ways To Reach (row, col) With Given Pipe State
 * 			- state 0: Horizontal (-)
 * 			- state 1: Vertical (|)
 * 			- state 2: Diagonal (\)
 * 2. Base Condition
 * 		2.1. Initial Pipe Starts At (0,0)-(0,1)
 * 		2.2. Fill First Row For Horizontal Movement
 * 3. Apply Dynamic Programming
 * 		3.1. For Each Cell (row, col)
 * 		3.2. If Current Cell Is Wall, Skip
 * 		3.3. Horizontal State (0)
 * 			3.3.1. From Left Horizontal
 * 			3.3.2. From Left Diagonal
 * 		3.4. Vertical State (1)
 * 			3.4.1. From Upper Vertical
 * 			3.4.2. From Upper Diagonal
 * 		3.5. Diagonal State (2)
 * 			3.5.1. Check Three Cells (Up, Left, Current)
 * 			3.5.2. From All Three States
 * 4. Final Result
 * 		4.1. Sum All States At (N-1, N-1)
 * 5. Print Result
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 16;
	
	// Class Variables
	private static int N;
	private static int[][] map = new int[MAX_N][MAX_N];
	private static int[][][] dpTable = new int[MAX_N][MAX_N][3];
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
		System.out.println(dpTable[N - 1][N - 1][0] + dpTable[N - 1][N - 1][1] + dpTable[N - 1][N - 1][2]);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N
		N = Integer.parseInt(br.readLine().trim());
		
		// Read Entire Map & Initialize DP Table
		for (int row = 0; row < N; row++) {
			// Read Line
			st = new StringTokenizer(br.readLine().trim());
			
			for (int col = 0; col < N; col++) {
				// Parse Map Value
				map[row][col] = Integer.parseInt(st.nextToken());
				
				// Initialize DP Table(State: 0 - -, 1 - |, 2 = \)
				for (int state = 0; state < 3; state++) dpTable[row][col][state] = 0;
			}
		}
	}
	
	private static void dp() {
		// Base Condition
		for (int col = 1; col < N; col++) {
			if (map[0][col] == 1) break;
			dpTable[0][col][0] = 1;
		}
		
		// Loop
		for (int row = 1; row < N; row++) {
			for (int col = 1; col < N; col++) {
				for (int state = 0; state < 3; state++) {
					// Check Wall
					if (map[row][col] == 1) dpTable[row][col][state] = 0;
					else if ((state == 2) && ((map[row - 1][col] == 1) || (map[row][col - 1] == 1))) dpTable[row][col][state] = 0;
					else {
						// If Not Wall, Sum From All Possible Cases
						if (state == 0) dpTable[row][col][state] = dpTable[row][col - 1][0] + dpTable[row][col - 1][2];
						else if (state == 1) dpTable[row][col][state] = dpTable[row - 1][col][1] + dpTable[row - 1][col][2];
						else dpTable[row][col][state] = dpTable[row - 1][col - 1][0] + dpTable[row - 1][col - 1][1] + dpTable[row - 1][col - 1][2];
					}
				}
			}
		}
	}
}
