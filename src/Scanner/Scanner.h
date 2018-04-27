//
// Created by muhammed on 04/04/18.
//

#ifndef LEXICAL_ANALYZER_GENERATOR_SCANNER_H
#define LEXICAL_ANALYZER_GENERATOR_SCANNER_H

#include <bits/stdc++.h>
#include "../Lexical/Machines/Machine.h"
#include "../Lexical/Symbol_Table/Symbol_table.h"
#include "../Lexical/Files_Handler/FileReader.h"
#include "../Lexical/Minimizer/Minimizer.h"
#include "../Lexical/Builders/Subset_Builder.h"
#include "../Lexical/Rules_Parser/Rules.h"
#include "../Lexical/Rules_Parser/FileRulesReader.h"
#include "../Lexical/Rules_Parser/RulesParser.h"
#include "../Parser/Parsing_Table/Parsing_Table.h"
#include "../Parser/Parser_Controller/Parser_Controller.h"


using namespace std;

class Scanner {

public:

    void terminal_output(string& rules_file , string& input_file, string& grammer_file);
    void file_output(string& rules_file , string& input_file, string& grammer_file, string& output_file);
    void normal_scan(string& rules_file, string& input_file,string& grammer_file);
    Symbol_table get_symbol_table();

private:
    string run(string& rules_file , string& input_file,string& grammer_file);
    string scan_file(string& src_code,Machine* m, Parsing_Table pt);

    void match_token(string &token, Parsing_Table &pt, stack<string> &st, vector<string> &res_vec);

    void print_parser_state(stack<string> st,vector<string> vec);

    void print_stack(stack<string> st);

    void print_vector(vector<string> vec);

    bool match_token(string given_token, string production_token);

    bool error_found(char c);

    void add_vector_to_stack(vector<string> vec, stack<string>& s);

    void add_string_to_stack(string str, stack<string>& s);

    string EOF_parser = "'$'";
    char single_quote = '\'';

    Symbol_table table;
    File_Reader fr ;

};


#endif //LEXICAL_ANALYZER_GENERATOR_SCANNER_H
