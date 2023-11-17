#include <iostream>
#include <string>

// Function to replace all occurrences of a substring in a string
std::string replaceSubstring(const std::string& str, const std::string& oldSubstr, const std::string& newSubstr) {
    std::string result = str;
    size_t pos = 0;

    // Find and replace all occurrences of oldSubstr with newSubstr
    while ((pos = result.find(oldSubstr, pos)) != std::string::npos) {
        result.replace(pos, oldSubstr.length(), newSubstr);
        pos += newSubstr.length();
    }

    return result;
}

int main() {
    std::string string1 = "the dog jumped over the fence";
    std::string string2 = "the";
    std::string string3 = "that";

    // Call the replaceSubstring function
    std::string result = replaceSubstring(string1, string2, string3);

    // Display the result
    std::cout << "Original string: " << string1 << std::endl;
    std::cout << "String to replace: " << string2 << std::endl;
    std::cout << "Replacement string: " << string3 << std::endl;
    std::cout << "Resulting string: " << result << std::endl;

    return 0;
}
