class Solution:
    def canPlaceFlowers(self, flowerbed: list[int], n: int) -> bool:
        size = len(flowerbed)  # Get the size of the flowerbed
        counter = 0  # Counter to track how many flowers can be planted

        # Loop through each plot in the flowerbed
        i = 0
        while i < size:
            # Check if the current spot is empty (0) and that its neighbors (if any) are also empty
            if (flowerbed[i] == 0 and 
                (i == 0 or flowerbed[i - 1] == 0) and 
                (i == size - 1 or flowerbed[i + 1] == 0)):
                flowerbed[i] = 1  # Place a flower in the current spot
                counter += 1  # Increment the counter for planted flowers
                i += 1  # Skip the next spot as flowers cannot be planted adjacent to each other
            i += 1  # Continue to the next spot
        
        # Return true if we can plant 'n' or more flowers, otherwise false
        return counter >= n
