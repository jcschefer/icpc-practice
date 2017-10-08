import java.util.*;

public class Seven {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();

		for (int i = 0; i < N; i++) {
			int[] villages = new int[20];
			for (int j = 0; j < 20; j ++) villages[j] = scan.nextInt();

			for (int j = 19; j >= 0; j--) {
				if (j != 0) {
					villages[j - 1] += villages[j] / 2;
					villages[j] = villages[j] % 2;
				}
			}

			for (int j = 0; j < 20; j++) {
				System.out.print(villages[j]);
				if (j != 19) System.out.print(" ");
			}
			System.out.println();
		}
	}
}
