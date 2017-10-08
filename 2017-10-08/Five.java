import java.util.*;

public class Five {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		
		for (int i = 0; i < N; i++) {
			int[] genes = new int[14];
			boolean valid = true;
			for (int j = 0; j < 14; j++) {
				genes[j] = scan.nextInt();
				if (genes[i] > 9) valid = false;
			}

			if (!valid || isVulnerable(genes)){
				System.out.println("Vulnerable");
			} else{
				System.out.println("Immune");
			}
		}
	}

	public static boolean isVulnerable(int[] genes) {
		for (int i = 0; i < 14; i++) {
			for (int j = i + 1; j < 14; j++) {
				if (i == 13) j = 0;
				if (genes[i] == genes[j]) {
					int one = genes[i] ;
					int two = genes[ j];

					genes[i] = 11;
					genes[j] = 11;

					if (findTripStraight(genes, 0)) return true;

					genes[i] = one;
					genes[j] = two;
				}
			}
		}
		return false;
	}

	public static boolean findTripStraight(int[] genes, int soFar) {
		if (soFar > 3) {
			return true;
		}

		for (int i = 0; i < 14; i++ ) {
			if (genes[i] != 11) {
				if (isTriple(genes, i) || isStraight(genes, i)) {
					int one = genes[i];
					int two = genes[i + 1];
					int three = genes[i+2];
					genes[i] = 11;
					genes[i + 1] = 11;
					genes[i + 2] = 11;
					if (findTripStraight(genes, soFar + 1)) return true;
					genes[i] = one;
					genes[i+1] = two;
					genes[i+2] = three;
				}
			}
		}
		return false;
	}

	public static boolean isTriple(int[] genes, int begin) {
		return begin < genes.length - 2 && genes[begin] == genes[begin + 1] 
			&& genes[begin] == genes[begin + 2] && genes[begin] != 11;
	}
	public static boolean isDouble(int[] genes, int begin) {
		return begin < genes.length - 1 && genes[begin] == genes[begin + 1] 
			&& genes[begin] != 11;
	}
	public static boolean isStraight(int[] genes, int begin) {
		return begin < genes.length - 2 && genes[begin] + 1==  genes[begin + 1] 
			&& genes[begin] + 2== genes[begin + 2];
	}
}
