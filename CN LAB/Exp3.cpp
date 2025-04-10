// To implement error detection and correction using the Hamming code.
// Show parity bits, check bits and correct single-bit errors.
#include <iostream>
#include <vector>
using namespace std;

bool detector(string encoded)
{
    // Calculating parity bits
    vector<int> parity(3);
    parity[0] = (encoded[0] - '0') ^ (encoded[2] - '0') ^ (encoded[4] - '0') ^ (encoded[6] - '0');
    parity[1] = (encoded[1] - '0') ^ (encoded[2] - '0') ^ (encoded[5] - '0') ^ (encoded[6] - '0');
    parity[2] = (encoded[3] - '0') ^ (encoded[4] - '0') ^ (encoded[5] - '0') ^ (encoded[6] - '0');

    int bit = parity[0] * 1 + parity[1] * 2 + parity[2] * 4;
    return bit;
}

vector<int> encoder(string input)
{
    // Using even parity Hamming(7,4)
    int n = 7;
    vector<int> encoded(n, 0);
    int it = 0;

    // Assigning data bits
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && i != 1 && i != 3)
        {
            encoded[i] = input[it] - '0';
            it++;
        }
    }

    encoded[0] = encoded[2] ^ encoded[4] ^ encoded[6];
    encoded[1] = encoded[2] ^ encoded[5] ^ encoded[6];
    encoded[3] = encoded[4] ^ encoded[5] ^ encoded[6];

    return encoded;
}

int main()
{
    cout << "Enter a message (4 bits) : ";
    string input;
    cin >> input;

    vector<int> encodedMessage = encoder(input);

    cout << "Message (with Parity bits): ";
    for (int i = 0; i < encodedMessage.size(); i++)
        cout << encodedMessage[i];
    cout << endl;

    cout << "Enter received message (7 bits): ";
    string output;
    cin >> output;

    int errorBit = detector(output);
    if (errorBit == 0)
    {
        cout << "Message received correctly." << endl;
    }
    else
    {
        cout << "Message received incorrectly. Error detected at bit position: " << errorBit << endl;
    }

    return 0;
}
