//
//  Created by zhengwei on 2019/1/25.
//  Copyright © 2019 lanqiao. All rights reserved.
//

/*

 标题：错误票据

 某涉密单位下发了某种票据，并要在年终全部收回。

 每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。

 因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。

 你的任务是通过编程，找出断号的ID和重号的ID。

 假设断号不可能发生在最大和最小号。

 要求程序首先输入一个整数N(N<100)表示后面数据行数。
 接着读入N行数据。
 每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000）
 每个整数代表一个ID号。

 要求程序输出1行，含两个整数m n，用空格分隔。
 其中，m表示断号ID，n表示重号ID

 例如：
 用户输入：
2
5 6 8 11 9
10 12 9

 则程序输出：
 7 9


 再例如：
 用户输入：
6
164 178 108 109 180 155 141 159 104 182 179 118 137 184 115 124 125 129 168 196
172 189 127 107 112 192 103 131 133 169 158
128 102 110 148 139 157 140 195 197
185 152 135 106 123 173 122 136 174 191 145 116 151 143 175 120 161 134 162 190
149 138 142 146 199 126 165 156 153 193 144 166 170 121 171 132 101 194 187 188
113 130 176 154 177 120 117 150 114 183 186 181 100 163 160 167 147 198 111 119

 则程序输出：
 105 120


 资源约定：
 峰值内存消耗 < 64M
 CPU消耗  < 1000ms


 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

 注意: main函数需要返回0
 注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>，
 不能通过工程设置而省略常用头文件。

 提交时，注意选择所期望的编译器类型。
 */

/*原始数据连续，输入的时候是乱序的，求出断开的号码和重复的号码*/
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
const int MaxN = 10000;
int line;
int data[MaxN];

void s2i(string &str, int &num) {
    stringstream ss;
    ss << str;
    ss >> num;
}

int main(int argc, const char *argv[]) {
    scanf("%d", &line);
    getchar();
    int index = 0;
    for (int i = 0; i < line; ++i) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        string tmp;
        while (getline(iss, tmp, ' ')) {
            s2i(tmp, data[index++]);
        }
    }
//    最终index就是数据的个数
//    cout << index << endl;
//排序
    sort(data, data + index);
    int a, b;
    for (int i = 1; i < index; ++i) {
        if (data[i] == data[i - 1] + 2)a = data[i] - 1;//printf("%d ", data[i] - 1);
        if (data[i] == data[i - 1]) b = data[i];//printf("%d", data[i]);
    }
    printf("%d %d", a, b);
    return 0;
}