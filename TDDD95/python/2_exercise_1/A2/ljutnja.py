
"""

IN:
5 3
1
3
2

OUT:
1

---------

IN:
10 4
4
5
2
3

OUT:
4

Question:

M - number of candies
N - number of children

-1 candy = angry
-2 candy = angrier

-1 candy = angry * 1
-2 candy = angry * 4
-3 candy = angry * 9

python ljutnja.py < ljutnja.1.in | diff - ljutnja.1.ans

155
"""


if __name__ == "__main__":
    _input = input()
    m, n = _input.split()

    m = int(m)
    n = int(n)

    sum = 0
    list = []
    for i in range(n):

        _input = input()
        tmp = int(_input)
        sum += tmp
        list.append(tmp)

    diff = sum - m

    anger = 0
    multiplier = 1
    multiplier2 = 0
    i = 0
    while diff:     # will exit at 0 which is false
        if list[i]:     # will be false when list[i] = 0
            list[i] -= 1
            anger += (multiplier * multiplier) - (multiplier2 * multiplier2)
            diff -= 1

        if i == len(list) - 1:
            i = 0
            multiplier += 1
            multiplier2 += 1
        else:
            i += 1

    print(anger)
    print(list)












    #okej
