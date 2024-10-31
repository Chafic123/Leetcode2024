import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public String predictPartyVictory(String senate) {
        Queue<Integer> dire = new LinkedList<>();     // Queue to store indices of 'D' (Dire party)
        Queue<Integer> radiant = new LinkedList<>();  // Queue to store indices of 'R' (Radiant party)
        int n = senate.length();

        // Populate the queues with the indices of each party's senators
        for (int i = 0; i < n; i++) {
            if (senate.charAt(i) == 'D') 
                dire.offer(i);      
            else  
                radiant.offer(i);
        }

        // Simulate the process of senators banning each other
        while (!dire.isEmpty() && !radiant.isEmpty()) {
            int r = radiant.poll();
            int d = dire.poll();
            // The one with the smaller index survives and gets to ban the other party's senator
            if (r < d) 
                radiant.offer(r + n); // Radiant senator will be at the back of the line after banning
            else 
                dire.offer(d + n);     // Dire senator will be at the back of the line after banning
        }

        // Return the winner based on which queue is empty
        return radiant.isEmpty() ? "Dire" : "Radiant";
    }
}
