#include <iostream>


// we use functional for std::hash
#include<functional> 

#include<unordered_set>
using namespace std;









int main() {
    


    hash<int> int_hasher;
    size_t h1=int_hasher(42); // same value as it is regardless of any compiler
    std::cout<<"This is hash for int number: "<<h1<<endl;  // it will give me 42


    // we have also for string 
    hash<string> string_hash;

    size_t h2=string_hash("hello"); // different value depends on the compiler, different compiler different value

    cout<<"This hash is for string: "<<h2<<endl;

    size_t value = string_hash("hello"s);  // if using std::string_literals

    cout<<"This is second experiment for string hash: "<<value<<endl;




    // now we have for double datatypes
     hash<double> double_hash;

    size_t d=double_hash(3.14);
    size_t d2=double_hash(0.14);
    cout<<"This is for double data type: "<<d<<endl;
    cout<<"This is for double data type: "<<d2<<endl;






    // we have other as well
    /*
    std::hash<int>
    std::hash<long>
    std::hash<long long>
    std::hash<unsigned int>
    std::hash<char>
    std::hash<bool>

    # for floating points

    std::hash<float>
    std::hash<double>
    std::hash<long double>

    ###for string datatyes


    std::hash<std::string>
    std::hash<std::wstring>
    std::hash<std::u16string>
    std::hash<std::u32string>
    


    */
    

    // we also have hash map containers( these are unordered containers. )

     
    unordered_map<int, int>  unordered_map_01; // hash tables for key value pairs, datatypes can be changed
    unordered_set<int> unordered_set_01;   // hash tables for unique values;
    unordered_set<int, int> setname;   // hash tables for unique key-values pair;


    // above duplicates are not allowed
    // but these are for duplicates 

    std::unordered_multimap;
    std::unordered_multiset;



    return 0;
}