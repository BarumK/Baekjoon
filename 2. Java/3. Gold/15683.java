import java.util.*;
import java.io.*;

/**
 * BOJ 15683
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read N And M
 * 2. Read Entire Office Map
 * 		2.1. Store Each Cell Value
 * 		2.2. If Current Cell Is CCTV, Store Its Position And Type
 * 		2.3. Count Total Number Of CCTVs
 * 3. Initialize Result
 * 		3.1. Set Initial Result As Maximum Possible Blind Area
 * 4. Select Direction For Each CCTV Using Backtracking
 * 		4.1. If All CCTVs Are Assigned, Calculate Blind Area
 * 		4.2. Get Current CCTV Type
 * 		4.3. Try All Possible Direction Cases For Current CCTV
 * 		4.4. Store Selected Direction And Recurse To Next CCTV
 * 5. For Each Completed Direction Selection,
 * 		5.1. Copy Original Map To Temporary Map
 * 		5.2. For Every CCTV, Update Surveillance Area On Copied Map
 * 		5.3. Count Remaining Blind Spots
 * 		5.4. Update Minimum Result
 * 6. While Updating Surveillance Area,
 * 		6.1. Get CCTV Position, Type, And Selected Direction Case
 * 		6.2. For Every Direction Included In That Case, Move Straight
 * 		6.3. Stop If Wall Is Met
 * 		6.4. Mark Empty Cells As Observed
 * 		6.5. Continue Through Other CCTVs Or Observed Cells
 * 7. Print Final Minimum Blind Area
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 8;
	private static final int MAX_CCTV = 8;
	
	// Class Variables
	private static int N, M, result, cctvCount;
	private static int[][] map = new int[MAX_N][MAX_N];
	private static int[][] mapCopy = new int[MAX_N][MAX_N];
	private static int[][] cctv = new int[MAX_CCTV][3];
	private static int[] selected = new int[MAX_N];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	private static int[][] maxSelections = {
			// {CCTV Direction Type, # of Each CCTV Direction}
			{0, 0}, 
			{4, 1}, 
			{2, 2}, 
			{4, 2}, 
			{4, 3}, 
			{1, 4}
	}; 
	private static int[][][][] directions = {
			// [CCTV Type][CCTV Direction Type][CCTV Direction #][Delta X(0)/Y(1)]
			{},
			
			// CCTV 1
			{
				{ {-1, 0} }, // Case 1(Length 1)
				{ {0, 1} },  // Case 2(Length 1) 
				{ {1, 0} },  // Case 3(Length 1)
				{ {0, -1} }  // Case 4(Length 1)
			},
			
			// CCTV 2
			{
				{ {1, 0}, {-1, 0} },  // Case 1(Length 2)
				{ {0, 1}, {0, -1} }   // Case 2(Length 2)
			},
			
			// CCTV 3
			{
				{ {-1, 0}, {0, 1} },  // Case 1(Length 2)
				{ {0, 1}, {1, 0} },   // Case 2(Length 2)
				{ {1, 0}, {0, -1} },  // Case 3(Length 2)
				{ {0, -1}, {-1, 0} }, // Case 4(Length 2)
			},
			
			// CCTV 4
			{
				{ {-1, 0}, {0, 1}, {1, 0} },  // Case 1(Length 3)
				{ {0, 1}, {1, 0}, {0, -1} },  // Case 2(Length 3)
				{ {1, 0}, {0, -1}, {-1, 0} }, // Case 3(Length 3)
				{ {0, -1}, {-1, 0}, {0, 1} }, // Case 4(Length 3)
			},
			
			// CCTV 5
			{
				{ {-1, 0}, {0, 1}, {1, 0}, {0, -1} } // Case 1(Length 4)
			}
	};
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Select Direction
		select(0);
		
		// Print Result
		System.out.println(result);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N, M
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		// Initialize Variables
		result = N * M;
		cctvCount = 0;
		
		// Read Entire Map
		for (int row = 0; row < N; row++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int col = 0; col < M; col++) {
				map[row][col] = Integer.parseInt(st.nextToken());
				if ((map[row][col] > 0) && (map[row][col] < 6)) {
					cctv[cctvCount][0] = row;
					cctv[cctvCount][1] = col;
					cctv[cctvCount][2] = map[row][col];
					cctvCount++;
				}
			}
		}
	}
	
	public static void select(int depth) {
		// Break condition
		if (depth == cctvCount) {
			calculate();
			return;
		}
		
		// Temporal Variables
		int curCCTVType = cctv[depth][2];
		int curCCTVCaseNum = maxSelections[curCCTVType][0];
		
		// Select
		for (int idx = 0; idx < curCCTVCaseNum; idx++) {
			selected[depth] = idx;
			select(depth + 1);
		}
	}
	
	private static void calculate() {
		// Copy Original Map
		copy();
		
		// Update
		for (int cctvNum = 0; cctvNum < cctvCount; cctvNum++) update(cctvNum);
		
		// Check Blind Area
		int tempCount = 0;
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				if (mapCopy[row][col] == 0) tempCount++;
			}
		}
		
		// Check Result
		if (tempCount < result) result = tempCount;
	}
	
	private static void copy() {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) mapCopy[row][col] = map[row][col];
		}
	}
	
	private static void update(int index) {
		// Local Variables
		int startX = cctv[index][0];
		int startY = cctv[index][1];
		int cctvType = cctv[index][2];
		int cctvDirIdx = selected[index];
		int cctvDirNum = maxSelections[cctvType][1];
		
		// Update
		for (int dir = 0; dir < cctvDirNum; dir++) {
			// Temporal Variables
			int deltaX = directions[cctvType][cctvDirIdx][dir][0];
			int deltaY = directions[cctvType][cctvDirIdx][dir][1];
			int nextX = startX + deltaX;
			int nextY = startY + deltaY;
			
			// Change
			while (inRange(nextX, nextY)) {
				// Mark
				if (mapCopy[nextX][nextY] == 6) break;
				else if (mapCopy[nextX][nextY] == 0) mapCopy[nextX][nextY] = 7;
				
				// Next Coordinate
				nextX += deltaX;
				nextY += deltaY;
			}
		}
	}
	
	private static boolean inRange(int x, int y) {
		if (x < 0 || x >= N) return false;
		if (y < 0 || y >= M) return false;
		return true;
	}
}
