#include <iostream>
#include <memory>
class Format { //Product
public:
    virtual void print() const = 0;
    virtual ~Format() = default;
};
class Archiver { //Creator
public:
    //FactoryMethod()
    virtual std::unique_ptr<Format> createArchive() const = 0;
    //AnOperation()
    void newArchive() const {
        auto doc = createArchive();
        doc->print();
    }
    virtual ~Archiver() = default;
};
class Format7z : public Format { //ConcreteProduct 1
public:
    void print() const override {
        std::cout << ".7z format archive" << std::endl;
    }
};
class FormatRar : public Format { //ConcreteProduct 2
public:
    void print() const override {
        std::cout << ".rar format archive" << std::endl;
    }
};
class Archiver7z : public Archiver { //ConcreteCreator 1
public:
    std::unique_ptr<Format> createArchive() const override {
        return std::make_unique<Format7z>();
    }
};
class ArchiverWinrar : public Archiver { //ConcreteCreator 2
public:
    std::unique_ptr<Format> createArchive() const override {
        return std::make_unique<FormatRar>();
    }
};
int main() {
    std::unique_ptr<Archiver> sevenZip = std::make_unique<Archiver7z>();
    sevenZip->newArchive(); // .7z format archive

    std::unique_ptr<Archiver> winRar = std::make_unique<ArchiverWinrar>();
    winRar->newArchive(); // .rar format archive

    return 0;
}