//
// Created by muhammed on 04/04/18.
//

#include "Scanner.h"


Scanner::Scanner(){

}


void Scanner::terminal_output(string& rules_file, string& input_file, string& grammer_file) {
    string output = run(rules_file,input_file,grammer_file);
    cout << output;
}

void Scanner::file_output(string& rules_file, string& input_file, string& output_file, string& grammer_file) {
    string output = run(rules_file,input_file,grammer_file);
    if(!fr.write_file(output,output_file)){
        perror("Error in Writing to the file\n");
    }
}

void Scanner::normal_scan(string &rules_file, string &input_file, string& grammer_file) {
    run(rules_file,input_file,grammer_file);
}

Symbol_table Scanner::get_symbol_table() {
    return table;
}

bool Scanner::error_found(char c) {
    return c != ' ' && c != '\n' && c != '\r' && c != '\t';
}

string Scanner::run(string& rules_file, string& input_file, string& grammer_file) {
    string output = "";

    // Lexical Start

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

    // Lexical end

    //Parser Start
    Parser_Controller parser_controller;

    Parsing_Table pt = parser_controller.generate_table(grammer_file);

    pt.print_table();

    //Parser End


    // try to read the src code.
    if(!fr.read_file(input_file)){
        perror("Source code file is not found.\n");
        return "";
    }
    // scanning input file
    cout << "Scanning.........\n";

    string src_code = fr.src_code();

    output = scan_file(src_code,m,pt);

    return output;
}

string Scanner::scan_file(string& src_code, Machine *m,Parsing_Table pt) {
    State* current = m->get_start();
    State* last_correct_state = current;
    int last_correct_index = 0;

    string output_lexical;
    string output_parser;

    string symbol;

    stack<string> parser_stack;
    parser_stack.push(EOF_parser);
    parser_stack.push(pt.get_start_Non_Terminal());
    vector<string> parser_result;

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
                // Token Found.
                string token = last_correct_state->get_token();
                output_lexical+= token;
                output_lexical+= '\n';
                i = last_correct_index;
                // add the pair of token and symbol
                table.add_token(last_correct_state->get_token(),symbol);
                symbol.clear();

                // Parser part
                match_token(token,pt,parser_stack,parser_result);

            }else{
                i = ++last_correct_index;
                // check if space or not
                if(error_found(src_code[i])) {
                    output_lexical = output_lexical + "LEXCIAL ERROR FOUND: This Character " + src_code[i] + " is not defined.\n";
                }
            }
            current = m->get_start();
            last_correct_state = current;
        }
    }
    return output_lexical;
}

void Scanner::add_vector_to_stack(vector<string> vec, stack<string> &s) {
    for(int i = 0 ; i < vec.size() ; i++){
        add_string_to_stack(vec[i],s);
    }
}

void Scanner::add_string_to_stack(string str, stack<string> &s) {
    s.push(str);
}

void Scanner::match_token(string &token, Parsing_Table &pt, stack<string> &st,vector<string> &res_vec) {
    string top = st.top();
    while(pt.is_non_terminal(top)){
        // pop the top
        st.pop();

        // print state
        print_parser_state(st,res_vec);

        vector<string> production;
        Type t = pt.get_production_type(top,token);

        if( t == valid_node){
            production = pt.get_production(top,token);
            add_vector_to_stack(production,st);
        }else if(t == invalid_node){
            // say error : non_terminal has no production for this token not even sync one
            string err = "Invalid non terminal ERROR: (illegal " + top + " )- discard " + token;
            res_vec.push_back(err);
            return;
        }else{
            string err = "Sync ERROR: non terminal: "+ top + " has sync production with " + token;
            res_vec.push_back(err);
        }

        top = st.top();
    }
    st.pop();
    // top now is terminal so we need to match it
    if(match_token(token,top)){
        res_vec.push_back(top);
    }else{
        // terminal != terminal
        // panic mode error recovery
        string err = "Invalid terminal ERROR: missing " + top;
        res_vec.push_back(err);
    }
}

bool Scanner::match_token(string orignal_token, string current_token) {
    return orignal_token == current_token;
}

void Scanner::print_parser_state(stack<string> st, vector<string> vec) {

    print_vector(vec);
    print_stack(st);
    cout << endl;
}

void Scanner::print_vector(vector<string> vec){
    for(int i = 0 ; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}

void Scanner::print_stack(stack<string> st) {
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}