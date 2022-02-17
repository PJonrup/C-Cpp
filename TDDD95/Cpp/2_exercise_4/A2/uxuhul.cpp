
/*

Problem B:
The Uxuhul Voting System

3 questions with yes/no answers

black stone = no
white stone = yes

all stones were black initially

all priests vote, starting with the youngest, and all could get their optimal solution.

---------------------

Input:
n = 1-100   voting rounds
m = 1-100   priests

[NNN, NNY, NYN, NYY, YNN, YNY, YYN, and YYY]
input = [1, 2, 3, 4, 5, 6, 7, 8]    1 being highest priority

----------------------

Output:
NYY

----------------------

TIPs:
if yes and no are equal, and the stone is currently no -> flip

-----------------------

pseudo:

enum

in n;
in m;

for n:
    for m:
        res = NNN;
        sum = {0, 0, 0}

        points = 8;
        while (points > 0):
            in x;
            switch(x):
                case NNN
                    pos = 0;
                    for str in res:
                        if (str[pos] != N)
                            sum[pos] += points;
                            pos++;
                    
                case NNY
                    pos = 0;
                    for str in res:
                        if (str[pos] != N)
                            sum[pos] += points;
                            pos++;
                    
                case ...

            points--;
        
        switch(res)
            case NNN:
                pos = max in sum:
                if(sum[pos] == N)
                    sum[pos] = Y;
                else
                    sum[pos] = N;
            case ...

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

enum vote {
    NNN = 1,
    NNY,
    NYN,
    NYY,
    YNN,
    YNY,
    YYN,
    YYY
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, x, res_int, points;
    
    cin >> n;
    while (n--) {
        cin >> m;
        string res = "NNN";
        res_int = NNN;

        while (m--) {
            int sum[3] = {0, 0, 0};
            points = 8;

            while (points > 0) {
                cin >> x;

                switch (x) {
                    case NNN:
                        if (res[0] != 'N') {
                            sum[0] += points;
                        }
                        if (res[1] != 'N') {
                            sum[1] += points;
                        }
                        if (res[2] != 'N') {
                            sum[2] += points;
                        }
                        break;
                    case NNY:
                        if (res[0] != 'N') {
                            sum[0] += points;
                        }
                        if (res[1] != 'N') {
                            sum[1] += points;
                        }
                        if (res[2] != 'Y') {
                            sum[2] += points;
                        }
                        break;
                    case NYN:
                        if (res[0] != 'N') {
                            sum[0] += points;
                        }
                        if (res[1] != 'Y') {
                            sum[1] += points;
                        }
                        if (res[2] != 'N') {
                            sum[2] += points;
                        }
                        break;
                    case NYY:
                        if (res[0] != 'N') {
                            sum[0] += points;
                        }
                        if (res[1] != 'Y') {
                            sum[1] += points;
                        }
                        if (res[2] != 'Y') {
                            sum[2] += points;
                        }
                        break;
                    case YNN:
                        if (res[0] != 'Y') {
                            sum[0] += points;
                        }
                        if (res[1] != 'N') {
                            sum[1] += points;
                        }
                        if (res[2] != 'N') {
                            sum[2] += points;
                        }
                        break;
                    case YNY:
                        if (res[0] != 'Y') {
                            sum[0] += points;
                        }
                        if (res[1] != 'N') {
                            sum[1] += points;
                        }
                        if (res[2] != 'Y') {
                            sum[2] += points;
                        }
                        break;
                    case YYN:
                        if (res[0] != 'Y') {
                            sum[0] += points;
                        }
                        if (res[1] != 'Y') {
                            sum[1] += points;
                        }
                        if (res[2] != 'N') {
                            sum[2] += points;
                        }
                        break;
                    case YYY:
                        if (res[0] != 'Y') {
                            sum[0] += points;
                        }
                        if (res[1] != 'Y') {
                            sum[1] += points;
                        }
                        if (res[2] != 'Y') {
                            sum[2] += points;
                        }
                        break;
                    default:
                        break;
                }
                points--;
            }

            int it = distance(sum, max_element(sum, sum + (sizeof(sum) / sizeof(int))));

            switch (res_int) {
                case NNN:
                    if (it == 0) {
                        res_int = YNN;
                        res = "YNN";
                    }
                    else if (it == 1) {
                        res_int = NYN;
                        res = "NYN";
                    }
                    else if (it == 2) {
                        res_int = NNY;
                        res = "NNY";
                    }
                    break;
                case NNY:
                    if (it == 0) {
                        res_int = YNY;
                        res = "YNY";
                    }
                    else if (it == 1) {
                        res_int = NYY;
                        res = "NYY";
                    }
                    else if (it == 2) {
                        res_int = NNN;
                        res = "NNN";
                    }
                    break;
                case NYN:
                    if (it == 0) {
                        res_int = YYN;
                        res = "YYN";
                    }
                    else if (it == 1) {
                        res_int = NNN;
                        res = "NNN";
                    }
                    else if (it == 2) {
                        res_int = NYY;
                        res = "NYY";
                    }
                    break;
                case NYY:
                    if (it == 0) {
                        res_int = YYY;
                        res = "YYY";
                    }
                    else if (it == 1) {
                        res_int = NNY;
                        res = "NNY";
                    }
                    else if (it == 2) {
                        res_int = NYN;
                        res = "NYN";
                    }
                    break;
                case YNN:
                    if (it == 0) {
                        res_int = NNN;
                        res = "NNN";
                    }
                    else if (it == 1) {
                        res_int = YYN;
                        res = "YYN";
                    }
                    else if (it == 2) {
                        res_int = YNY;
                        res = "YNY";
                    }
                    break;
                case YNY:
                    if (it == 0) {
                        res_int = NNY;
                        res = "NNY";
                    }
                    else if (it == 1) {
                        res_int = YYY;
                        res = "YYY";
                    }
                    else if (it == 2) {
                        res_int = YNN;
                        res = "YNN";
                    }
                    break;
                case YYN:
                    if (it == 0) {
                        res_int = NYN;
                        res = "NYN";
                    }
                    else if (it == 1) {
                        res_int = YNN;
                        res = "YNN";
                    }
                    else if (it == 2) {
                        res_int = YYY;
                        res = "YYY";
                    }
                    break;
                case YYY:
                    if (it == 0) {
                        res_int = NYY;
                        res = "NYY";
                    }
                    else if (it == 1) {
                        res_int = YNY;
                        res = "YNY";
                    }
                    else if (it == 2) {
                        res_int = YYN;
                        res = "YYN";
                    }
                    break;
                default:
                    break;
            }
        }

        cout << res << '\n';
    }
    
    return 0;
}