import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		long n;
		int a, b;
		n = scan.nextLong();
		a = scan.nextInt();
		b = scan.nextInt();

		long m = n + 1;
		long asum = sum(m,a);
		long bsum = sum(m,b);
		while (asum != bsum) {
			long ashifts = 0;
			long tmpa = m;
			while ((tmpa +1) % a ==0) {
				tmpa /= a;
				ashifts++;
			}

			asum += 1;
			asum -= ashifts*(a-1);

			long bshifts = 0;
			long tmpb = m;
			while ((tmpb +1) % b ==0) {
				tmpb /= b;
				bshifts++;
			}

			bsum += 1;
			bsum -= bshifts*(b-1);

			m++;
		}

		System.out.println(m);
	}

	private static long sum(long n, int base) {
		String s = Long.toString(n, base);
		int su = 0;
		for (int i = 0; i < s.length();i++) {
			if (s.charAt(i) <= 'z' && s.charAt(i) >='a') {
				su += s.charAt(i) - 'a' + 10;
			} else {
				su += s.charAt(i) - '0';
			}
		}

		return su;
	}
}
