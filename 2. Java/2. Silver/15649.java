import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - SWEA 4130
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read N, M
 * 2. Recursively Select This Index's Number
 * 		2.1. If not visited, mark as visited and add to result and go next
 * 		2.2. If come back, mark as unvisited
 * 		2.3. If depth reaches, add to result string
 * 3. Print result string
 */
public class Main {
	// Constant Variables

	
	// Class Variables
	private static int N, M;
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Read N, M
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		// Perform Depth First Search
		dfs(0, new int[M], new int[N + 1]);
		
		// Print Result
		System.out.println(sb);
	}
	
	
	// Utility Functions
	private static void dfs(int depth, int[] result, int[] list) {
		// Print Condition
		if (depth == M) {
			for (int i = 0; i < M; i++) sb.append(String.format("%d ", result[i]));
			sb.append("\n");
			return;
		}
		
		// Selection
		for (int i = 1; i <= N; i++) {
			if (list[i] == 0) {
				result[depth] = i;
				list[i] = 1;
				dfs(depth + 1, result, list);
				list[i] = 0;
			}
		}
	}
}
