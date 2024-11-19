/* Trie
** log n
* Besser Substrings finden
 */
//START
class Trie:
    def __init__(self, words):
        self.root = {}
        for word in words:
            self.add(word)
    def add(self, word):
        cur = self.root
        for letter in word:
            if letter in cur:
                cur = cur[letter]
            else:
                cur[letter] = {}
                cur = cur[letter]
    def query(self, word):
        max_xor = 0
        cur = self.root
        l = len(word)
        cnt = 0
        for letter in word:
            cnt += 1
            if (1 ^ letter) in cur:
                max_xor ^= 2 ** (l - cnt)
                cur = cur[letter ^ 1]
            else:
                if letter not in cur:
                    return -1
                cur = cur[letter]
        return max_xor
//END
