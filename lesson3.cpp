#include <iostream>
#include <unordered_map>
#include <string>

void printMap(const std::unordered_map<std::string, int>& m, const std::string& label) {
    std::cout << label << ": ";
    if (m.empty()) {
        std::cout << "(empty)";
    } else {
        for (const auto& pair : m) {
            std::cout << "{" << pair.first << ": " << pair.second << "} ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::cout << "========== UNORDERED_MAP COMPLETE GUIDE ==========\n\n";
    
    // ===== 1. CREATION & INITIALIZATION =====
    std::cout << "1. CREATION & INITIALIZATION:\n";
    
    // Empty map
    std::unordered_map<std::string, int> map1;
    std::cout << "   Empty map created\n";
    
    // Initialize with values
    std::unordered_map<std::string, int> map2 = {
        {"apple", 5},
        {"banana", 3},
        {"orange", 7}
    };
    printMap(map2, "   Initialized map");
    
    // Copy constructor
    std::unordered_map<std::string, int> map3 = map2;
    printMap(map3, "   Copied map");
    std::cout << "\n";
    
    
    // ===== 2. INSERTION METHODS =====
    std::cout << "2. INSERTION METHODS:\n";
    std::unordered_map<std::string, int> inventory;
    
    // Method 1: Using [] operator (creates or overwrites)
    inventory["sword"] = 1;
    inventory["shield"] = 2;
    std::cout << "   After [] insertion: ";
    printMap(inventory, "");
    
    // Method 2: Using insert() - returns pair<iterator, bool>
    auto result = inventory.insert({"potion", 5});
    std::cout << "   insert() success: " << result.second << "\n";
    
    auto result2 = inventory.insert({"sword", 10});  // Won't overwrite
    std::cout << "   insert() on existing key: " << result2.second << " (false = already exists)\n";
    
    // Method 3: Using insert() with pair
    inventory.insert(std::make_pair("helmet", 1));
    
    // Method 4: Using emplace() - constructs in place (more efficient)
    inventory.emplace("boots", 1);
    
    // Method 5: Using insert_or_assign() - C++17 (overwrites if exists)
    inventory.insert_or_assign("sword", 10);  // Now it will overwrite
    
    printMap(inventory, "   After all insertions");
    std::cout << "\n";
    
    
    // ===== 3. ACCESSING ELEMENTS =====
    std::cout << "3. ACCESSING ELEMENTS:\n";
    
    // Method 1: Using [] operator (creates if doesn't exist)
    std::cout << "   sword count (using []): " << inventory["sword"] << "\n";
    std::cout << "   arrow count (creates with 0): " << inventory["arrow"] << "\n";
    printMap(inventory, "   After [] access");
    
    // Method 2: Using at() - throws exception if key doesn't exist
    try {
        std::cout << "   potion count (using at()): " << inventory.at("potion") << "\n";
        std::cout << "   invalid key: " << inventory.at("invalid") << "\n";
    } catch (const std::out_of_range& e) {
        std::cout << "   Exception caught: Key not found!\n";
    }
    std::cout << "\n";
    
    
    // ===== 4. SEARCHING & CHECKING =====
    std::cout << "4. SEARCHING & CHECKING:\n";
    
    // Method 1: Using find() - returns iterator
    auto it = inventory.find("shield");
    if (it != inventory.end()) {
        std::cout << "   Found shield: " << it->second << "\n";
    }
    
    // Method 2: Using count() - returns 0 or 1 for unordered_map
    if (inventory.count("helmet")) {
        std::cout << "   helmet exists\n";
    }
    
    // Method 3: Using contains() - C++20 (returns bool)
    #if __cplusplus >= 202002L
    if (inventory.contains("boots")) {
        std::cout << "   boots exists (using contains())\n";
    }
    #endif
    
    std::cout << "\n";
    
    
    // ===== 5. MODIFYING ELEMENTS =====
    std::cout << "5. MODIFYING ELEMENTS:\n";
    
    // Direct modification using []
    inventory["sword"] += 5;
    std::cout << "   sword after +=5: " << inventory["sword"] << "\n";
    
    // Modify using iterator
    auto it2 = inventory.find("potion");
    if (it2 != inventory.end()) {
        it2->second = 10;
        std::cout << "   potion modified via iterator: " << it2->second << "\n";
    }
    std::cout << "\n";
    
    
    // ===== 6. DELETION METHODS =====
    std::cout << "6. DELETION METHODS:\n";
    printMap(inventory, "   Before deletion");
    
    // Method 1: Using erase() with key
    size_t removed = inventory.erase("arrow");
    std::cout << "   Removed 'arrow': " << removed << " element(s)\n";
    
    // Method 2: Using erase() with iterator
    auto it3 = inventory.find("helmet");
    if (it3 != inventory.end()) {
        inventory.erase(it3);
        std::cout << "   Removed 'helmet' via iterator\n";
    }
    
    printMap(inventory, "   After deletions");
    std::cout << "\n";
    
    
    // ===== 7. SIZE & CAPACITY =====
    std::cout << "7. SIZE & CAPACITY:\n";
    std::cout << "   size(): " << inventory.size() << "\n";
    std::cout << "   empty(): " << (inventory.empty() ? "true" : "false") << "\n";
    std::cout << "   max_size(): " << inventory.max_size() << " (theoretical max)\n";
    std::cout << "   bucket_count(): " << inventory.bucket_count() << "\n";
    std::cout << "   load_factor(): " << inventory.load_factor() << "\n";
    std::cout << "\n";
    
    
    // ===== 8. ITERATION METHODS =====
    std::cout << "8. ITERATION METHODS:\n";
    
    // Method 1: Range-based for loop
    std::cout << "   Range-based loop:\n";
    for (const auto& pair : inventory) {
        std::cout << "      " << pair.first << ": " << pair.second << "\n";
    }
    
    // Method 2: Iterator loop
    std::cout << "   Iterator loop:\n";
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        std::cout << "      " << it->first << ": " << it->second << "\n";
    }
    
    // Method 3: Structured bindings (C++17)
    std::cout << "   Structured bindings:\n";
    for (const auto& [key, value] : inventory) {
        std::cout << "      " << key << ": " << value << "\n";
    }
    std::cout << "\n";
    
    
    // ===== 9. CLEARING =====
    std::cout << "9. CLEARING:\n";
    std::unordered_map<std::string, int> temp = {{"a", 1}, {"b", 2}};
    printMap(temp, "   Before clear()");
    temp.clear();
    printMap(temp, "   After clear()");
    std::cout << "\n";
    
    
    // ===== 10. COMPARISON OPERATIONS =====
    std::cout << "10. COMPARISON:\n";
    std::unordered_map<std::string, int> m1 = {{"x", 1}, {"y", 2}};
    std::unordered_map<std::string, int> m2 = {{"x", 1}, {"y", 2}};
    std::unordered_map<std::string, int> m3 = {{"x", 1}, {"z", 3}};
    
    std::cout << "   m1 == m2: " << (m1 == m2 ? "true" : "false") << "\n";
    std::cout << "   m1 == m3: " << (m1 == m3 ? "true" : "false") << "\n";
    std::cout << "   m1 != m3: " << (m1 != m3 ? "true" : "false") << "\n";
    std::cout << "\n";
    
    
    // ===== 11. SWAP =====
    std::cout << "11. SWAP:\n";
    std::unordered_map<std::string, int> first = {{"cat", 1}};
    std::unordered_map<std::string, int> second = {{"dog", 2}};
    
    printMap(first, "   First before swap");
    printMap(second, "   Second before swap");
    
    first.swap(second);
    
    printMap(first, "   First after swap");
    printMap(second, "   Second after swap");
    std::cout << "\n";
    
    
    // ===== 12. PRACTICAL EXAMPLE: WORD COUNTER =====
    std::cout << "12. PRACTICAL EXAMPLE - Word Counter:\n";
    std::string sentence = "hello world hello cpp world cpp cpp";
    std::unordered_map<std::string, int> wordCount;
    
    std::string word;
    size_t pos = 0;
    while (pos < sentence.length()) {
        size_t space = sentence.find(' ', pos);
        if (space == std::string::npos) {
            word = sentence.substr(pos);
            pos = sentence.length();
        } else {
            word = sentence.substr(pos, space - pos);
            pos = space + 1;
        }
        wordCount[word]++;  // Increment count
    }
    
    std::cout << "   Word frequencies:\n";
    for (const auto& [w, count] : wordCount) {
        std::cout << "      '" << w << "' appears " << count << " time(s)\n";
    }
    
    return 0;
}