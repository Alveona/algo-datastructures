"""Harold is a kidnapper who wrote a ransom note, but now he is worried it will be traced back to him through his handwriting. He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. The words in his note are case-sensitive and he must use only whole words available in the magazine. He cannot use substrings or concatenation to create the words he needs.

Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No."""

import collections

def checkMagazine(magazine, note):
        h1 = magazine.split()
        col1 = dict(collections.Counter(h1))
        # print(col1)
        h2 = note.split()
        col2 = dict(collections.Counter(h2))
        # print(col2)
        initial_size = len(col1)
        # print('initial size was ' + str(initial_size))
        for k, v in col2.items():
            # print(k, v)
            try:
                tmp = col1[k]
            except:
                pass
            col1[k] = v
            print(col1)
            if len(col1) == initial_size:
                if v > tmp:
                    print("No")
                    return "No"
        # print('new size is ' + str(len(col1)))

        if initial_size == len(col1):
            print("Yes")
            return "Yes"
        else:
            print("No")
            return "No"
        # print(col1)

# magazine = "give me one grand today night"
# note = "give one grand today"
assert(checkMagazine("give me one grand today night", "give one grand today") == "Yes")
assert(checkMagazine("two times three is not four", "two times two is four") == "No")
assert(checkMagazine("ive got a lovely bunch of coconuts", "ive got some coconuts") == "No")
assert(checkMagazine("some text from magazine", "some magazine") == "Yes")
assert(checkMagazine("some text from magazinee", "some magazine") == "No")
assert(checkMagazine("some some some text from magazine", "some magazine") == "Yes")
