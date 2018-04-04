//
// Created by muhammed on 04/04/18.
//

#ifndef LEXICAL_ANALYZER_GENERATOR_SCANNER_H
#define LEXICAL_ANALYZER_GENERATOR_SCANNER_H

#include <bits/stdc++.h>
#include "../Machines/Machine.h"
#include "../Symbol_Table/Symbol_table.h"
#include "../Files_Handler/FileReader.h"
#include "../Minimizer/Minimizer.h"
#include "../Builders/Subset_Builder.h"
#include "../Rules_Parser/Rules.h"
#include "../Rules_Parser/FileRulesReader.h"
#include "../Rules_Parser/RulesParser.h"

using namespace std;

class Scanner {

public:

    Scanner();
    void terminal_output(string& rules_file , string& input_file);
    void file_output(string& rules_file , string& input_file, string& output_file);
    void normal_scan(string& rules_file, string& input_file);
    Symbol_table *get_symbol_table();

private:
    string run(string& rules_file , string& input_file);
    string scan_file(string& src_code,Machine* m);

    bool error_found(char c);

    Symbol_table* table;
    File_Reader fr ;

};


#endif //LEXICAL_ANALYZER_GENERATOR_SCANNER_H
