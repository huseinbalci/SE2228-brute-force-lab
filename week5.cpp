/*Question 1
---------------
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Question 2
---------------
'^' means power. (2^5) = Math.pow(2,5) = 32

The series,
(1^1)+(2^2)+(3^3)+(4^4) ... (10^10) = 10405071317.

Find the last ten digits of the series.
(1^1)+(2^2)+(3^3)+ ...... +(1000^1000). */

#include <iostream>

using namespace std;

int question1(int array[],int arraySize){
    int index = 0;
    int max = 0;
    for (int i = 0; i < arraySize; ++i) {
        for (int j = i + 1; j < arraySize; ++j) {
            if ((array[j] - array[i]) > max) {
                max = (array[j] - array[i]);
            }
        }
        index++;
    }
    return max;
}

long long power(int base, int exponent) {
    long long result = 1;
    for (int i = 1; i <= exponent; ++i) {
        result *= base;
    }
    return result;
}

long long question2(int upperLimit) {
    long long sum = 0;
    long long lastTenDigitsMod = power(10, 10);
    for (int i = 1; i <= upperLimit; ++i) {
        long long number = 1;
        for (int j = 0; j < i; ++j) {
            number = (number * i) % lastTenDigitsMod;
        }
        sum = (sum + number) % lastTenDigitsMod;
    }
    return sum;
}

int main(){
    int prices[19] = {12,43,9,76,3,8,90,11,33,
                     56,8,9,23,54,73,78,23,
                     22,45};

    int result = power(2,6);
    int answer1 = question1(prices, 19);
    int answer2 = question2(1000);

    cout<<answer1<<endl;
    cout<<answer2<<endl;
    cout<<result<<endl;
    return 0;
}