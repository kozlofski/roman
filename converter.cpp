#include <iostream>
using namespace std;

// #include <string>
int romanToArabic(char* roman);
char* arabicToRoman(int arabic);
int convertRomanDigitToInt(char roman);
enum romanNumbers {I = 1, V = 5, X = 10, L = 50, 
                    C = 100, D = 500, M = 1000};

int main() {

    char * roman {"MCM"};
    int arabic = 29;
    int length = 0;

    cout << roman << endl;
    arabic = romanToArabic(roman);
    cout << "value: " << arabic << endl;
    
    return 0;
}

int romanToArabic(char* roman) {
    int length = 0;
    while(roman[length] != '\0') length++;
    int result = 0;
    int i = length - 1;
    int curr = 0, next = 0; //next to następny w napisie
    int min = 0;
    int inRow = 1;
    
    while(roman[i] > 0) {
        next = curr;
        curr = convertRomanDigitToInt(roman[i]);
        if(curr >= next) {
            if(curr == next && ++inRow > 3) return -1;
            result += curr;
            min = next; // dalej mogą się pojawić tylko > min
            inRow = 1;
        }
        else if(curr > min && next == curr * 10) {
            result -= curr;
            min = next;
            inRow = 1;
        }
        else return -1;
        i--;
    }
    return result;
}

int convertRomanDigitToInt(char roman) {
    switch(roman) {
        case 'I': return I;
        case 'V': return V;
        case 'X': return X;
        case 'L': return L;
        case 'C': return C;
        case 'D': return D;
        case 'M': return M;
        default: return 0;
    }
}

char* arabicToRoman(int arabic) {
    char* result;

    

    return result;
}