/*
 *（1）用递归编写n!的函数，并在main主函数中调用此函数。
 *（2）有n个大小不同的盘片从大到小放在A柱上，另有B和C两个空柱，要求将这n个盘片从A柱搬到C柱上，
 * 在搬动过程中，每次只能搬一个盘片，而且小的不能放在大的之下。编写hanoi函数实现搬迁过程。
 *（3）编写一个程序，求解皇后问题：在n×n的方格棋盘上，放置n个皇后，
 * 要求每个皇后不同行、不同列、不同左右对角线。
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * questions 1 
 */
long long int factorial(int num);

/*
 * question 2
 */
/*
 * parameter 1 : begin postion
 * parameter 2 : target postion
 */
void move(char pos_1, char pos_2);
/*
 * depended function : move(char pos_1, char pos_2)
 * parameter 1 : num of hanoi
 * parameter 2 : begin postion
 * parameter 3 : temp postion
 * parameter 4 : target postion
 */
void hanoi(int num, char pos_1, char pos_2, char pos_3);

/*
 * question 3
 */
class Solution;

int main(void) {
    int n = 5;
    cout << "n! = " << factorial(n) << endl;
    hanoi(3, 'A', 'B', 'C');
    vector<vector<string>> result = Solution().solveNQueens(8);
    return EXIT_SUCCESS;
}


long long int factorial(int num) {
    if (num <= 1) {
        return 1;
    }
    else {
        return num * factorial(num - 1);
    }
}

void move(char pos_1, char pos_2) {
    cout << pos_1 << "->" << pos_2 << endl;
}

void hanoi(int num, char pos_1, char pos_2, char pos_3) {
    if (num == 1) {
        move(pos_1, pos_3);
    }
    else {
        hanoi(num - 1, pos_1, pos_3, pos_2);
        move(pos_1, pos_3);
        hanoi(num - 1, pos_2, pos_1, pos_3);
    }
}

class Solution {
private:
vector<vector<string>> result;
// n 为输入的棋盘大小
// row 是当前递归到棋盘的第几行了
void backtracking(int n, int row, vector<string>& chessboard) {
    if (row == n) {
        result.push_back(chessboard);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(row, col, chessboard, n)) { // 验证合法就可以放
            chessboard[row][col] = 'Q'; // 放置皇后
            backtracking(n, row + 1, chessboard);
            chessboard[row][col] = '.'; // 回溯，撤销皇后
        }
    }
}
bool isValid(int row, int col, vector<string>& chessboard, int n) {
    // 检查列
    for (int i = 0; i < row; i++) { // 这是一个剪枝
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // 检查 135度角是否有皇后
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};
