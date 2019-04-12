"""Given two strings, determine if they share a common substring. A substring may be as small as one character.

For example, the words "a", "and", "art" share the common substring
. The words "be" and "cat" do not share a substring."""

def twoStrings(s1, s2):
    s1_dict = dict(zip(list(s1), [i for i in range(len(s1))]))
    s2_dict = dict(zip(list(s2), [i for i in range(len(s2))]))
    initial_size = len(s1_dict)
    i = 0
    for k, v in s2_dict.items():
        if k in s1_dict.keys():
            i+=1
            # print(i)
        s1_dict[k] = v
        # print(s1_dict)
    # print('initial size was: ' + str(initial_size))
    # print('new size is: ' + str(len(s1_dict)))
    # print('expected :' + str(initial_size + len(s2_dict) - i))
    if len(s1_dict) != (initial_size + len(s2_dict)):
        print("YES")
        return "YES"
    else:
        print("NO")
        return "NO"

assert(twoStrings("hello", "world") == "YES")
assert(twoStrings("hi", "world") == "NO")
assert(twoStrings("ooooooo", "o") == "YES")
assert(twoStrings("o", "ooooooo") == "YES")
assert(twoStrings("hi", "ih") == "YES")
assert(twoStrings("hel", "wor") == "NO")
