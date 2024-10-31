from collections import deque

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        dire = deque()     # Queue to store indices of 'D' (Dire party)
        radiant = deque()  # Queue to store indices of 'R' (Radiant party)
        n = len(senate)

        # Populate the queues with the indices of each party's senators
        for i in range(n):
            if senate[i] == 'D':
                dire.append(i)      
            else:
                radiant.append(i)

        # Simulate the process of senators banning each other
        while dire and radiant:
            r = radiant.popleft()
            d = dire.popleft()
            # The one with the smaller index survives and gets to ban the other party's senator
            if r < d:
                radiant.append(r + n)  # Radiant senator will be at the back of the line after banning
            else:
                dire.append(d + n)      # Dire senator will be at the back of the line after banning

        # Return the winner based on which queue is empty
        return "Dire" if radiant else "Radiant"
