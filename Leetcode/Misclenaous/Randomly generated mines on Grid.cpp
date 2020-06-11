/* 
    I have a solution, but I think it works with O(m*n).

    Generate any random number from 0 to m*n.
    Generate i position by i=random%m and j by j=random%j
    Check if grid[i][j] is not occupied , place a mine and increment k
    Repeat this process till k times.

*/

public class GenerateKMines {

  public static void main(String[] args) {
    char grid[][]=new char[][]{{'-','-','-','-'},{'-','-','-','-'},{'-','-','-','-'}};
    new GenerateKMines().generateKMines(grid,3);
    for(int i=0;i<grid.length;i++){
      for(int j=0;j<grid[0].length;j++){
        System.out.print(grid[i][j]+" ");
      }
      System.out.println();
    }
  }

  public void generateKMines(char[][]grid, int K){
    int m = grid.length, n=grid[0].length;
    int count=0;
    Random random = new Random();
    while(count!=K){
      int index = random.nextInt(m*n);
      int i = index%m, j=index%n;
      if(grid[i][j]!='X'){
        grid[i][j]='X';
        count++;
      }

    }
  }
}