#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string read_file_contents(const string& filename);

int main(int argc, char *argv[]) {
    // Disable output buffering
    cout << unitbuf;
    cerr << unitbuf;

    // You can use print statements as follows for debugging, they'll be visible when running tests.
    cerr << "Logs from your program will appear here!" << endl;

    if (argc < 3) {
        cerr << "Usage: ./your_program tokenize <filename>" << endl;
        return 1;
    }

    const string command = argv[1];

    if (command == "tokenize") {
        string file_contents = read_file_contents(argv[2]);
        
        for (auto c: file_contents) {
            switch (c)
            {
            case '(':
                cout << "LEFT_PAREN ( null" << '\n'; 
                break;
            case ')':
                cout << "RIGHT_PAREN ) null" << '\n';
                break;
            case '{':
                cout << "LEFT_BRACE { null" << '\n';
                break;
            case '}':
                cout << "RIGHT_BRACE } null" << '\n';
                break;
            case ',':
                cout << "COMMA , null" << '\n';
                break;
            case '.':
                cout << "DOT . null" << '\n';
                break;
            case '-':
                cout << "MINUS - null" << '\n';
                break;
            case '+':
                cout << "PLUS + null" << '\n';
            case ';':
                cout << "SEMICOLON ; null" << '\n';
                break;
            case '*':
                cout << "STAR * null" << '\n';
                break;
            case '/':
                cout << "SLASH / null" << '\n';
                break;
            default:
                cout << "IDENTIFIER " << c << " null" << '\n';
                break;
            }
        }
        
        cout << "EOF  null" << endl; 
        
    } else {
        cerr << "Unknown command: " << command << endl;
        return 1;
    }

    return 0;
}

string read_file_contents(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error reading file: " << filename << endl;
        exit(1);
    }

    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}
