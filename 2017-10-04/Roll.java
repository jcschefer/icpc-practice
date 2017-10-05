import java.util.*;

public class Roll {
	public static void main(String [] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		for (int i = 0; i < n; i++) {
			Map<String, String> names = new HashMap<String, String>();

			int numNames = scan.nextInt();
			String[] ns = new String[numNames];
			for (int j = 0; j < numNames; j++) {
				String name = scan.next();
				names.put(name, "absent");
				ns[j] = name;
			}

			int numLines = scan.nextInt();
			scan.nextLine();
			for (int line = 0; line < numLines; line++) {
				String l = scan.nextLine();
				
				String[] words = l.split(" ");
				for (String w : words) {
					if (names.containsKey(w)) names.put(w, "present");
				}
			}

			System.out.println("Test set " + (i + 1) + ":");
			for (String name : ns) {
				
				System.out.println(name + " is " + names.get(name));
			}
			System.out.println();
		}
	}
}
