#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
// Hàm cộng hai số nguyên lớn dưới dạng chuỗi
string add(const string &num1, const string &num2) {
    string result;
    int carry = 0;
    int n1 = num1.size();
    int n2 = num2.size();
    int max_len = max(n1, n2);

    for (int i = 0; i < max_len; ++i) {
        int digit1 = i < n1 ? num1[n1 - 1 - i] - '0' : 0;
        int digit2 = i < n2 ? num2[n2 - 1 - i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    if (carry) result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}

// Hàm trừ hai số nguyên lớn dưới dạng chuỗi
string subtract(const string &num1, const string &num2) {
    string result;
    int borrow = 0;
    int n1 = num1.size();
    int n2 = num2.size();

    for (int i = 0; i < n1; ++i) {
        int digit1 = num1[n1 - 1 - i] - '0';
        int digit2 = (i < n2) ? num2[n2 - 1 - i] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff + '0');
    }
    // Remove leading zeros
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result;
}

// Hàm nhân hai số nguyên lớn dưới dạng chuỗi
string multiply(const string &num1, const string &num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    string result(n1 + n2, '0');

    for (int i = n1 - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = n2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = mul / 10;
            result[i + j + 1] = (mul % 10) + '0';
        }
        result[i] += carry;
    }

    size_t start = result.find_first_not_of('0');
    if (start != string::npos) {
        result = result.substr(start);
    } else {
        result = "0";
    }
    return result;
}

// Hàm chia hai số nguyên lớn và lấy k chữ số sau dấu thập phân
string divide(const string &num1, const string &num2, int k) {
    string result;
    string quotient;
    string remainder = num1;
    string divisor = num2;
    
    if (divisor == "0") {
        return "ERROR: Division by zero"; // Xử lý chia cho 0
    }
    
    // Phần nguyên
    string integer_part;
    while (remainder.size() > divisor.size() || (remainder.size() == divisor.size() && remainder >= divisor)) {
        int count = 0;
        string temp = divisor;
        while (temp.size() < remainder.size()) {
            temp += '0';
        }
        while (temp <= remainder) {
            remainder = subtract(remainder, temp);
            count++;
            temp = add(temp, divisor);
        }
        integer_part += to_string(count);
    }

    // Phần thập phân
    string fractional_part;
    for (int i = 0; i < k; ++i) {
        remainder += '0';
        int count = 0;
        string temp = divisor;
        while (temp.size() < remainder.size()) {
            temp += '0';
        }
        while (temp <= remainder) {
            remainder = subtract(remainder, temp);
            count++;
            temp = add(temp, divisor);
        }
        fractional_part += to_string(count);
    }

    // Kết hợp phần nguyên và phần thập phân
    result = integer_part + "." + fractional_part;
    return result;
}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Hàm so sánh hai chuỗi số lớn
bool isSmaller(string str1, string str2) {
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n1 > n2)
        return false;

    for (int i = 0; i < n1; i++) {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}

// Hàm trừ chuỗi số lớn
string subtractStrings(string num1, string num2) {
    string result = "";

    int n1 = num1.length(), n2 = num2.length();
    int diff = n1 - n2;

    int carry = 0;

    for (int i = n2 - 1; i >= 0; i--) {
        int sub = ((num1[i + diff] - '0') - (num2[i] - '0') - carry);

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result.push_back(sub + '0');
    }

    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (num1[i] == '0' && carry) {
            result.push_back('9');
            continue;
        }
        int sub = ((num1[i] - '0') - carry);
        if (i > 0 || sub > 0)
            result.push_back(sub + '0');
        carry = 0;
    }

    reverse(result.begin(), result.end());

    // Loại bỏ các số 0 thừa ở đầu
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        return result.substr(pos);
    }

    return "0";
}

// Hàm chia chuỗi số lớn
pair<string, string> divide_string(string dividend, string divisor) {
    if (isSmaller(dividend, divisor)) {
        return {"0", dividend};  // Trả về thương là 0, phần dư là dividend
    }

    string quotient = "";
    string current = "0";

    for (char digit : dividend) {
        current += digit;

        // Loại bỏ các số 0 ở đầu
        size_t pos = current.find_first_not_of('0');
        if (pos != string::npos) {
            current = current.substr(pos);
        } else {
            current = "0";
        }

        int count = 0;
        while (!isSmaller(current, divisor)) {
            current = subtractStrings(current, divisor);
            count++;
        }

        quotient += (count + '0');
    }

    // Loại bỏ các số 0 thừa ở đầu của thương
    size_t pos = quotient.find_first_not_of('0');
    if (pos != string::npos) {
        quotient = quotient.substr(pos);
    } else {
        quotient = "0";
    }

    return {quotient, current};  // Trả về cả thương và phần dư
}

int main() {
    string num1, num2;
    int k;
    cout << "Nhập số nguyên lớn thứ nhất: ";
    cin >> num1;
    cout << "Nhập số nguyên lớn thứ hai: ";
    cin >> num2;
    cout << "Nhập số chữ số sau dấu thập phân: ";
    cin >> k;

    string sum = add(num1, num2);
    string diff = subtract(num1, num2);
    string prod = multiply(num1, num2);
    string div = divide(num1, num2, k);

    cout << "Tổng của " << num1 << " và " << num2 << " là: " << sum << endl;
    cout << "Hiệu của " << num1 << " và " << num2 << " là: " << diff << endl;
    cout << "Tích của " << num1 << " và " << num2 << " là: " << prod << endl;
    cout << "Thương của " << num1 << " chia cho " << num2 << " với " << k << " chữ số sau dấu thập phân là: " << div << endl;

    return 0;
}