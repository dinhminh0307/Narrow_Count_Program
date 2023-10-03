#include <iostream>
/*A 10×10
 target is made out of five "rings" as shown. Each ring has a different point value: the outermost ring — 1 point, the next ring — 2 points, ..., the center ring — 5 points.


Vlad fired several arrows at the target. Help him determine how many points he got.

Input
The input consists of multiple test cases. The first line of the input contains a single integer t
 (1≤t≤1000
) — the number of test cases.

Each test case consists of 10 lines, each containing 10 characters. Each character in the grid is either X
 (representing an arrow) or .
 (representing no arrow).

Output
For each test case, output a single integer — the total number of points of the arrows.*/



// Algorithm to find total point

int find_total_point(char tmp[10][10]) {
    int sum = 0;
    int point_flag = 0;
    int outer_last_col = 9;
    int outer_first_col = 0;
    
    // row = i; col = j
    for(int i = 0; i < 10;i++) {
        point_flag++;
        for(int j = outer_first_col; j <= outer_last_col; j++) { // In the position j - 1, the point is always point - 1
            // Calculate the previous column before
            if(j == outer_first_col) {
                int n = outer_first_col - 1;
                int counter_flag = 0;
                for(counter_flag; counter_flag <= n; counter_flag++) {
                    if(tmp[i][counter_flag] == 'X') {
                        sum = sum + (counter_flag + 1);
                    }
                }
            }
            else if(j == outer_last_col) { // Counting for the last column of the point zone
                int n = outer_last_col + 1;
                int counter_flag = 0;
                for(counter_flag; counter_flag <= 10 - n; counter_flag++) {
                    if(tmp[i][counter_flag] == 'X') {
                        sum = sum + (counter_flag + 1);
                    }
                }
            }
            // For narrow in the right current point zone
            if(tmp[i][j] == 'X') {
                sum += point_flag;
            }
            else {
                continue;
            }

            // For reverse from 5 till 10, we change the order of the point zone follow the alogrithm below:
        }
        outer_first_col++;
        outer_last_col--;
    }
    return sum;
}

void solution() {
    int test_case;
    // Input number of test case
    std::cin >> test_case;
    //Input the table base on test case
    for(int i = 0; i < test_case;i++) {
        char table[10][10];
        for(int r = 0; r < 10; r++) {
            for(int c = 0; c < 10; c++) {
                std::cin >> table[r][c];
            }
        }
        std::cout << find_total_point(table);
    }
    
    
}

int main(void) {
    solution();
}