#include <iostream>
#include <limits>
using namespace std;

int coinChange(int coins[], int amount, int size){
    if(amount == 0) return 0;
    if(amount < 0) return -1;

    int mini = INT_MAX;
    int ans = INT_MAX;

    for(int i = 0; i < size; i++){
        int recurAns = coinChange(coins, amount - coins[i], size);
        if (recurAns != INT_MAX && recurAns > 0) ans = recurAns + 1;
        else ans = INT_MAX;
        mini = min(ans, mini);
    }
    return mini;
}

int main(){
    int coins[] = {1, 2, 5};
    int ans = coinChange(coins, 11, 3);
    cout << ans << endl;
    return 0;
}