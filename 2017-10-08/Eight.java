import java.util.*;
import java.util.regex.*;

public class Eight {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in).useDelimiter("\\s\n\\s*");
		int N = scan.nextInt();
		int count = 0;
		int time = 0;
		String currentBuffer = "";
		
		while (count < N) {
			if (scan.hasNextLine()) {
				time++;
			}
			String buffer = scan.next();
			int iB = buffer.indexOf(";");


			if (iB == -1) {
				currentBuffer += buffer;
			} else {
				while (iB != -1) {
					String yeet = buffer.substring(0, iB + 1);
					currentBuffer += yeet;

					if (currentBuffer.equals("NoZombies;")) {
						currentBuffer = "No Zombies;";
					}
					
					if (currentBuffer.indexOf(":") != -1) {
						currentBuffer = currentBuffer.substring(0, currentBuffer.indexOf(":") + 1) + " " + currentBuffer.substring(currentBuffer.indexOf(":") + 1).trim();
					}

					System.out.println(time + ": " + currentBuffer);
					currentBuffer = "";

					buffer = buffer.substring(iB + 1);
					iB = buffer.indexOf(";");
				}
				
				currentBuffer += buffer;
			}

			if (buffer.equals("END OF CASE")) { 
				count++;
				currentBuffer = "";
				time = 0;
				continue;
			}
		}
	}
}
