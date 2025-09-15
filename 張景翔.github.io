#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
class HugeInt {
    friend ostream& operator<<(ostream&, const HugeInt&);
public:
    static const int digits = 30; // Maximum number of digits
    HugeInt(long = 0);
    HugeInt(const string&);
    HugeInt operator+(const HugeInt&) const;
    HugeInt operator-(const HugeInt&) const;
private:
    short integer[digits] = { 0 };
};
// Constructor from long
HugeInt::HugeInt(long num) {
    for (int i = digits - 1; num > 0 && i >= 0; --i) {
        integer[i] = num % 10;
        num /= 10;
    }
}
// Constructor from string
HugeInt::HugeInt(const string& numStr) {
    int len = numStr.length();
    int pos = digits - len;
    for (int i = 0; i < len; ++i) {
        integer[pos + i] = numStr[i] - '0';
    }
}
// Addition operator
HugeInt HugeInt::operator+(const HugeInt& other) const {
    HugeInt result;
    int carry = 0;
    for (int i = digits - 1; i >= 0; --i) {
        int sum = integer[i] + other.integer[i] + carry;
        result.integer[i] = sum % 10;
        carry = sum / 10;
    }
    return result;
}
// Subtraction operator
HugeInt HugeInt::operator-(const HugeInt& other) const {
    HugeInt result;
    int borrow = 0;
    for (int i = digits - 1; i >= 0; --i) {
        int diff = integer[i] - other.integer[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        result.integer[i] = diff;
    }
    return result;
}
// Overload output stream operator
ostream& operator<<(ostream& out, const HugeInt& num) {
    int i = 0;
    while (i < HugeInt::digits && num.integer[i] == 0) {
        ++i;
    }
    if (i == HugeInt::digits) {
        out << "0";
    }
    else {
        for (; i < HugeInt::digits; ++i) {
            out << num.integer[i];
        }
    }
    return out;
}
int main() {
    string a, b, op;
    while (cin >> a >> op >> b) {
        HugeInt num1(a), num2(b), result;
        if (op == "+") {
            result = num1 + num2;
        }
        else if (op == "-") {
            result = num1 - num2;
        }
        cout << result << endl;
    }
    return 0;
}
