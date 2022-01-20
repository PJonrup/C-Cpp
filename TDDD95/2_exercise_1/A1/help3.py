
"""
IN:
3
how now brown <animal>
<foo> now <color> cow
who are you
<a> <b> <a>
<a> b
c <a>

OUT:
how now brown cow
-
c b

"""


if __name__ == "__main__":
    _cases = input()    # 3

    for i in range(int(_cases)):
        _input = input()    # word word word word
        pattern1 = _input.split()
        _input = input()
        pattern2 = _input.split()

        phrase = []
        pat1_count = 0
        length = len(pattern1)

        for j in range(length):  # varje position för ord
            if '<' in pattern1[j] and '<' in pattern2[j]:
                print('-')
                break
            elif '<' in pattern1[j]:
                phrase.append(pattern2[j])
            else:
                phrase.append(pattern1[j])
                pat1_count += 1

        if pat1_count != 0 and pat1_count != length:
            print(*phrase)
        else:
            print('-')
