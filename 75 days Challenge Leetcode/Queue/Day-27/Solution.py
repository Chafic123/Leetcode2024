from collections import deque

class RecentCounter:
    def __init__(self):
        self.Q = deque()  # Initialize the deque to store ping timestamps

    def ping(self, t: int) -> int:
        self.Q.append(t)  # Add the current ping timestamp

        # Remove timestamps that are older than 3000 ms from the current ping
        while self.Q and self.Q[0] < t - 3000:
            self.Q.popleft()

        return len(self.Q)  # Return the number of pings in the last 3000 ms
