import java.util.*;

public class Tetra {
	static Map<Integer, Integer> memo = new HashMap<Integer,Integer>();

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();

		for (int i = 0; i < n; i++) {
			int query = scan.nextInt();
			System.out.println((i+1) + ": "+ query + " " + getOrCalculate(query));
		}
	}

	private static int getOrCalculate(int side) {
		if (side == 0) return 0;
		if (!memo.containsKey(side)) 
			memo.put(
				side,
				side*(side + 1)/2 + getOrCalculate(side - 1));
		return memo.get(side);
		
	}
}
