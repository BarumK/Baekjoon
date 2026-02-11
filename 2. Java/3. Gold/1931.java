import java.util.*;
import java.io.*;

/**
 * SW Expert Academy - BOJ 1931
 * @author Kim Jeongwook
 * 
 * @see #main(String[])
 * 1. Read N (number of meetings)
 * 2. Read N meeting intervals into meetings[][]
 *      2.1. meetings[i][0]: start time
 *      2.2. meetings[i][1]: end time
 * 3. Sort meetings by greedy priority
 *      3.1. Primary key: end time ascending
 *      3.2. Secondary key: start time ascending when end times are equal
 *           - This tie-break is required to handle cases like (4,4) correctly
 * 4. Select maximum number of non-overlapping meetings using greedy scan
 *      4.1. Select the first meeting in the sorted order
 *      4.2. Track the end time of the last selected meeting
 *      4.3. For each next meeting in order:
 *           4.3.1. If start >= current end, select it
 *           4.3.2. Update current end to the selected meeting's end
 * 5. Print result (maximum count)
 */
public class Main {
	// Constant Variables
	private static final int MAX_N = 100000;
	
	// Class Variables
	private static int TC, N, result;
	private static int[][] meetings = new int[MAX_N][2];
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	
	// Main Function
	public static void main(String[] args) throws Exception {
		// Initialization
		init();
		
		// Calculate Result by Using Greedy Algorithm
		greedy();
		
		// Print Result
		System.out.println(result);
	}
	
	
	// Utility Functions
	private static void init() throws Exception {
		// Read N
		N = Integer.parseInt(br.readLine().trim());
		
		// Read Meeting Informations
		for (int idx = 0; idx < N; idx++) {
			st = new StringTokenizer(br.readLine().trim());
			meetings[idx][0] = Integer.parseInt(st.nextToken());
			meetings[idx][1] = Integer.parseInt(st.nextToken());
		}
		
		// Sort Meetings by End Time -> Start Time
		Arrays.sort(meetings, 0, N, (a, b) -> {
		    if (a[1] != b[1]) return Integer.compare(a[1], b[1]); // end
		    return Integer.compare(a[0], b[0]);                   // start
		});
		
		// Initialize Variables
		result = 1;
	}
	
	private static void greedy() {
		// Set First Meeting's End Time
		int end = meetings[0][1];
		
		// Repeately Find Next Meeting
		for (int idx = 1; idx < N; idx++) {
			if (meetings[idx][0] >= end) {
				result++;
				end = meetings[idx][1]; 
			}
		}
	}
}
