from collections import defaultdict

class Solution:
    def equalPairs(self, grid):
        hashmap = defaultdict(int)
        ans = 0
        row = len(grid)
        col = len(grid[0])

        # Store each row in the map with its frequency count
        for i in range(row):
            row_tuple = tuple(grid[i])  # Convert row to a tuple for hashmap key
            hashmap[row_tuple] += 1

        # Check each column against stored rows in the map
        for j in range(col):
            curr = []

            # Create a list for the current column
            for i in range(row):
                curr.append(grid[i][j])

            # Convert column list to tuple and increment answer by hashmap count
            ans += hashmap[tuple(curr)]

        return ans
