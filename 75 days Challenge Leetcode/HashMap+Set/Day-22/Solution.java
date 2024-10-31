import java.util.*;

class Solution {
    public boolean closeStrings(String word1, String word2) {
        
        if (word1.length() != word2.length()) return false;

        // Sets to store unique characters in each word
        Set<Character> setWord1 = new HashSet<>();
        Set<Character> setWord2 = new HashSet<>();

        // Maps to store the frequency of each character in each word
        Map<Character, Integer> freqWord1 = new HashMap<>();
        Map<Character, Integer> freqWord2 = new HashMap<>();

        // Populate set and frequency map for word1
        for (char c : word1.toCharArray()) {
            setWord1.add(c);           // Add character to set
            freqWord1.put(c, freqWord1.getOrDefault(c, 0) + 1); // Increment frequency
        }

        // Populate set and frequency map for word2
        for (char c : word2.toCharArray()) {
            setWord2.add(c);           // Add character to set
            freqWord2.put(c, freqWord2.getOrDefault(c, 0) + 1); // Increment frequency
        }

        // If the sets of characters are not the same, words can't be "close"
        if (!setWord1.equals(setWord2)) return false;

        // Lists to store the frequency counts of each character
        List<Integer> freqValues1 = new ArrayList<>(freqWord1.values());
        List<Integer> freqValues2 = new ArrayList<>(freqWord2.values());

        // Sort both frequency lists to compare them
        Collections.sort(freqValues1);
        Collections.sort(freqValues2);

        // Compare the frequency distributions
        return freqValues1.equals(freqValues2);
    }
}
