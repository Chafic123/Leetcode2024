import java.util.*;

class Solution {
    public int equalPairs(int[][] grid) {
        Map<List<Integer>, Integer> hashmap = new HashMap<>();
        int ans = 0;
        int row = grid.length;
        int col = grid[0].length;

        // Store each row in the map with its frequency count
        for (int i = 0; i < row; i++) {
            List<Integer> rowList = new ArrayList<>();
            for (int j = 0; j < col; j++) {
                rowList.add(grid[i][j]);
            }
            hashmap.put(rowList, hashmap.getOrDefault(rowList, 0) + 1);
        }

        // Check each column against stored rows in the map
        for (int j = 0; j < col; j++) {
            List<Integer> curr = new ArrayList<>();

            // Create a list for the current column
            for (int i = 0; i < row; i++) {
                curr.add(grid[i][j]);
            }

            // Increment answer by the count of this column vector in the map
            ans += hashmap.getOrDefault(curr, 0);
        }

        return ans;
    }
}
