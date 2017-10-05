import java.util.*;

public class Strategy {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();

		for (int i = 0; i < n; i++) {
			int k = scan.nextInt();

			int[] times = new int[k];
			List<Integer> tcopy = new ArrayList<Integer>(k);

			for (int j = 0; j < k; j++) {
				times[j] = scan.nextInt();
				System.out.println(k);
				tcopy.add(times[j]);
			}
			Arrays.sort(times);
		
			int sum = 0;
			int numcomplete = 0;
			for(int l = 0; l < k;l++) {
				sum += times[l];

				if (sum < 300 ) numcomplete ++;
			}

			System.out.print("Data set " + (k+1) + ":");
			for (int l = 0; l < k; l++) {
				System.out.print(" " + (char)((int)'A' + tcopy.indexOf(times[l])));
				tcopy.remove(times[l]);
			}

			System.out.print(" " + numcomplete + " " + sum);
			System.out.println();
			 
		}
	}

}
