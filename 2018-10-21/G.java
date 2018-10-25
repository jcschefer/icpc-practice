import java.math.*;
import java.util.*;
public class G {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String fact = scan.next();
		BigInteger big = new BigInteger(fact);

		int n = 1;
		while (!big.equals(BigInteger.valueOf(2))) {
			BigInteger div = big.gcd(big.divide(BigInteger.valueOf(2)));
			big = div;
			n++;
		}

		System.out.println(n);
	}
}
