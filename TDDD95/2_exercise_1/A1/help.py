
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

python help.py < help.in | diff - help.ans

"""


if __name__ == "__main__":
    try:

        _cases = input()    # 3

        for i in range(int(_cases)):
            _input = input()
            pattern1 = _input.split()
            _input = input()
            pattern2 = _input.split()

            phrase = []
            pat1_count = 0
            length = len(pattern1)

            dic1 = {}
            dic2 = {}

            for j in range(length):
                if '<' in pattern1[j] and '<' not in pattern2[j]:
                    if pattern1[j] in dic1.keys():
                        phrase.append('-')
                        break
                    else:
                        dic1[pattern1[j]] = pattern2[j]
                elif '<' in pattern2[j] and '<' not in pattern1[j]:
                    if pattern2[j] in dic2.keys():
                        phrase.append('-')
                        break
                    else:
                        dic2[pattern2[j]] = pattern1[j]

            if phrase:
                print('-')
                continue

            for n in range(length):
                if '<' not in pattern1[n] and '<' not in pattern2[n]:
                    phrase.append(pattern1[n])
                elif '<' not in pattern1[n] and '<' in pattern2[n] and pattern2[n] in dic2.keys():
                    phrase.append(dic2[pattern2[n]])

                elif '<' in pattern1[n] and pattern1[n] in dic1.keys():
                    phrase.append(dic1[pattern1[n]])
                else:
                    phrase.append("test")

            for m in range(length):
                if m != length - 1:
                    print(phrase[m], end = " ")
                else:
                    print(phrase[m])

    except:
        pass
