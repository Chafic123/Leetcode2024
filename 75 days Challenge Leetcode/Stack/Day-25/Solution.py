class Solution:
    def asteroidCollision(self, asteroids: list[int]) -> list[int]:
        stack = []  # Stack to keep track of surviving asteroids

        for asteroid in asteroids:
            destroyed = False  # Flag to track if the current asteroid is destroyed

            # Check for collisions between the current asteroid and those in the stack
            while stack and asteroid < 0 and stack[-1] > 0:
                if stack[-1] < abs(asteroid):
                    stack.pop()  # The asteroid in the stack is destroyed
                    continue
                elif stack[-1] == abs(asteroid):
                    stack.pop()  # Both asteroids are destroyed

                destroyed = True  # Mark the current asteroid as destroyed
                break
            
            if not destroyed:
                stack.append(asteroid)  # If not destroyed, push the asteroid onto the stack

        return stack  # Return the stack directly, as it maintains the correct order
