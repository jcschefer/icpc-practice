import java.util.*;

public class Course {
	public static void main(String[] args) {
		ArrayList<Integer> unseen = new ArrayList<Integer>();
		ArrayList<Integer> seen = new ArrayList<Integer>();
		Map<Integer, Integer> mapBoi = new HashMap<Integer, Integer>();

		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		scan.nextLine();

		for (int i =0; i < n; i++) {
			String strNums[] = scan.nextLine().split(" ");
			List<Integer> nums = new ArrayList<Integer>();

			for(String s : strNums) nums.add(Integer.valueOf(s));

			for (int j = 0; j < n; j++) {
				mapBoi.put(iToNum(i, j, n), nums.get(j));
			}
		}

		seen.add(0);

	}

	public static int iToNum(int r, int c, int n) {
		return r * n + c;
	}

	public static int[] getLoc(int n, int size) {
		int loc[] = new int[2];

		int row = n / 3;
		int col = n % 3;

		loc[0] = row;
		loc[1] = col;

		return loc;
	}

	public static List<Integer> getNeighbors(int n, int size) {
		
	}

}
