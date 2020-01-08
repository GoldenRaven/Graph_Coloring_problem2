#include<iostream>
using namespace std;

int main()
{
    int node_num, side_num, color_num;
    node_num=9;
    side_num=0;
    if (side_num == 0){
        color_num = 1;
        cout << "1" << endl;
        for (int i = 0;i<node_num;i++){
            cout << "0 ";
        }
        cout << endl;
    }
}
