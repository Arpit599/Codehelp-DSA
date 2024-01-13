#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;

    switch(n > 0){
        case 1: {
            ans = 1;
            break;
        }
        default: break;
    }
    cout << ans;
    return 0;
}