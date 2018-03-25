cmake_minimum_required(VERSION 3.8)
project(Lexical_Analyzer_Generator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/Bonus/lex.yy.c
        src/Bonus/scanner.c
        src/Builders/Builder.cpp
        src/Builders/Builder.h
        src/Builders/Postfix_handler.cpp
        src/Builders/Postfix_handler.h
        src/Builders/Subset_Builder.cpp
        src/Builders/Subset_Builder.h
        src/Builders/Thomson_Builder.cpp
        src/Builders/Thomson_Builder.h
        src/Data_Structure/Token_Saver.cpp
        src/Data_Structure/Token_Saver.h
        src/Files_Handler/FileReader.cpp
        src/Files_Handler/FileReader.h
        src/General/Enums.h
        src/General/functions.cpp
        src/General/functions.h
        src/Graph/Edge.cpp
        src/Graph/Edge.h
        src/Graph/Graph.cpp
        src/Graph/Graph.h
        src/Graph/Node.cpp
        src/Graph/Node.h
        src/Machines/Machine.cpp
        src/Machines/Machine.h
        src/Machines/State.cpp
        src/Machines/State.h
        src/Machines/Transition_Table.cpp
        src/Machines/Transition_Table.h
        src/Minimizer/Group.cpp
        src/Minimizer/Group.h
        src/Minimizer/Groups.cpp
        src/Minimizer/Groups.h
        src/Minimizer/Minimizer.cpp
        src/Minimizer/Minimizer.h
        src/Rules_Parser/FileRulesReader.cpp
        src/Rules_Parser/FileRulesReader.h
        src/Rules_Parser/Rules.cpp
        src/Rules_Parser/Rules.h
        src/Rules_Parser/RulesParser.cpp
        src/Rules_Parser/RulesParser.h
        src/Lexical-Analyzer-Generator.cpp)

add_executable(Lexical_Analyzer_Generator ${SOURCE_FILES})