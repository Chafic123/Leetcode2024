import java.util.ArrayList;
import java.util.List;

class RecentCounter {
    final List<Integer> timestamps; // List to store the ping timestamps

    public RecentCounter() {
        timestamps = new ArrayList<>(); // Initialize the list
    }

    public int ping(int t) {
        timestamps.add(t); // Add the current ping timestamp

        // Count the number of pings in the last 3000 ms
        int count = 0;
        for (int i = timestamps.size() - 1; i >= 0; i--) {
            if (timestamps.get(i) >= t - 3000) {
                count++;
            } else {
                break; // No need to check older timestamps
            }
        }

        return count; // Return the number of pings in the last 3000 ms
    }
}
