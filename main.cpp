#include <iostream>
using namespace std;

int calculate(int[][20], int);
int signal(int);

int main()
{
    int raw_determinant[20][20] = {0};
    cout << "请输入你的行列式阶数：" << endl;
    cin >> raw_determinant[0][0];
    cout << endl << "请输入你的行列式：" << endl;
    for(int i = 1; i <= raw_determinant[0][0]; i++)
        for(int j = 1; j <= raw_determinant[0][0]; j++)
            cin >> raw_determinant[i][j];
    int result = 0;
    for(int i = 1; i <= raw_determinant[0][0]; i++)
        result += raw_determinant[1][i] * calculate(raw_determinant, i) * signal(i);
    cout << result << endl;
    return 0;
}

int calculate(int determinant[][20], int row)
{
    int result = 0;
    int copy[20][20] = {0};     //将原行列式复制出一个新的行列式，这个行列式是原行列式展开的余子式，展开时按第一行展开。
    copy[0][0] = determinant[0][0] - 1;
    for(int i = 2; i <= determinant[0][0]; i++)
    {
        int j = 1;
        while(j <= determinant[0][0])
        {
            if(j < row)
            {
                copy[i - 1][j] = determinant[i][j];
                j++;
            }
            else
            {
                copy[i - 1][j] = determinant[i][j + 1]; 
                j++;
            }
        }
    }
    if(copy[0][0] > 2)
    {
        for (int i = 1; i <= copy[0][0]; i++)
            result += copy[1][i] * calculate(copy, i) * signal(i);
        return result;
    }

    else
        return (copy[1][1] * copy[2][2] - copy[1][2] * copy[2][1]);
}

int signal(int i)
{
    if((i + 1) % 2 == 1)
        return -1;
    else
        return 1;
}