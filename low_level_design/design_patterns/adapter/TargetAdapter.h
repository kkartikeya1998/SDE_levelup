#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "IAdapter.h"
#include "Targets.h"

class ConcreteAdapter1 : public IAdapter {
private:
    ApiServiceA* target;

    std::string extractValue(const std::string& data, const std::string& key) {
        size_t keyPos = data.find(key);
        if (keyPos == std::string::npos) return "";

        size_t colon = data.find(":", keyPos);
        size_t start = data.find_first_of("\"0123456789", colon + 1);
        size_t end;

        if (data[start] == '"') {
            start++;
            end = data.find("\"", start);
        } else {
            end = data.find_first_not_of("0123456789", start);
        }

        return data.substr(start, end - start);
    }

public:
    ConcreteAdapter1() {
        target = new ApiServiceA();
    }

    std::string get_name() override {
        std::string data = target->getData();
        return extractValue(data, "name");
    }

    std::string get_city() override {
        std::string data = target->getData();
        return extractValue(data, "city");
    }
};


class ConcreteAdapter2 : public IAdapter {
private:
    ApiServiceB* target;

public:
    ConcreteAdapter2() {
        target = new ApiServiceB();
    }

    std::string get_name() override {
        std::string record = target->fetchRecord();
        std::stringstream ss(record);
        std::string name;
        std::getline(ss, name, ',');
        return name;
    }

    std::string get_city() override {
        std::string record = target->fetchRecord();
        std::stringstream ss(record);
        std::string item;

        // skip name
        std::getline(ss, item, ',');
        // skip age
        std::getline(ss, item, ',');
        // city
        std::getline(ss, item, ',');

        return item;
    }
};


class ConcreteAdapter3 : public IAdapter {
private:
    LegacySystemC* target;

public:
    ConcreteAdapter3() {
        target = new LegacySystemC();
    }

    std::string get_name() override {
        return target->retrieve().fullName;
    }

    std::string get_city() override {
        return target->retrieve().location;
    }
};


class ConcreteAdapter4 : public IAdapter {
private:
    ApiServiceD* target;

    std::string findValue(const std::string& key) {
        auto pairs = target->getPairs();
        for (const auto& p : pairs) {
            if (p.first == key) {
                return p.second;
            }
        }
        return "";
    }

public:
    ConcreteAdapter4() {
        target = new ApiServiceD();
    }

    std::string get_name() override {
        return findValue("username");
    }

    std::string get_city() override {
        return findValue("user_city");
    }
};