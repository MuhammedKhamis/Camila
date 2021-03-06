cmake_minimum_required(VERSION 3.10)
project(Compiler-Project)

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
        src/Scanner/Scanner.cpp
        src/Scanner/Scanner.h
        src/Parser/Data_Structures/Production/Production.cpp 
        src/Parser/Data_Structures/Production/Production.h 
        src/Parser/Parsing_Table/Parsing_Table.cpp 
        src/Parser/Parsing_Table/Parsing_Table.h 
        src/Parser/Data_Structures/First/First.cpp 
        src/Parser/Data_Structures/First/First.h 
        src/Parser/Data_Structures/Follow/Follow.cpp 
        src/Parser/Data_Structures/Follow/Follow.h 
        src/Parser/Non_Terminal_Package/Non_Terminal_Info.cpp 
        src/Parser/Non_Terminal_Package/Non_Terminal_Info.h 
        src/Parser/Data_Structures/First_Production_Pair/First_Production_Pair.cpp 
        src/Parser/Data_Structures/First_Production_Pair/First_Production_Pair.h 
        src/Parser/Parsing_Table_Generator/Parsing_Table_Generator.cpp 
        src/Parser/Parsing_Table_Generator/Parsing_Table_Generator.h
        src/Parser/Grammar_parser/Input_parser.cpp
        src/Parser/Grammar_parser/Input_parser.h
        src/Parser/Grammar_parser/Input_reader.cpp
        src/Parser/Grammar_parser/Input_reader.h
        src/Parser/Parser_Controller/Parser_Controller.cpp
        src/Parser/Parser_Controller/Parser_Controller.h
        src/Parser/First_follow_finder/first_follow_generator.cpp
        src/Parser/First_follow_finder/first_follow_generator.h
        src/Parser/Data_Structures/Non_Terminal/non_terminal.cpp
        src/Parser/Data_Structures/Non_Terminal/non_terminal.h
        src/Parser/Data_Structures/Non_Terminal/part.cpp
        src/Parser/Data_Structures/Non_Terminal/part.h
        src/Parser/Data_Structures/Non_Terminal/line.cpp
        src/Parser/Data_Structures/Non_Terminal/line.h
        src/Parser/Data_Structures/Non_Terminal/element.cpp
        src/Parser/Data_Structures/Non_Terminal/element.h
        src/Parser/Data_Structures/Parser_Group/Parser_group.cpp
        src/Parser/Data_Structures/Parser_Group/Parser_group.h
        src/Parser/Data_Structures/Non_Terminal_Mapper/Non_Terminal_mapper.cpp
        src/Parser/Data_Structures/Non_Terminal_Mapper/Non_Terminal_mapper.h
        src/Parser/First_follow_finder/FF_Generator.cpp
        src/Parser/First_follow_finder/FF_Generator.h
        src/Parser/Data_Structures/First_Follow_Package/FF_Package.cpp
        src/Parser/Data_Structures/First_Follow_Package/FF_Package.h
        src/Parser/Grammar_parser/Grammar_rule.h
        src/Parser/Grammar_parser/Grammar_rule.cpp
        src/Parser/LL1\ -\ Conversion/LL1_handler.h
        src/Parser/LL1\ -\ Conversion/LL1_handler.cpp
        src/Parser/LL1\ -\ Conversion/prefix_handler.cpp
        src/Parser/LL1\ -\ Conversion/prefix_handler.h)

add_executable(Compiler-Project ${SOURCE_FILES})
