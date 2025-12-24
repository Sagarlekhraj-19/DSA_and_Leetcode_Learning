#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>

int main() {
    std::cout << "=== HASH FUNCTIONS FOR DIFFERENT DATA TYPES ===\n\n";
    
    // 1. INT - Hash for integers
    std::cout << "1. INT:\n";
    std::hash<int> int_hasher;
    int num = 42;
    size_t int_hash = int_hasher(num);
    std::cout << "   Value: " << num << " -> Hash: " << int_hash << "\n";
    std::cout << "   Note: Integer hash is typically the value itself\n\n";
    
    // 2. CHAR - Hash for single characters
    std::cout << "2. CHAR:\n";
    std::hash<char> char_hasher;
    char ch = 'A';
    size_t char_hash = char_hasher(ch);
    std::cout << "   Value: '" << ch << "' -> Hash: " << char_hash << "\n";
    std::cout << "   Note: Character converted to integer then hashed\n\n";
    
    // 3. DOUBLE - Hash for floating-point numbers
    std::cout << "3. DOUBLE:\n";
    std::hash<double> double_hasher;
    double dbl = 3.14159;
    size_t double_hash = double_hasher(dbl);
    std::cout << "   Value: " << dbl << " -> Hash: " << double_hash << "\n";
    std::cout << "   Note: Uses bit representation of the double\n\n";
    
    // 4. LONG LONG - Hash for large integers
    std::cout << "4. LONG LONG:\n";
    std::hash<long long> ll_hasher;
    long long big_num = 9223372036854775807LL;
    size_t ll_hash = ll_hasher(big_num);
    std::cout << "   Value: " << big_num << " -> Hash: " << ll_hash << "\n";
    std::cout << "   Note: May fold bits for 32-bit size_t\n\n";
    
    // 5. STRING - Hash for strings
    std::cout << "5. STRING:\n";
    std::hash<std::string> str_hasher;
    std::string text = "Hello";
    size_t str_hash = str_hasher(text);
    std::cout << "   Value: \"" << text << "\" -> Hash: " << str_hash << "\n";
    std::cout << "   Note: Uses complex algorithm on character sequence\n\n";
    
    // 6. BOOL - Hash for boolean values
    std::cout << "6. BOOL:\n";
    std::hash<bool> bool_hasher;
    bool flag = true;
    size_t bool_hash = bool_hasher(flag);
    std::cout << "   Value: " << (flag ? "true" : "false") << " -> Hash: " << bool_hash << "\n";
    std::cout << "   Note: true=1, false=0 typically\n\n";
    
    // 7. FLOAT - Hash for single-precision floats
    std::cout << "7. FLOAT:\n";
    std::hash<float> float_hasher;
    float flt = 2.718f;
    size_t float_hash = float_hasher(flt);
    std::cout << "   Value: " << flt << " -> Hash: " << float_hash << "\n";
    std::cout << "   Note: Similar to double but less precision\n\n";
    
    std::cout << "=== USING HASH MAPS (unordered_map) ===\n\n";
    
    // Example: unordered_map with int keys
    std::unordered_map<int, std::string> age_map;
    age_map[25] = "John";
    age_map[30] = "Alice";
    age_map[25] = "Bob";  // Overwrites John
    
    std::cout << "Int Key Map:\n";
    for (const auto& pair : age_map) {
        std::cout << "   Age " << pair.first << " -> " << pair.second << "\n";
    }
    std::cout << "\n";
    
    // Example: unordered_map with string keys
    std::unordered_map<std::string, int> score_map;
    score_map["Alice"] = 95;
    score_map["Bob"] = 87;
    score_map["Charlie"] = 92;
    
    std::cout << "String Key Map:\n";
    for (const auto& pair : score_map) {
        std::cout << "   " << pair.first << " -> Score: " << pair.second << "\n";
    }
    std::cout << "\n";
    
    // Example: unordered_map with double keys
    std::unordered_map<double, std::string> temp_map;
    temp_map[98.6] = "Normal body temp";
    temp_map[32.0] = "Freezing point";
    temp_map[100.0] = "Boiling point";
    
    std::cout << "Double Key Map:\n";
    for (const auto& pair : temp_map) {
        std::cout << "   " << pair.first << "°F -> " << pair.second << "\n";
    }
    
    return 0;
}