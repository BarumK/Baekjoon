import java.util.*;
import java.io.*;

/**
 * BOJ 17472
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read Input And Initialize Variables
 * 		1.1. Read N And M
 * 		1.2. Read Entire Map Information
 * 		1.3. Initialize Parent Information For Land Cells
 * 		1.4. Initialize Result And Edge Information
 * 2. Identify Each Island By Union-Find
 * 		2.1. Check Adjacent Land Cells In Four Directions
 * 		2.2. Merge Connected Land Cells Into Same Set
 * 		2.3. Count Number Of Distinct Islands
 * 3. Generate All Possible Bridges
 * 		3.1. Scan Each Row To Find Horizontal Bridges
 * 			3.1.1. Check Distance Between Two Islands
 * 			3.1.2. Add Bridge If Length Is At Least 2
 * 		3.2. Scan Each Column To Find Vertical Bridges
 * 			3.2.1. Check Distance Between Two Islands
 * 			3.2.2. Add Bridge If Length Is At Least 2
 * 		3.3. Sort All Bridges By Length
 * 4. Build Minimum Spanning Tree By Kruskal's Algorithm
 * 		4.1. Traverse Bridges In Increasing Length Order
 * 		4.2. Skip Bridge If Two Islands Are Already Connected
 * 		4.3. Connect Two Islands And Add Bridge Length To Result
 * 5. Check Whether All Islands Are Fully Connected
 * 		5.1. Compare Root Of Every Land Cell
 * 		5.2. If Any Island Is Not Connected, Set Result To -1
 * 6. Print Final Result
 */
public class Main {
	// Constant Variables
	private static final int MAX_NM = 10;
	private static final int MAX_EDGE = 100;
	
	// Class Variables
	private static int N, M, numIsland, numEdge, result;
	private static int[][] map = new int[MAX_NM][MAX_NM];
	private static int[][] parent = new int[MAX_NM][MAX_NM];
	private static Set<Integer> islandID = new HashSet<>();
	private static Edge[] edges = new Edge[MAX_EDGE];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	private static int[][] direction = {
			{-1, 0, 1, 0},
			{0, 1, 0, -1}
	};
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Identify Islands
		identifyIsland();
		
		// Make All Possible Bridges
		makeEdge();
		
		// Calculate Minimum Sum by using Kruskal's Algorithm
		kruskal();
		
		// Check Result
		check();
		
		// Print Result
		System.out.println(result);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N, M
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		// Read Entire Map
		for (int row = 0; row < N; row++) {
			st = new StringTokenizer(br.readLine().trim());
			for (int col = 0; col < M; col++) {
				map[row][col] = Integer.parseInt(st.nextToken());
				parent[row][col] = (map[row][col] == 1) ? (M * row + col) : -1;
			}
		}
		
		// Initialize Variables
		islandID.clear();
		numEdge = 0;
		result = 0;
	}
	
	private static void identifyIsland() {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				// Pass Condition
				if (parent[row][col] == -1) continue;
				
				// Union
				for (int dir = 0; dir < 4; dir++) {
					// Next Coordinate
					int nextX = row + direction[0][dir];
					int nextY = col + direction[1][dir];
					
					// Pass Condition
					if (!inRange(nextX, nextY) || parent[nextX][nextY] == -1) continue;
					
					// Union
					union(row, col, nextX, nextY);
				}
			}
		}
		
		// Identify # of Islands
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				if (parent[row][col] != -1) islandID.add(find(row, col));
			}
		}
		numIsland = islandID.size();
	}
	
	private static void makeEdge() {
		// Horizontal Bridge
		for (int row = 0; row < N; row++) {
			// Temporal Variables
			int prev = -1;
			
			// Make Bridge
			for (int col = 0; col < M; col++) {
				// Pass Condition
				if (map[row][col] == 0) continue;
				
				// Check Previous Value
				if (prev != -1) {
					// Find Root
					int root1 = find(row, prev);
					int root2 = find(row, col);
					int len = (col - prev - 1);
					
					// Check & Add
					if ((root1 != root2) && (len > 1)) edges[numEdge++] = new Edge(root1, root2, len);
				}
				
				// Update Previous Value
				prev = col;
			}
		}
		
		// Vertical Bridge
		for (int col = 0; col < M; col++) {
			// Temporal Variables
			int prev = -1;
						
			// Make Bridge
			for (int row = 0; row < N; row++) {
				// Pass Condition
				if (map[row][col] == 0) continue;
				
				// Check Previous Value
				if (prev != -1) {
					// Find Root
					int root1 = find(prev, col);
					int root2 = find(row, col);
					int len = (row - prev - 1);
					
					// Check & Add					
					if ((root1 != root2) && (len > 1)) edges[numEdge++] = new Edge(root1, root2, len);
				}
				
				// Update Previous Value
				prev = row;
			}
		}
		
		// Sort Edges by Weight
		Arrays.sort(edges, 0, numEdge);
	}
	
	private static void kruskal() {
		for (int idx = 0, count = 0; (count < numIsland - 1) && (idx < numEdge); idx++) {
			// Select Current Node
			Edge cur = edges[idx];
			
			// Find Root
			int root1 = find(cur.node1 / M, cur.node1 % M);
			int root2 = find(cur.node2 / M, cur.node2 % M);

			// Check
			if (root1 == root2) continue;
			
			// Union
			result += cur.weight;
			union((cur.node1 / M), (cur.node1 % M), (cur.node2 / M), (cur.node2 % M));
			count++;
		}
	}
	
	private static void check() {
		// Temporal Variables
		boolean find = false;
		int value = -1;
		
		// Check All Islands Has Been Connected
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				if (parent[row][col] != -1) {
					// If First Value, Save
					if (find == false) {
						value = find(row, col);
						find = true;
					}
					// Else, Compare
					else {
						if (value != find(row, col)) {
							result = -1;
							return;
						}
					}
				}
			}
		}
	}
	
	private static int find(int x, int y) {
		// Decompose Value
		int row = parent[x][y] / M;
		int col = parent[x][y] % M;
		
		// Find Parent
		if ((x == row) && (y == col)) return parent[x][y];
		return (parent[x][y] = find(row, col));
	}
	
	private static void union(int x1, int y1, int x2, int y2) {
		// Find Root
		int root1 = find(x1, y1);
		int root2 = find(x2, y2);
		
		// Decompose Value
		int parentX1 = (root1 / M);
		int parentY1 = (root1 % M);
		int parentX2 = (root2 / M);
		int parentY2 = (root2 % M);
		
		// Union
		parent[parentX2][parentY2] = parent[parentX1][parentY1];
	}
	
	private static boolean inRange(int x, int y) {
		if (x < 0 || x >= N) return false;
		if (y < 0 || y >= M) return false;
		return true;
	}
	
	
	// Utility Class
	static class Edge implements Comparable<Edge> {
		// Class Variables
		int node1;
		int node2;
		int weight;
		
		// Methods
		public Edge(int node1, int node2, int weight) {
			this.node1 = node1;
			this.node2 = node2;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(this.weight, o.weight);
		}
	}
}
