import java.util.*;
import java.text.*;

public class Two {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		
		DecimalFormat formatter = new DecimalFormat("0.0000");

		for (int i = 0; i < N; i++) {
			int infMonth = scan.nextInt();
			int infYear = scan.nextInt();
			int strMonth = scan.nextInt();
			int strYear = scan.nextInt();

			if (infYear == strYear) {
				int gap = 13 - infMonth ;
				double incr = (double) (0.5 / gap);
				double eit = incr * (strMonth - infMonth);

//				String print = eit + 0.00005 + "";
				//print = print.substring(0, print.indexOf(".") + 5);
				//System.out.println(print);
				System.out.println(formatter.format(eit));
			} else {
				double eit = 0;
				infYear = infYear + 1;

				eit += ((double)(strMonth - 1)/12);
				eit += 0.5 + (strYear - infYear);

				//String print = eit + 0.00005 + "";
				//print = print.substring(0, print.indexOf(".") + 5);
				//System.out.println(print);
				System.out.println(formatter.format(eit));
			}
		}
	}
}
