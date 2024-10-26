class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int) -> list[bool]:
        n = len(candies)  # Number of kids
        max_candies = max(candies)  # Find the maximum number of candies

        # Use list comprehension to check if each kid can have the greatest number of candies
        return [(candy + extraCandies) >= max_candies for candy in candies]
