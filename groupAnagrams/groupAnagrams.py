from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        res = defaultdict(list) # Create a dictionay

        for s in strs:
            freqs = [0] * 26
            for c in s:
                freqs[ord(c) - ord('a')] += 1 # Create a frequency map
            res[tuple(freqs)].append(s) # Add the original word to the frequency map being used as a key in the dict

        return list(res.values()) # Since all the values are lists of anagrams we return them

        