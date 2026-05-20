#include <string>
#include <iostream>
#include <vector>

//------------------------------------------
// Component Class/Interface
//------------------------------------------

class FileSystemItem {
protected:
    std::string name;
    int size;
    FileSystemItem* parent_dir;

public:
    FileSystemItem(std::string name, FileSystemItem* p, int init_size)
        : name(name), size(init_size), parent_dir(p) {}

    virtual ~FileSystemItem() = default;

    virtual int get_size() = 0;

    virtual std::string get_name() {
        return name;
    }

    virtual void ls() = 0;
    virtual void expand(int indent) = 0;
};

//------------------------------------------
// Composite Class - Directories
//------------------------------------------

class FileSystemDirectory : public FileSystemItem {
protected:
    std::vector<FileSystemItem*> contents;

public:
    FileSystemDirectory(std::string name, FileSystemItem* parent)
        : FileSystemItem(name, parent, 5) {}

    void add_item_to_dir(FileSystemItem* item) {
        contents.push_back(item);
    }

    int get_size() override {
        int res = this->size;
        for (auto& content : contents) {
            res += content->get_size();
        }
        return res;
    }

    void ls() override {
        std::cout << "[Directory] " << name << std::endl;
        for (auto& content : contents) {
            std::cout << "  - " << content->get_name() << std::endl;
        }
    }

    void expand(int indent) override {
        std::string ind(indent, '\t');

        std::cout << ind << "[Directory] " << name << " (" << size << " bytes)" << std::endl;

        for (auto& content : contents) {
            content->expand(indent + 1);
        }
    }
};

//------------------------------------------
// Leaf Class - Files
//------------------------------------------

class FileSystemFile : public FileSystemItem {
public:
    FileSystemFile(std::string name, FileSystemItem* parent)
        : FileSystemItem(name, parent, 1) {}

    int get_size() override {
        return size;
    }

    void ls() override {
        std::cout << "[File] " << name << std::endl;
    }

    void expand(int indent) override {
        std::string ind(indent, '\t');
        std::cout << ind << "[File] " << name << " (" << size << " bytes)" << std::endl;
    }
};

//------------------------------------------
// Client Code
//------------------------------------------

int main() {
    FileSystemDirectory* root = new FileSystemDirectory("root", nullptr);

    FileSystemDirectory* home = new FileSystemDirectory("home", root);
    FileSystemDirectory* user = new FileSystemDirectory("user", home);

    FileSystemFile* file1 = new FileSystemFile("file1.txt", user, 10);
    FileSystemFile* file2 = new FileSystemFile("file2.txt", user, 20);

    FileSystemFile* syslog = new FileSystemFile("syslog", root, 50);

    // Build tree
    user->add_item_to_dir(file1);
    user->add_item_to_dir(file2);

    home->add_item_to_dir(user);
    root->add_item_to_dir(home);
    root->add_item_to_dir(syslog);

    // Usage
    std::cout << "===== LS VIEW =====\n";
    root->ls();

    std::cout << "\n===== TREE VIEW =====\n";
    root->expand(0);

    std::cout << "\n===== TOTAL SIZE =====\n";
    std::cout << root->get_size() << std::endl;

    return 0;
}