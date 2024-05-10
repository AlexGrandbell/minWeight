//题目内容：
//设某一机器由n个部件组成,部件编号为1~n，每一种部件都可以从m个不同的供应商处购得，供应商编号为1~m。设wij是从供应商j处购得的部件i的重量,cij是相应的价格。对于给定的机器部件重量和机器部件价格，计算总价格不超过d的最小重量机器设计。（注意：输出结果中第一行最后没有空格。比如下面的输出样例中1 3 1后面没有空格。）
//
//输入格式:
//
//第1行输入3个正整数n,m和d。接下来n行输入wij（每行m个整数），最后n行输入cij（每行m个整数）,这里1≤n、m≤100。
//
//输出格式：
//
//输出的第1行包括n个整数，表示每个对应的供应商编号，第2行为对应的最小重量。
//
//输入样例：
//
//3 3 7
//1 2 3
//3 2 1
//2 3 2
//1 2 3
//5 4 2
//2 1 2
//
//输出样例：
//
//1 3 1
//4
#include <iostream>
#include <vector>

using namespace std;

int n, m, d;
vector<int> w, c;
vector<int> x, bestx;//x是当前解的路径，bestx是最优解的路径
int currentW, bestW, currentD;//currentW是当前解的重量，bestW是最优解的重量，currentD是当前解的价格

void Backtrack(int t) {
    //t是当前处理的部件编号
    //当前解已经处理到了叶子节点，肯定是当前更优解
    if (t > n) {
        for (int i = 0; i < n; i++) {
            bestx[i] = x[i];
        }
        bestW = currentW;
        return;
    }
    for (int i = 0; i < m; i++) {
        x[t] = i;
        currentW += w[t * m + i];
        currentD += c[t * m + i];
        if (currentD <= d && currentW < bestW){
            Backtrack(t + 1);
        }
        currentW -= w[t * m + i];
        currentD -= c[t * m + i];
    }
}

int main() {
    cin >> n >> m >> d;
    w = vector<int>(n * m);
    c = vector<int>(n * m);
    x = vector<int>(n);
    bestx = vector<int>(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> w[i * m + j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i * m + j];
        }
    }
    currentW = 0;
    bestW = 100000;
    currentD = 0;
    Backtrack(0);
    cout << bestx[0] + 1;
    for (int i = 1; i < n; i++) {
        cout << " " << bestx[i] + 1;
    }
    cout << endl << bestW << endl;
    return 0;
}