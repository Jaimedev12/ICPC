#include <iostream>
using namespace std;

int main() {
    int l, w, n;
    cin >> l >> w >> n;

    if (l * w < n) {
        cout << "impossible\n";
        return 0;
    }

    char grid[100][100] = {};
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        char c = 'A' + i;
        int area = (l * w - i) / (n - i);
        int width = area / l;
        int height = area / width;
        while (width * height != area || y + height > w) {
            height--;
            width = area / height;
        }
        for (int j = x; j < x + width; j++) {
            for (int k = y; k < y + height; k++) {
                grid[j][k] = c;
            }
        }
        y += height;
        if (y == w) {
            x++;
            y = 0;
        }
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
