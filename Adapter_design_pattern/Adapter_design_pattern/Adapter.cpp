#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Problem Description :
//You have an existing application that reads data from text files using the following interface:

// Existing FileReader interface
class FileReader {
public:
    virtual void readFile(const string& filename) = 0;
    virtual ~FileReader() = default;
};


//Now, you want to extend your application to read data from XML files.However, the XML file reader you have(XmlFileReader) has a different interface:

// XmlFileReader interface (incompatible with FileReader)
class XmlFileReader {
public:
    void readXmlFile(const string& filename) {
        // Implementation specific to reading XML files
        cout << "Reading data from XML file: " << filename << "\n";
    }
};

//To integrate the XmlFileReader into the existing application without modifying the FileReader interface, you can create an adapter class: 

// Adapter to make XmlFileReader compatible with FileReader
class XmlFileReaderAdapter : public FileReader {
private:
    XmlFileReader xmlFileReader;

public:
    void readFile(const string& filename) override {
        // Adapt the interface of XmlFileReader to match FileReader
        xmlFileReader.readXmlFile(filename);
    }
};

// Another way to make XmlFileReader compatible with FileReader 
class XmlFileReaderAdapter2 : public FileReader, private XmlFileReader {
public: 
    void readFile(const string& filename) override {
        readXmlFile(filename);
    }
};

//Now, you can use the XmlFileReaderAdapter to seamlessly integrate the XmlFileReader into your existing application :
int main() {
    // Existing application using the FileReader interface
    FileReader* fileReader = new XmlFileReaderAdapter();

    // Read data using the integrated XmlFileReader
    fileReader->readFile("data.xml");

    delete fileReader;

    return 0;
}

