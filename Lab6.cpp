#include <iostream>

using namespace std;

//characteristics of point(coordinates)
struct Point {
    int x, y;
};

//inputing coords of points
void input(int* n, Point pt[]);

//point A is on an axe
bool onAxe(Point A);

//brute force algorithm
int bruteForce(int n, Point pt[]);

//does length AB cross an axe
bool crossesOneAxe(Point A, Point B);

//does length AB cross a point (0,0) (origin)
bool crossesOrigin(Point A, Point B);

int main() {
    int cnt = 0;
    int n;
    Point pt[10000];

    //input
    input(&n, pt);

    cnt = bruteForce(n, pt);
    cout << "Answer: ";
    cout << cnt;
    return 0;
}

void input(int* n, Point pt[]) {
    int i;
    cout << "Please, input number of points n: ";
    cin >> *n;
    for (i = 0; i < *n; i++) {
        cout << "x y : ";
        cin >> pt[i].x >> pt[i].y;
    }
}

inline bool onAxe(Point A) {
    return !(A.x * A.y);
}

int bruteForce(int n, Point pt[]) {
    int i, j, res = 0;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (!onAxe(pt[i]) && !onAxe(pt[j]) && crossesOneAxe(pt[i], pt[j])) {
                res++;
            }
    return res;
}

bool crossesOneAxe(Point A, Point B) {
    bool res;
    if (crossesOrigin(A, B) && (A.x * B.x < 0) && (A.y * B.y < 0)) {
        //crossed (0,0);
        res = 0;
    }
    else {
        res = (A.x * B.x < 0) ^ (A.y * B.y < 0);//in different quarters
    }
    return res;
}

inline bool crossesOrigin(Point A, Point B) {
    //equation of line, using 2 points
    return A.x * (B.y - A.y) == A.y * (B.x - A.x);
}




