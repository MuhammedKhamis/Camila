cmake_minimum_required(VERSION 3.8)
project(Lexical_Analyzer_Generator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/Lexical/Bonus/lex.yy.c
        src/Lexical/Bonus/scanner.c
        src/Lexical/Builders/Builder.cpp
        src/Lexical/Builders/Builder.h
        src/Lexical/Builders/Postfix_handler.cpp
        src/Lexical/Builders/Postfix_handler.h
        src/Lexical/Builders/Subset_Builder.cpp
        src/Lexical/Builders/Subset_Builder.h
        src/Lexical/Builders/Thomson_Builder.cpp
        src/Lexical/Builders/Thomson_Builder.h
        src/Lexical/Data_Structure/Token_Saver.cpp
        src/Lexical/Data_Structure/Token_Saver.h
        src/Lexical/Files_Handler/FileReader.cpp
        src/Lexical/Files_Handler/FileReader.h
        src/Lexical/General/Enums.h
        src/Lexical/General/functions.cpp
        src/Lexical/General/functions.h
        src/Lexical/Graph/Edge.cpp
        src/Lexical/Graph/Edge.h
        src/Lexical/Graph/Graph.cpp
        src/Lexical/Graph/Graph.h
        src/Lexical/Graph/Node.cpp
        src/Lexical/Graph/Node.h
        src/Lexical/Machines/Machine.cpp
        src/Lexical/Machines/Machine.h
        src/Lexical/Machines/State.cpp
        src/Lexical/Machines/State.h
        src/Lexical/Machines/Transition_Table.cpp
        src/Lexical/Machines/Transition_Table.h
        src/Lexical/Minimizer/Group.cpp
        src/Lexical/Minimizer/Group.h
        src/Lexical/Minimizer/Groups.cpp
        src/Lexical/Minimizer/Groups.h
        src/Lexical/Minimizer/Minimizer.cpp
        src/Lexical/Minimizer/Minimizer.h
        src/Lexical/Rules_Parser/FileRulesReader.cpp
        src/Lexical/Rules_Parser/FileRulesReader.h
        src/Lexical/Rules_Parser/Rules.cpp
        src/Lexical/Rules_Parser/Rules.h
        src/Lexical/Rules_Parser/RulesParser.cpp
        src/Lexical/Rules_Parser/RulesParser.h
        src/main.cpp
        src/Lexical/Symbol_Table/Symbol_table.cpp
        src/Lexical/Symbol_Table/Symbol_table.h
        src/Lexical/Symbol_Table/Symbol_table_iterator.cpp
        src/Lexical/Symbol_Table/Symbol_table_iterator.h
        src/Lexical/Scanner/Scanner.cpp
        src/Lexical/Scanner/Scanner.h src/Parser/Grammar_parser/Input_Parser.cpp src/Parser/Grammar_parser/Input_Parser.h)

add_executable(Lexical_Analyzer_Generator ${SOURCE_FILES} src/Parser/Grammar_parser/Input_Parser.cpp src/Parser/Grammar_parser/Input_Parser.h)