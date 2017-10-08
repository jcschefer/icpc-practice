import java.util.*;

public class Six {
	
	public static char[][] grid;

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		
		for (int i = 0; i < N; i++) {
			int width = scan.nextInt();
			int height = scan.nextInt();
			scan.nextLine();
			
			grid = new char[height][width];

			for (int r = 0; r < height; r++) {
				String str = scan.nextLine();
				for (int c = 0; c < width; c++) grid[r][c] = str.charAt(c);
			}

			int infected = scan.nextInt();
			for (int j = 0; j < infected; j++) {
				int c = scan.nextInt();
				int r=scan.nextInt();
				boolean[][] used = new boolean[height][width];
				for (int a = 0; a < height;a++){
					for( int b = 0; b < width;b++) {
						used[a][b] = false;
					}
				}

				infectionEvent(used, r ,c, -1, -1);
			}

			for (int row = 0; row < height; row++) {
				for (int col = 0; col < width; col++) {
					System.out.print(grid[row][col]);
				}
				System.out.println();
			}
		}
	}

	public static void infectionEvent(boolean[][] used, int r, int c, int fromR, int fromC) {
		if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length) return;

		if (grid[r][c] == 'X') { 
			return;
		} else if (grid[r][c] == 'D') {
			if (!used[r][c]) {
			used[r][c] = true;
				if (r + 1 != fromR) infectionEvent(used, r + 1, c, r, c);
				if (r - 1 != fromR) infectionEvent(used, r - 1, c, r, c);
				if (c + 1 != fromC) infectionEvent(used, r, c + 1, r ,c);
				if (c - 1 != fromC) infectionEvent(used, r, c - 1, r ,c);
				return;
			}
		} else {
			grid[r][c] = (char)((int)grid[r][c] + 1);
			return;
		}
	}

}
