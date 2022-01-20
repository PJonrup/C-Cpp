
"""
SETTING UP A PYTHON KERNEL:
https://nteract.io/kernels

In:
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay


OUT:
cat
eh
loops

RUN WITH:
python babelfish.py < C.0.in | diff - C.0.ans

"""

#def main():


if __name__ == "__main__":
    _input = input()

    dic = {}
    while _input:
        tmp = _input.split()
        dic[tmp[1]] = tmp[0]

        _input = input()

    _input = input()

    tran = []
    while _input:
        if _input in dic.keys():
            print(dic[_input])
        else:
            print("eh")
        try:
            _input = input()
        except:
            break
    #main()
