#include <iostream>
using namespace std;

int main() {
    // Case 1: Bit Framing
    string s;
    cout << "Input for Bit Stuffing: ";
    cin >> s;

    string head = "101";
    string tail = "101";
    string decoded = head;
    int counter = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            decoded += '1';
            counter++;
            if (counter == 5) {
                decoded += '0'; 
                counter = 0;
            }
        } else {
            decoded += '0';
            counter = 0;
        }
    }

    decoded += tail;
    cout << "Decoded (Bit Stuffing): " << decoded << endl;

    // Case 2: Byte Framing
    string s2;
    cout << "Input for Byte Stuffing: ";
    cin >> s2;

    int byte_window = 4;
    string flag = "1111";
    string escape = "0000";
    string decoder2 = flag;

    for (int i = 0; i < s2.size(); i += byte_window) {
        string temp = s2.substr(i, byte_window);
        if (temp == flag) {
            decoder2 += escape;
            decoder2 += flag;
        } else if (temp == escape) {
            decoder2 += escape;
            decoder2 += escape;
        } else {
            decoder2 += temp;
        }
    }

    decoder2 += flag;
    cout << "Decoded (Byte Stuffing): " << decoder2 << endl;

    // Case 3: Character Framing
    string s3;
    cout << "Input for Character Stuffing: ";
    cin >> s3;

    char start_char = '#';  
    char end_char = '#';   
    string decoder3 = string(1, start_char);  

    for (int i = 0; i < s3.size(); i++) {
        if (s3[i] == start_char || s3[i] == end_char) {
            decoder3 += start_char;  
        }
        decoder3 += s3[i];
    }

    decoder3 += end_char;  
    cout << "Decoded (Character Stuffing): " << decoder3 << endl;

    return 0;
}
