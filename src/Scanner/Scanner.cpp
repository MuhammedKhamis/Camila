//
// Created by muhammed on 04/04/18.
//

#include "Scanner.h"


Scanner::Scanner(){
    table = new Symbol_table;
}


void Scanner::terminal_output(string& rules_file, string& input_file) {
    string output = run(rules_file,input_file);
    cout << output;
}

void Scanner::file_output(string& rules_file, string& input_file, string& output_file) {
    string output = run(rules_file,input_file);
    if(!fr.write_file(output,output_file)){
        perror("Error in Writing to the file\n");
    }
}

void Scanner::normal_scan(string &rules_file, string &input_file) {
    run(rules_file,input_file);
}

Symbol_table* Scanner::get_symbol_table() {
    return table;
}


bool Scanner::error_found(char c) {
    return c != ' ' && c != '\n' && c != '\r' && c != '\t';
}

string Scanner::run(string& rules_file, string& input_file) {
    string output = "";

    // reading Rules
    RulesParser rp;
    FileRulesReader frr;
    string path(rules_file);
    vector<string> lines = frr.read(path);

    if(lines.empty()){
        return output;
    }

    // NFA creation
    Rules r = rp.parse_lines(lines);
    Node* start = r.parse_nfa();


    // DFA creation.
    Subset_Builder *sb = new Subset_Builder();
    Transition_Table* table = sb->convert_to_DFA(start);

    // minimized DFA
    Minimizer * minimizer = new Minimizer(table);

    Transition_Table* minimized_table = minimizer->get_minimized();

    Machine* m = new Machine(minimized_table);


    //minimized_table->print_table();


    // try to read the src code.
    if(!fr.read_file(input_file)){
        perror("Source code file is not found.\n");
        return "";
    }
    // scanning input file
    cout << "Scanning.........\n";

    string src_code = fr.src_code();

    output = scan_file(src_code,m);

    return output;
}

string Scanner::scan_file(string& src_code, Machine *m) {
    State* current = m->get_start();
    State* last_correct_state = current;
    int last_correct_index = 0;

    string output;

    string symbol;

    for(int i = 0 ; i < src_code.size();i++){
        bool res = m->next(current,char_to_string(src_code[i]));
        if(res){
            current = m->get_current();
            // correct transition
            if(current->get_priority() == valid){
                last_correct_state = current;
                last_correct_index = i;
            }
            symbol+= src_code[i];
        }else{
            // bad transition
            if(last_correct_state->get_priority() == valid){
                output+= last_correct_state->get_token();
                output+= '\n';
                i = last_correct_index;
                // add the pair of token and symbol
                table->add_token(last_correct_state->get_token(),symbol);
                symbol.clear();
            }else{
                i = ++last_correct_index;
                // check if space or not
                if(error_found(src_code[i])) {
                    output = output + "ERROR FOUND: This Character " + src_code[i] + " is not defined.\n";
                }
            }
            current = m->get_start();
            last_correct_state = current;
        }
    }
    return output;
}