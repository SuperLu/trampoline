//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_program.cpp'                           *
//                        Generated by version 1.9.9                         *
//                     february 3rd, 2010, at 19h21'52"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#include "version_libpm.h"
#if LIBPM_VERSION != 647
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include "utilities/F_DisplayException.h"
#include "utilities/MF_MemoryControl.h"
#include "collections/TC_UniqueArray.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "command_line_interface/mainForLIBPM.h"
#include "utilities/MF_MemoryControl.h"
#include "command_line_interface/C_StringCommandLineOption.h"

#ifdef TARGET_API_MAC_CARBON
  #include <SIOUX.H>
#endif

#ifdef COMPILE_FOR_WIN32
  #ifdef __MWERKS__
    #include <WINSIOUX.H>
  #endif
#endif

#include <typeinfo>

//---------------------------------------------------------------------------*

#include "goil_grammar.h"
#include "goil_program.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_program.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O G R A M    P R O L O G U E                      *
//                                                                           *
//---------------------------------------------------------------------------*

static void
goil_program_prologue (C_Compiler & /* inLexique */,
                     const TC_UniqueArray <C_String> & /* inSourceFilesArray */) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     P R O G R A M    E P I L O G U E                      *
//                                                                           *
//---------------------------------------------------------------------------*

static void
goil_program_epilogue (C_Compiler & /* inLexique */,
                     const TC_UniqueArray <C_String> & /* inSourceFilesArray */) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//                      M A I N    F O R    L I B P M                        *
//                                                                           *
//---------------------------------------------------------------------------*

