import java.util.*;

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();  // Stack to keep track of surviving asteroids

        for (int asteroid : asteroids) {
            boolean destroyed = false;  // Flag to track if the current asteroid is destroyed

            // Check for collisions between the current asteroid and those in the stack
            while (!stack.isEmpty() && asteroid < 0 && stack.peek() > 0) {
                if (stack.peek() < Math.abs(asteroid)) {
                    stack.pop(); // The asteroid in the stack is destroyed
                    continue;
                } else if (stack.peek() == Math.abs(asteroid)) {
                    stack.pop(); // Both asteroids are destroyed
                }
                
                destroyed = true; // Mark the current asteroid as destroyed
                break;
            }
            if (!destroyed) stack.push(asteroid); // If not destroyed, push the asteroid onto the stack
        }

        // Prepare the result array to collect remaining asteroids
        int[] result = new int[stack.size()];
        for (int i = stack.size() - 1; i >= 0; i--) { // Reverse to maintain original order
            result[i] = stack.pop();
        }

        return result;  // Return the result array
    }
}
