#include <iostream>

using namespace std;

int target(int a[], int ans, int i, int target, int size){
    if (i == size){
        return ans;
    }
    if (a[i] == target){
        return i;
    }
    return target(a, ans, i + 1, target, size);
}

int main()
{
    int a[5] = {10,20,30,40,50};
    int ans = target(a, -1, 0, 80, 5);
    cout<<ans;
}