int mainForLIBPM  (const int argc, const char * argv []) {
  bool verboseOptionOn = true ;
  PMSInt16 returnCode = 0 ; // No error
//--- Fix parameters for BDD package
  C_BDD::setHashMapSize (19) ;
  C_BDD::setITEcacheSize (17) ;
  C_BDD::setANDcacheSize (1) ;
  C_BDD::forAllOnBitsGreaterCacheSize (18) ;
  C_PrologueEpilogue::runPrologueActions () ;
  {
  //--- Input/output parameters
    const char * extensions [] = {"oil", "OIL", NULL} ;
    const char * helpMessages [] = {"an '.oil' source file", "an '.OIL' source file", NULL} ;
    TC_UniqueArray <C_String> sourceFilesArray ;
  //--- Analyze Command Line Options
    F_Analyze_CLI_Options (argc, argv,
                                 #ifndef DO_NOT_GENERATE_CHECKINGS
        "version 2.0b43" " [debug]",
      #else
        "version 2.0b43",
      #endif
                           sourceFilesArray,
                           extensions,
                           helpMessages) ;
  //--- Build galgas io object
    C_galgas_io * galgasIOptr = NULL ;
    macroMyNew (galgasIOptr, C_galgas_io (HERE)) ;
  //--- Common lexique object
    C_Compiler * _commonLexique = NULL ;
    macroMyNew (_commonLexique, C_Compiler (NULL, "", "", galgasIOptr COMMA_HERE)) ;
  //--- Ask Save On Close ? (Carbon and Windows SIOUX Only)
    #ifdef SIOUX_IS_IMPLEMENTED
      SIOUXSettings.asktosaveonclose = gOption_generic_5F_cli_5F_options_options_asktosaveonclose.mValue ;
    #endif
  //--- Enable 64 bit alloc debug ? Only if compiled in 64 bit and in debug mode
    #ifndef DO_NOT_GENERATE_CHECKINGS
      #ifdef __LP64__
        if (gOption_generic_5F_cli_5F_options_enable_5F_allocation_5F_debugging.mValue) {
          enableAllocDebugFor64BitTool () ;
        }
      #endif
    #endif
    try{
      verboseOptionOn = gOption_galgas_5F_cli_5F_options_verbose_5F_output.mValue ;
      goil_program_prologue (* _commonLexique, sourceFilesArray) ;
      for (PMSInt32 i=0 ; i<sourceFilesArray.count () ; i++) {
        try {
          const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
          PMSInt16 r = 0 ;
          if (fileExtension.compare ("oil") == 0) {
            C_Compiler & inLexique = * _commonLexique ;
            const GGS_string _source (true, sourceFilesArray (i COMMA_HERE)) ;
            const GGS_location _here (inLexique) ;
            const GGS_lstring var_cas_inSourceFile (GGS_lstring::constructor_new (inLexique, _source, _here COMMA_HERE)) ;
            const GGS_string _depExtension = GGS_string ("") ;
            const GGS_string _depPath = GGS_string ("") ;
            if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
              goil_grammar::_performSourceFileParsing_ (inLexique,
                                            _depExtension.string (),
                                            _depPath.string (),
                                            NULL,
                                            var_cas_inSourceFile
                                            COMMA_SOURCE_FILE_AT_LINE (13)) ;
            }
            if (verboseOptionOn) {
              co << "Analysis of '" << sourceFilesArray (i COMMA_HERE).lastPathComponent () << "' completed. " ;
              switch (_commonLexique->totalErrorCount ()) {
              case 0 :
                co << "No error, " ;
                break ;
              case 1 :
                co << "1 error, " ;
                returnCode = 1 ; // Error code
                break ;
              default :
                co << cStringWithSigned (_commonLexique->totalErrorCount ()) << " errors, " ;
                returnCode = 1 ; // Error code
                break ;
              }
              switch (_commonLexique->totalWarningCount ()) {
              case 0 :
                co << "no warning" ;
                break ;
              case 1 :
                co << "1 warning" ;
                break ;
              default :
                co << cStringWithSigned (_commonLexique->totalWarningCount ()) << " warnings" ;
                break ;
              }
              if (verboseOptionOn || ((_commonLexique->totalErrorCount () + _commonLexique->totalWarningCount ()) > 0)) {
                co << ".\n" ;
              }
            }
          }else if (fileExtension.compare ("OIL") == 0) {
            C_Compiler & inLexique = * _commonLexique ;
            const GGS_string _source (true, sourceFilesArray (i COMMA_HERE)) ;
            const GGS_location _here (inLexique) ;
            const GGS_lstring var_cas_inSourceFile (GGS_lstring::constructor_new (inLexique, _source, _here COMMA_HERE)) ;
            const GGS_string _depExtension = GGS_string ("") ;
            const GGS_string _depPath = GGS_string ("") ;
            if (_depExtension.isBuilt () && _depPath.isBuilt ()) {
              goil_grammar::_performSourceFileParsing_ (inLexique,
                                            _depExtension.string (),
                                            _depPath.string (),
                                            NULL,
                                            var_cas_inSourceFile
                                            COMMA_SOURCE_FILE_AT_LINE (17)) ;
            }
            if (verboseOptionOn) {
              co << "Analysis of '" << sourceFilesArray (i COMMA_HERE).lastPathComponent () << "' completed. " ;
              switch (_commonLexique->totalErrorCount ()) {
              case 0 :
                co << "No error, " ;
                break ;
              case 1 :
                co << "1 error, " ;
                returnCode = 1 ; // Error code
                break ;
              default :
                co << cStringWithSigned (_commonLexique->totalErrorCount ()) << " errors, " ;
                returnCode = 1 ; // Error code
                break ;
              }
              switch (_commonLexique->totalWarningCount ()) {
              case 0 :
                co << "no warning" ;
                break ;
              case 1 :
                co << "1 warning" ;
                break ;
              default :
                co << cStringWithSigned (_commonLexique->totalWarningCount ()) << " warnings" ;
                break ;
              }
              if (verboseOptionOn || ((_commonLexique->totalErrorCount () + _commonLexique->totalWarningCount ()) > 0)) {
                co << ".\n" ;
              }
            }
          }else{
            printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
            r = 1 ;
          }
          if (r != 0) {
            returnCode = r ;
          }
        }catch (C_ScanOrParseOnlyException) { // Raised when scan only or parse only options are set
          // Do nothing: accept silently exception
        }
      }
    //--- Error or warnings ?
      if (_commonLexique->totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (_commonLexique->totalWarningCount () > 0) {
        if (gOption_galgas_5F_cli_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      goil_program_epilogue (* _commonLexique, sourceFilesArray) ;
    }catch (const M_STD_NAMESPACE exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      throw ;
    }
    macroDetachPointer (galgasIOptr, C_galgas_io) ;
    macroDetachPointer (_commonLexique, C_Compiler) ;
  }
  C_PrologueEpilogue::runEpilogueActions () ;
  runAllReleaseRoutines () ;
  C_StringCommandLineOption::releaseStrings () ;
  C_String::freeUnusedRegisteredStrings () ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    C_GGS_Object::checkAllObjectsHaveBeenReleased () ;
  #endif
  if (verboseOptionOn) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      const PMUInt64 maxUsedMemorySize = getMaxUsedMemorySize () ;
      const PMUInt64 oneMegaByte = 1 << 20 ;
      const PMUInt64 megaBytes = maxUsedMemorySize / oneMegaByte ;
      const PMUInt64 fraction = ((maxUsedMemorySize % oneMegaByte) * 1000) / oneMegaByte ;
      co << cStringWithSigned (getCreatedDynamicObjectsTotalCount ())
         << " C++ objects have been created (" ;
      co.appendUnsigned64 (megaBytes) ;
      co << "." ;
      co.appendUnsignedWithZeroFill ((PMUInt32) fraction, 3) ;
      co << " MB).\n" ;
      deactivateMemoryControl () ;
      if ((getAllocationBalance () != 0) && (returnCode == 0)) {
        display_pointers () ;
      }
    #endif
  }
  return returnCode ;
}

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


