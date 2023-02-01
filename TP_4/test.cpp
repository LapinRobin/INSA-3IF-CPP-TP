#include <iostream>
#include <vector>
#include <string>
#include <fstream>


std::vector<std::string> parseString(const std::string& str) {
    std::vector<std::string> fields;
    std::string currentField;
    bool insideQuotes = false;
    bool insideBrackets = false;
    for (char c : str) {
        if (c == '\"') {
            insideQuotes = !insideQuotes;
        } else if (c == '[') {
            insideBrackets = true;
        } else if (c == ']') {
            insideBrackets = false;
        } else if (c == ' ' && !insideQuotes && !insideBrackets) {
            fields.push_back(currentField);
            currentField.clear();
        } else {
            currentField += c;
        }
    }

    fields.push_back(currentField);
    return fields;
}

int main() {
/*     std::string input = "This is [fewjoiwe fwjeiofj] a \"sample string\" with spaces and \"quotes\"";

    std::vector<std::string> fields = parseString(input);

    for (const std::string& field : fields) {
        std::cout << field << std::endl;
    }

    return 0;

    */

    std::ifstream logfile("test.log");
    std::string log;

    logfile.seekg(0, std::ios::end);
    log.reserve(logfile.tellg());
    logfile.seekg(0, std::ios::beg);

    log.assign((std::istreambuf_iterator<char>(logfile)),
               std::istreambuf_iterator<char>());

    std::cout << log << std::endl;
    std::cout << std::endl;
    
    std::vector<std::string> fields = parseString(log);

    for (const std::string& field : fields) {
        std::cout << field << std::endl;
    }

    return 0;
    
}
