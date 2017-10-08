import java.util.*;

public class Four {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();

		for (int i = 0; i < N; i++) {
			Map<Integer, ArrayList<Double>> carts = new HashMap<Integer, ArrayList<Double>>();
			Map<Integer, ArrayList<Integer>> circles = new HashMap<Integer, ArrayList<Integer>>();

			double r = scan.nextDouble();
			int t = scan.nextInt();
			double d = r * 2;

			int zombiesKilled = 1;

			for (int j = 0; j < t; j++) {
				double x = scan.nextDouble();
				double y = scan.nextDouble();

				ArrayList<Double> temp = new ArrayList<Double>();
				temp.add(x);
				temp.add(y);

				ArrayList<Integer> placeholder = new ArrayList<Integer>();
				carts.put(j, temp);
				circles.put(j, placeholder);
			}


			for (int k = 0; k < t; k++) {
				ArrayList<Double> cartier = carts.get(k);
				double x = cartier.get(0);
				double y = cartier.get(1);

				for (int z = 0; z < t; z++) {
					if (z == k) {
						circles.get(k).add(z);
					} else {
						ArrayList<Double> cartiero = carts.get(z);
						double xo = cartiero.get(0);
						double yo = cartiero.get(1);

						if (calculateDistance(x, y, xo, yo) <= d) {
							circles.get(k).add(z);
						}
					}
				}
			}

			for (int z = 0; z < t; z++) {
				if (circles.get(z).size() < zombiesKilled) {
					continue;
				}

				for (int x: circles.get(z)) {
					if (x != z) {
						int yeet = works(circles.get(z), circles.get(x));
						if (yeet > zombiesKilled) {
							zombiesKilled = yeet;
						}
					}
				}
			}

			System.out.println(zombiesKilled);
		}
	}

	public static double[] cartToString(String s) {
		double[] carts = new double[2];
		String[] cartbois = s.split(" ");

		carts[0] = Double.parseDouble(cartbois[0]);
		carts[1] = Double.parseDouble(cartbois[1]);

		return carts;
	}

	public static double calculateDistance(double x, double y, double xo, double yo) {
		return Math.sqrt(Math.pow((x-xo), 2) + Math.pow((y-yo), 2));
	}

	public static int works(ArrayList<Integer> circs, ArrayList<Integer> circles) {
		int count = 0;

		for (int i : circs) {
			if (circles.contains(i)) {
				count++;
			}
		}

		return count;
	}

}
