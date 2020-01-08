#include<iostream>
using namespace std;

int main()
{
    int node_num, side_num, color_num;
    node_num=4;
    side_num=4;
    // 如果边数为0,最优排列只有一种,即全为0
    if (side_num == 0){
        color_num = 1;
        cout << color_num << endl;
        for (int i = 0; i < node_num; i++){
            cout << "0 ";
        }
        cout << endl;
    // 如果边数为1,最优排列为010000...,1位置可移动
    }else if (side_num == 1){
        color_num = 2;
        cout << color_num << endl;
            cout << "0 1 ";
        for (int i = 0;i<node_num-2;i++){
            cout << "0 ";
        }
        cout << endl;
    // 如果边数小于节点数,最优排列为010101...
    }else if (side_num < node_num){
        color_num = 2;
        cout << color_num << endl;
        for (int i = 0;i<node_num;i++){
            if (i%2 == 0) cout << "0 ";
            if (i%2 != 0) cout << "1 ";
        }
        cout << endl;
    // 如果边数等于节点数,最优排列为010101...,奇数最后位为2,偶数最后位为1
    }else if(side_num == node_num){
        if (side_num%2 == 0){
            color_num = 2;
            cout << color_num << endl;
            for (int i = 0;i<node_num-1;i++){
                if (i%2 == 0) cout << "0 ";
                if (i%2 != 0) cout << "1 ";
            }
            if (node_num%2 == 0) cout << "1 ";
            if (node_num%2 != 0) cout << "2 ";
            cout << endl;
        }else{
            color_num = 3;
            cout << color_num << endl;
            for (int i = 0;i<node_num-1;i++){
                if (i%2 == 0) cout << "0 ";
                if (i%2 != 0) cout << "1 ";
            }
            if (node_num%2 == 0) cout << "1 ";
            if (node_num%2 != 0) cout << "2 ";
            cout << endl;
        }
    }
}
