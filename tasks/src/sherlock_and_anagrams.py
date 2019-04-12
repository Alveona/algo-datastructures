"""Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other."""

from itertools import combinations
import collections

def get_all_substrings(string):
    length = len(string) + 1
    return [string[x:y] for x, y in combinations(range(length), r=2)]

def sherlockAndAnagrams(s):
    list1 = get_all_substrings(s)
    print(list1)
    for ind, el in enumerate(list1):
        list1[ind] = ''.join(sorted(el))
    print(list1)
    fr_map = dict(collections.Counter(list1))
    print(fr_map)
    i = 0
    for k, v in fr_map.items():
        if v > 1:
            i+=sum_n(v)
    print(i)
    return i


def sum_n(n):
    return sum([i for i in range(n)])


assert(sherlockAndAnagrams("abba") == 4)
assert(sherlockAndAnagrams("abcd") == 0)
assert(sherlockAndAnagrams("ifailuhkqq") == 3)
assert(sherlockAndAnagrams("kkkk") == 10)
assert(sherlockAndAnagrams("cdcd") == 5)
