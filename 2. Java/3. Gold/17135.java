import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 17135
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * Function Call Graph:
 * 	main() --> init()
 * 	       +-> combination() -> simulate() --> gameSet()
 *                                         +-> findEnemy()
 *                                         +-> eliminateEnemy()
 *                                         +-> moveEnemy()
 * 1. Read Board Size N, M and Attack Distance D
 * 2. Select 3 Archer Positions using Combination (M C 3)
 * 3. For Each Combination, Simulate Game:
 * 		3.1. Copy Original Map and Count Initial Enemies
 * 		3.2. While Enemies Remain on the Board:
 * 			3.2.1. Each Archer Finds the Closest Enemy within Distance D (using BFS)
 * 			3.2.2. Archers Simultaneously Attack and Remove Enemies
 * 			3.2.3. Remaining Enemies Move Down One Row
 * 4. Update and Print Maximum Number of Eliminated Enemies
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 15;
	private static final int MAX_M = 15;
	
	// Class Variables
	private static int N, M, D, result;
	private static int remainEnemy, tempResult;
	private static int[][] map = new int[MAX_N][MAX_M];
	private static int[][] mapCopy = new int[MAX_N + 1][MAX_M];
	private static boolean[][] visited = new boolean[MAX_N + 1][MAX_M];
	private static Deque<int[]> queue = new ArrayDeque<>();
	private static int[] selected = new int[3];
	private static int[][] eliminateList = new int[3][2];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	private static int[][] delta = {
			{0, -1, 0},
			{-1, 0, 1}
	};
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Get Result by Using Combination
		combination(0, 0);
		
		// Print Result
		System.out.println(result);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N, M, D
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		
		// Initialize variables
		result = 0;
		
		// Read Entire Map
		for (int row = 0; row < N; row++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int col = 0; col < M; col++) map[row][col] = Integer.parseInt(st.nextToken());
		}
	}
	
	private static void combination(int depth, int start) {
		// Break Condition
		if (depth == 3) {
			simulate();
			return;
		}
		
		// Select
		for (int idx = start; idx < M; idx++) {
			selected[depth] = idx;
			combination(depth + 1, idx + 1);
		}
	}

	private static void simulate() {
		// Game Setting
		gameSet();
		
		// Simulate While Enemy Remains
		while(remainEnemy > 0) {
			// Find Enemies
			findEnemy();
			
			// Eliminate Enemies
			eleminiteEnemy();
			
			// Move Enemies
			moveEnemy();
		}
		
		// Update Result
		if (tempResult > result) result = tempResult; 
	}

	private static void gameSet() {
		// Initialize Variables
		remainEnemy = 0;
		tempResult = 0;
		
		// Copy Map
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				mapCopy[row][col] = map[row][col];
				if (map[row][col] == 1) remainEnemy++;
			}
		}
	}
	
	private static void findEnemy() {
		// Initialize Enemy List
		for (int idx = 0; idx < 3; idx++) eliminateList[idx][0] = -1;
		
		// Find Enemy for Each Archer by Using BFS
		for (int idx = 0; idx < 3; idx++) {
			// Initialize Queue
			queue.clear();
			
			// Initialize Visited Array
			for (int row = 0; row <= N; row++) {
				for (int col = 0; col < M; col++) {
					if (row == N) visited[row][col] = true;
					else visited[row][col] = false;
				}
			}
			
			// Push Start Point to Queue
			queue.offerLast(new int[] {N, selected[idx]});
			
			// Loop While Queue is Not Empty
			while (!queue.isEmpty()) {
				// Pop Element
				int[] cur = queue.pollFirst();
				
				// Check Current Point If Enemy Exists
				if (inRange(cur[0], cur[1]) && (mapCopy[cur[0]][cur[1]] == 1)) {
					eliminateList[idx][0] = cur[0];
					eliminateList[idx][1] = cur[1];
					break;
				}
				
				// Check Near Nodes
				for (int dir = 0; dir < 3; dir++) {
					// Next Point
					int nextRow = cur[0] + delta[0][dir];
					int nextCol = cur[1] + delta[1][dir];
					
					// Push to Queue If Possible
					if (inRange(nextRow, nextCol) 
							&& !visited[nextRow][nextCol]
							&& (calculateDistance(selected[idx], nextRow, nextCol) <= D)) {
						visited[nextRow][nextCol] = true;
						queue.offerLast(new int[] {nextRow, nextCol});
					}
				}
			}
		}
	}
	
	private static void eleminiteEnemy() {
		// Set Enemy(1) As Eliminated(0)
		for (int idx = 0; idx < 3; idx++) {
			// Pass Condition: Cannot Eliminate
			if (eliminateList[idx][0] == -1) continue;
			
			// Coordinates
			int row = eliminateList[idx][0];
			int col = eliminateList[idx][1];
			
			// Eliminate Enemy
			if (mapCopy[row][col] == 1) {
				mapCopy[row][col] = 0;
				remainEnemy--;
				tempResult++;
			}
		}
	}
	
	private static void moveEnemy() {
		for (int row = N - 1; row >= 0; row--) {
			for (int col = 0; col < M; col++) {
				// If Last Row, Reduce # of Enemy
				if ((row == N - 1) && (mapCopy[row][col] == 1)) remainEnemy--;
				
				// Shift Map
				if (row != 0) mapCopy[row][col] = mapCopy[row - 1][col];
				else mapCopy[row][col] = 0;
			}
		}
	}
	
	private static boolean inRange(int x, int y) {
		if (x < 0 || x >= N) return false;
		if (y < 0 || y >= M) return false;		
		return true;
	}
	
	private static int calculateDistance(int idx, int row, int col) {
		int result = (N - row);
		result += (idx > col) ? (idx - col) : (col - idx);
		
		return result;
	}
}
