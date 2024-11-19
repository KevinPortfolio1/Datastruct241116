#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 函数：读取CSV文件并按行分割
void readCSV(const string& filename) {
    ifstream file(filename); // 打开文件
    string line;

    if (!file.is_open()) {
        cerr << "Unable to open file!" << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream ss(line);  // 使用 stringstream 来解析每一行
        string cell;
        vector<string> row;

        // 逐个读取每列的数据，按逗号分隔
        while (getline(ss, cell, ',')) {
            row.push_back(cell);  // 将每个单元格的内容存储到 vector 中
        }

        // 输出当前行的数据
        for (const auto& field : row) {
            cout << field << " ";
        }
        cout << endl; // 每行输出后换行
    }

    file.close(); // 关闭文件
}

int main() {
    string filename = "data.csv"; // 假设 CSV 文件名为 "data.csv"
    readCSV(filename); // 调用函数读取 CSV 文件
    return 0;
}
