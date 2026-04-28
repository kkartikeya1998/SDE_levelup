#include <string>
#include <vector>

// Target 1: JSON-like structure
class ApiServiceA {
public:
    std::string getData() {
        // Simulated JSON response
        return R"({"name": "Alice", "age": 30, "city": "Paris"})";
    }
};

// Target 2: CSV fields
class ApiServiceB {
public:
    std::string fetchRecord() {
        // name,age,city
        return "Bob,25,London";
    }
};


class LegacySystemC {
public:
    struct Record {
        std::string fullName;
        int years;
        std::string location;
    };

    Record retrieve() {
        return {"Charlie", 40, "New York"};
    }
};

// Target 4: key-value pairs
class ApiServiceD {
public:
    std::vector<std::pair<std::string, std::string>> getPairs() {
        return {
            {"username", "Diana"},
            {"user_age", "35"},
            {"user_city", "Berlin"}
        };
    }
};
