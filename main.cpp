#include<iostream>
#include<fstream>
#include<iomanip>
#include<algorithm>

using namespace std;

class node{
public:
  int node_color,node_bond_num;
  int * node_bond_index;
};

int node_num, side_num, color_num;
node * nodes;

int main()
{
    void preprocess();
    preprocess();
    cout << node_num << "  " <<  side_num << endl;
    nodes[0].node_color = 0;
    for (int i=1;i<node_num;i++){//brush node one by one
        for (int j=0;j<node_num;j++){//brush from the first color 0
            bool j_not_exist = true;
            for (int k=0;k<nodes[i].node_bond_num;k++){
                if (j == nodes[nodes[i].node_bond_index[k]].node_color) j_not_exist = false;
            }
            if (j_not_exist){
                nodes[i].node_color = j;
            }
        }
    }
    int * color_configuration = new int [node_num];
    for (int i=0;i<node_num;i++){
        color_configuration[i] = nodes[i].node_color;
        cout << color_configuration[i] << " ";
    }
    int * temp = new int [node_num];
    temp = color_configuration;
    for (int i=1;i<node_num;i++){
        if (temp[0] < temp[i]) temp[0] = temp[i];
    }
    cout << temp[0] << endl;
}

void preprocess(){
    double fac(int);
    void init_node(void);
    ifstream fin("input");
    fin >> node_num >> side_num;
    fin.close();
    // 如果边数为0,最小颜色数为1,即全为0
    if (side_num == 0){
        color_num = 1;
        cout << color_num << endl;
        for (int i = 0; i < node_num-1; i++){
            cout << "0 ";
        }
        cout << "0" << endl;
        exit(0);
    // 如果边数为最大值,最小颜色数为节点数,即0,1,2,3,...
    }else if (side_num == fac(node_num)/(fac(node_num - 2)*fac(2))){
        color_num = node_num;
        cout << color_num << endl;
        for (int i = 0;i<node_num-1;i++){
            cout << i << " ";
        }
        cout << node_num-1 << endl;
        exit(1);
    }else{
        init_node();
        // cout << nodes[45].node_bond_num << endl;
    }
}

double fac(int n){
    double ans=1;
    for (int i=1;i<=n;i++){
        ans = ans * i;
    }
    return ans;
}

void init_node(){
    ifstream fin("input");
    fin >> node_num >> side_num;
    int ** sides = new int * [side_num];//open space for side array storage in input file
    for (int i=0;i<side_num;i++){
        sides[i] = new int [2];
    }
    for (int i=0;i<side_num;i++){//read sides from input file
        fin >> sides[i][0] >> sides[i][1];
    }
    fin.close();
    int ** bonds = new int * [side_num];//open space for bonds storage
    nodes = new node [node_num];
    for (int i=0;i<node_num;i++){//generate bonds of every node
        int count = 0;
        for (int j=0;j<side_num;j++){//count bonds of every node
            if (i == sides[j][0]) count++;
        }
        nodes[i].node_bond_num = count;
        bonds[i] = new int [count];
        int k = 0;
        for (int j=0;j<side_num;j++){//store sides into bonds
            if (i == sides[j][0]){
                bonds[i][k] = sides[j][1];
                k++;
            }
        }
    }
    for (int i=0;i<node_num;i++){
        nodes[i].node_bond_index = bonds[i];//initialize bond index
        nodes[i].node_color = node_num;//initialize node color to an illegal value
    }
}
