//---------------------------------------------------------------------------*
//                                                                           *
//                      File 'goil_template_grammar.h'                       *
//                        Generated by version 1.9.9                         *
//                     january 28th, 2010, at 15h58'31"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef GRAMMAR_goil_template_grammar_HAS_BEEN_DEFINED
#define GRAMMAR_goil_template_grammar_HAS_BEEN_DEFINED

//---------------------------------------------------------------------------*

#include "goil_template_parser.h"
#include "goil_template_expression_parser.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*

class goil_template_grammar : public goil_template_parser,
                                 public goil_template_expression_parser {
  public : virtual void nt_goil_template_start_symbol_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                GGS_goilTemplateVariableMap,
                                GGS_string &) ;
  public : static void _performSourceFileParsing_ (C_Compiler & inCompiler,
                                const C_String & inDependancyExtension,
                                const C_String & inDependancyPath,
                                GGS_string * inSentStringPtr,
                                const GGS_lstring inFileName,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                GGS_goilTemplateVariableMap,
                                GGS_string &
                                COMMA_LOCATION_ARGS) ;
  public : static void _performSourceStringParsing_ (C_Compiler & inCompiler,
                                GGS_string * inSentStringPtr,
                                const GGS_string inSourceString,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                GGS_goilTemplateVariableMap,
                                GGS_string &
                                COMMA_LOCATION_ARGS) ;
  public : virtual void nt_template_instruction_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                GGS_goilTemplateVariableMap &,
                                GGS_string &) ;
  public : virtual void nt_template_instruction_parse (goil_template_scanner &) ;
  public : virtual void nt_variable_or_here_ (goil_template_scanner &,
                                const GGS_goilTemplateVariableMap,
                                GGS_location &) ;
  public : virtual void nt_variable_or_here_parse (goil_template_scanner &) ;
  public : virtual void nt_expression_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                const GGS_goilTemplateVariableMap,
                                GGS_goilTemplateValue &,
                                GGS_goilTemplateType &) ;
  public : virtual void nt_expression_parse (goil_template_scanner &) ;
  public : virtual void nt_template_instruction_list_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                GGS_goilTemplateVariableMap &,
                                GGS_string &) ;
  public : virtual void nt_template_instruction_list_parseAndResetTemplateString (goil_template_scanner &) ;
  public : virtual void nt_template_instruction_list_parse (goil_template_scanner &) ;
  public : virtual void nt_relation_term_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                const GGS_goilTemplateVariableMap,
                                GGS_goilTemplateValue &,
                                GGS_goilTemplateType &) ;
  public : virtual void nt_relation_term_parse (goil_template_scanner &) ;
  public : virtual void nt_relation_factor_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                const GGS_goilTemplateVariableMap,
                                GGS_goilTemplateValue &,
                                GGS_goilTemplateType &) ;
  public : virtual void nt_relation_factor_parse (goil_template_scanner &) ;
  public : virtual void nt_simple_expression_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                const GGS_goilTemplateVariableMap,
                                GGS_goilTemplateValue &,
                                GGS_goilTemplateType &) ;
  public : virtual void nt_simple_expression_parse (goil_template_scanner &) ;
  public : virtual void nt_term_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                const GGS_goilTemplateVariableMap,
                                GGS_goilTemplateValue &,
                                GGS_goilTemplateType &) ;
  public : virtual void nt_term_parse (goil_template_scanner &) ;
  public : virtual void nt_factor_ (goil_template_scanner &,
                                const GGS_string,
                                const GGS_string,
                                const GGS_string,
                                const GGS_goilTemplateVariableMap,
                                GGS_goilTemplateValue &,
                                GGS_goilTemplateType &) ;
  public : virtual void nt_factor_parse (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_0 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_1 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_2 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_3 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_4 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_5 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_6 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_7 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_8 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_9 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_10 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_11 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_12 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_13 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_14 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_15 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_16 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_17 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_parser_18 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_0 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_1 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_2 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_3 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_4 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_5 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_6 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_7 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_8 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_9 (goil_template_scanner &) ;
  public : virtual PMSInt16 select_goil_template_expression_parser_10 (goil_template_scanner &) ;
} ;

//---------------------------------------------------------------------------*

#endif
