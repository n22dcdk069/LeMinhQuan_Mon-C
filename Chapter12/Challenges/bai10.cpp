#include <iostream>
#include <fstream>
#include <string>

void decryptFile(const char* inputFile, const char* outputFile, int shift) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files.\n";
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        // Decrypt the character
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ch = ((ch - base - shift + 26) % 26) + base;
        }

        // Write the decrypted character to the output file
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();
}

int main() {
    const char* encryptedFile = "encrypted.txt";
    const char* decryptedFile = "decrypted.txt";
    int shift = 3;  // Adjust this based on the encryption shift used in Programming Challenge 9

    decryptFile(encryptedFile, decryptedFile, shift);

    std::cout << "Decryption complete. Decrypted data written to " << decryptedFile << std::endl;

    return 0;
}
