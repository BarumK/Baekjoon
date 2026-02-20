import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 2252
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read Number of Students N and Number of Comparisons M
 * 2. Build a Directed Graph and Calculate In-Degree for each Node
 * 3. Perform Topological Sort:
 * 		3.1. Add all Nodes with In-Degree of 0 to the Queue
 * 		3.2. While Queue is Not Empty:
 * 			3.2.1. Poll a Student(Node) and Append to Result String
 * 			3.2.2. Decrease In-Degree of Linked Students
 * 			3.2.3. If a Linked Student's In-Degree becomes 0, Add to Queue
 * 4. Print the Sorted Sequence of Students
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 32000;
	
	// Class Variables
	private static int N, M;
	private static int[] inDegree = new int[MAX_N + 1];
	private static Deque<Integer>[] graph = new ArrayDeque[MAX_N + 1];
	private static Deque<Integer> queue = new ArrayDeque<>();
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Get Result String by Using Topological Sort
		topologicalSort();
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N, M
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		// Initialize Graph & In-Degree Array
		for (int idx = 0; idx <= N; idx++) {
			graph[idx] = new ArrayDeque<>();
			inDegree[idx] = 0;
		}
		
		// Initialize Queue
		queue.clear();
		
		// Read Edge Information
		for (int edge = 0; edge < M; edge++) {
			// Get Node #
			st = new StringTokenizer(br.readLine().trim());
			int from = Integer.parseInt(st.nextToken());
			int to = Integer.parseInt(st.nextToken());
			
			// Add to Graph & Update In-Degree
			inDegree[to]++;
			graph[from].offerLast(to);
		}
	}
	
	private static void topologicalSort() {
		// Add All Nodes With In-Degree of 0 to Queue
		for (int idx = 1; idx <= N; idx++) {
			if (inDegree[idx] == 0) queue.offerLast(idx);
		}
		
		// Loop While Queue is Not Empty
		while (!queue.isEmpty()) {
			// Pop Element & Add Element to Result String
			int cur = queue.pollFirst();
			sb.append(cur + " ");
			
			// Seek Linked Node
			for (int next : graph[cur]) {
				inDegree[next]--;
				if (inDegree[next] == 0) queue.offerLast(next);
			}
		}
	}
}
