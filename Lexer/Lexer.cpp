#include <iostream>
#include "Lexer.h"

/*
 * Function for default lexer
 */
Comm
Lexer::Lexer() {
    row = CodeRow();
}

/*
 * Function file Lexer
 */
Comm
Lexer::Lexer(std::string fileName)
{
    row = CodeRow();
    if (!setFile(fileName)) {
        throw std::logic_error("File doesn't exist");
    }
}
/*
 * Function set file to lexer
 */
bool Lexer::setFile(std::string fileName)
{
    file = new std::ifstream(fileName);
    return file->good();
}

bool Lexer::fileSet() {
    return (file != nullptr);
}
/*
 * Destructor for Lexer
 */
Comm
Lexer::~Lexer()
{
    if (file != nullptr) {
        delete file;
    }
}

//
// Usage methods
//

// Returns next row, returns NULL if reached EOF
CodeRow& Lexer::nextRow()
{
    // Check if a file has been set
    if (!fileSet()) {
        throw std::logic_error("No file to read from");
    }

    // Put next line into row
    // Puts empty row in case of empty line
    *file >> row;
    return row;
}

// Lex one line (command line style)
CodeRow& Lexer::lexLine(std::string line)
{
    // Convert line to stringstream
    std::stringstream lineStream(line);
    // Process line into CodeRow
    row.readRow(lineStream);
    // Return row
    return row;
}

// Returns a split of the arguments entered
std::vector<std::string> Lexer::getArgs() {
    return row.getArgs();
}