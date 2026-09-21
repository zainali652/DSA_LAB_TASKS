#include <iostream>
using namespace std;

int main()
{
    int arr[2][2][2] = {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };

    int search = 70;

    cout << "3D Array:" << endl << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << "Layer " << i + 1 << ":" << endl;

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }

        cout << endl;
    }

    cout << "Searching for: " << search << endl << endl;

    bool found = false;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (arr[i][j][k] == search)
                {
                    cout << "Element found!" << endl;
                    cout << "Layer: " << i + 1 << endl;
                    cout << "Row: " << j + 1 << endl;
                    cout << "Column: " << k + 1 << endl;
                    found = true;
                }
            }
        }
    }

    if (!found)
        cout << "Element not found!" << endl;

    return 0;
}