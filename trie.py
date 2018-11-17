import functools
import collections

words=['to','tea','ted','ten','inn','A']

_trie = lambda: collections.defaultdict(_trie)
trie = _trie()
for word in words: functools.reduce(dict.__getitem__, word, trie)

# to get the all keys with prefix t and e

print("No of keys with prefix t followed by e :",len(trie['t']['e']))

print("Nodes with prefix t followed by e :",trie['t']['e'])
