//---------------------------------------------------------------------------*
//                                                                           *
//  AC_OutputStream : an abstract output stream class                        *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1997, ..., 2009 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "streams/AC_OutputStream.h"
#include "strings/C_String.h"
#include "strings/unicode_character_cpp.h"
#include "strings/unicode_string_routines.h"

//---------------------------------------------------------------------------*

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//---------------------------------------------------------------------------*

AC_OutputStream::AC_OutputStream (void) :
mIndentation (0),
mStartingLine (true) {
}

//---------------------------------------------------------------------------*

AC_OutputStream::~AC_OutputStream (void) {
}

//---------------------------------------------------------------------------*

void AC_OutputStream::flush (void) {
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendCString (const char * inCstring) {
  if (inCstring != NULL) {
    genericCharArrayOutput (inCstring, (PMSInt32) (strlen (inCstring) & PMUINT32_MAX)) ;
  }
}

//---------------------------------------------------------------------------*

void AC_OutputStream::genericCharArrayOutput (const char * inCharArray, const PMSInt32 inArrayCount) {
  if (mIndentation == 0) {
    performActualCharArrayOutput (inCharArray, inArrayCount) ;
  }else if (inArrayCount > 0) {
    for (PMSInt32 i=0 ; i<inArrayCount ; i++) {
      if (mStartingLine) {
        for (PMSInt32 j=0 ; j<mIndentation ; j++) {
          performActualCharArrayOutput (" ", 1) ;
        }
      }
      performActualCharArrayOutput (& (inCharArray [i]) , 1) ;
      mStartingLine = inCharArray [i] == '\n' ;
    }
  }
}

//---------------------------------------------------------------------------*

void AC_OutputStream::genericUnicodeArrayOutput (const utf32 * inCharArray, const PMSInt32 inArrayCount) {
  if (mIndentation == 0) {
    performActualUnicodeArrayOutput (inCharArray, inArrayCount) ;
  }else if (inArrayCount > 0) {
    for (PMSInt32 i=0 ; i<inArrayCount ; i++) {
      if (mStartingLine) {
        for (PMSInt32 j=0 ; j<mIndentation ; j++) {
          const utf32 space [1] = {TO_UNICODE (' ')} ;
          performActualUnicodeArrayOutput (space, 1) ;
        }
      }
      performActualUnicodeArrayOutput (& (inCharArray [i]) , 1) ;
      mStartingLine = UNICODE_VALUE (inCharArray [i]) == '\n' ;
    }
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << C_String
#endif

//---------------------------------------------------------------------------*

void AC_OutputStream::appendString (const C_String inString) {
  genericUnicodeArrayOutput (inString.utf32String (HERE), inString.length ()) ;
}

//---------------------------------------------------------------------------*

AC_OutputStream & AC_OutputStream::operator << (const C_String inString) {
  genericUnicodeArrayOutput (inString.utf32String (HERE), inString.length ()) ;
  return *this ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << char *
#endif

//---------------------------------------------------------------------------*

AC_OutputStream & AC_OutputStream::operator << (const char * inCstring) {
  appendCString (inCstring) ;
  return *this ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendCString (const char * inCstring, const PMSInt32 inCount) {
  genericCharArrayOutput (inCstring, inCount) ;
}

//---------------------------------------------------------------------------*

AC_OutputStream & AC_OutputStream::operator << (const utf32 * inUTF32String) {
  genericUnicodeArrayOutput (inUTF32String, utf32_strlen (inUTF32String)) ;
  return * this ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUTF32String (const utf32 * inUTF32String) {
  genericUnicodeArrayOutput (inUTF32String, utf32_strlen (inUTF32String)) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUTF32LiteralStringConstant (const C_String & inString) {
  const utf32 * str = inString.utf32String (HERE) ;
  appendUnicodeCharacter (TO_UNICODE ('{') COMMA_HERE) ;
  while (UNICODE_VALUE (* str) != 0) {
    const utf32 c = * str ;
    appendCString ("\n  TO_UNICODE (") ;
    if (isprint ((int) UNICODE_VALUE (c))) {
      appendCLiteralCharConstant (c) ;
    }else{
      appendUnsigned (UNICODE_VALUE (c)) ;
    }
    appendCString ("),") ;
    str ++ ;
  }
  appendCString ("\n  TO_UNICODE (0)\n}") ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << char
#endif

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendUnicodeCharacter (const utf32 inUnicodeCharacter COMMA_UNUSED_LOCATION_ARGS) {
  genericUnicodeArrayOutput (& inUnicodeCharacter, 1) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << double
#endif

//---------------------------------------------------------------------------*

void AC_OutputStream::appendDouble (const double inValue) {
  char s [40] = "" ;
  snprintf (s, 39, "%g", inValue) ;
  genericCharArrayOutput (s, (PMSInt32) (strlen (s) & PMUINT32_MAX)) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << PMSInt32
#endif

//---------------------------------------------------------------------------*

void AC_OutputStream::appendSigned (const PMSInt32 inValue) {
  char s [20] = "" ;
  snprintf (s, 19, "%d", inValue) ;
  genericCharArrayOutput (s, (PMSInt32) (strlen (s) & PMUINT32_MAX)) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark PMUInt64
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//  WARNING: in gcc 3.x printf for 64-bit integer crashes!                   *
//  So we use an auxiliary function printfUINT64 and only 32-bit printing    *
//                                                                           *
//---------------------------------------------------------------------------*

static void
printfUINT64 (char ioString [],
              const PMUInt64 inValue,
              PMSInt32 & ioLength) {
  const PMUInt64 quotient = inValue / 10ULL ;
  if (quotient != 0) {
    printfUINT64 (ioString, quotient, ioLength) ;
  }
  const PMUInt32 v = (PMUInt32) ((inValue % 10ULL) & PMUINT32_MAX) ;
  ioString [ioLength] = (char) (('0' + v) & 255) ;
  ioLength ++ ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUnsigned64 (const PMUInt64 inValue) {
  char s [30] = "" ;
  PMSInt32 length = 0 ;
  printfUINT64 (s, inValue, length) ;
  s [length] = '\0' ;
  MF_Assert (length < 30, "C string overflow", 0, 0) ;
  genericCharArrayOutput (s, length) ;
}

//---------------------------------------------------------------------------*

static void
printfUINT64Hex (char ioString [],
                 const PMUInt64 inValue,
                 int & ioLength) {
  const PMUInt64 quotient = inValue >> 4 ;
  if (quotient != 0) {
    printfUINT64Hex (ioString, quotient, ioLength) ;
  }
  const PMUInt32 v = (PMUInt32) (inValue & 15ULL) ;
  sprintf (& ioString [ioLength], "%X", v) ;
  ioLength ++ ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUnsigned64inHex (const PMUInt64 inValue) {
  int length = 0 ;
  char s [32] ;
  printfUINT64Hex (s, (PMUInt64) inValue, length) ;
  MF_Assert (length < 32, "C string overflow", 0, 0) ;
  genericCharArrayOutput (s, length) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << PMSInt64
#endif

//---------------------------------------------------------------------------*

void AC_OutputStream::appendSigned64 (const PMSInt64 inValue) {
  PMSInt32 length = 0 ;
  char s [30] = "" ;
  if (inValue >= 0) {
    printfUINT64 (s, (PMUInt64) inValue, length) ;
  }else if (inValue == PMSINT64_MIN) {
    s [0] = '-' ;
    length = 1 ;
    printfUINT64 (s, (PMUInt64) PMSINT64_MIN, length) ;
  }else{
    s [0] = '-' ;
    length = 1 ;
    printfUINT64 (s, (PMUInt64) (- inValue), length) ;
  }
  s [length] = '\0' ;
  MF_Assert (length < 30, "C string overflow", 0, 0) ;
  genericCharArrayOutput (s, length) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Bool
#endif

//---------------------------------------------------------------------------*

void AC_OutputStream::appendBool (const bool inValue) {
  appendCString (inValue ? "true" : "false") ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << PMUInt32
#endif

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendUnsignedWithZeroFill (const PMUInt32 inValue, const PMUInt32 inWidth) {
  char s [32] = "" ;
  snprintf (s, 31, "%0*u", inWidth, inValue) ;
  appendCString (s) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUnsigned (const PMUInt32 inValue) {
  char s [20] = "" ;
  snprintf (s, 19, "%u", inValue) ;
  genericCharArrayOutput (s, (PMSInt32) (strlen (s) & PMUINT32_MAX)) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUnsignedHex (const PMUInt32 inValue) {
  char s [20] = "" ;
  snprintf (s, 19, "%X", inValue) ;
  genericCharArrayOutput (s, (PMSInt32) (strlen (s) & PMUINT32_MAX)) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUnsignedHex2 (const PMUInt32 inValue) {
  char s [20] = "" ;
  snprintf (s, 19, "%02X", inValue & 0xFF) ;
  genericCharArrayOutput (s, (PMSInt32) (strlen (s) & PMUINT32_MAX)) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUnsignedHex4 (const PMUInt32 inValue) {
  char s [20] = "" ;
  snprintf (s, 19, "%04X", inValue & 0xFFFF) ;
  genericCharArrayOutput (s, (PMSInt32) (strlen (s) & PMUINT32_MAX)) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::appendUnsignedHex8 (const PMUInt32 inValue) {
  char s [20] = "" ;
  snprintf (s, 19, "%08X", inValue) ;
  genericCharArrayOutput (s, (PMSInt32) (strlen (s) & PMUINT32_MAX)) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark << void *
#endif

//---------------------------------------------------------------------------*

void AC_OutputStream::appendPointer (const void * inValue) {
  char s [30] = "" ;
  snprintf (s, 29, "%p", inValue) ;
  genericCharArrayOutput (s, (PMSInt32) (strlen (s) & PMUINT32_MAX)) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendSpaces (const PMSInt32 inSpaceCount) {
  for (PMSInt32 i=0 ; i<inSpaceCount ; i++) {
    appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
  }
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
writeStringMultiple (const C_String & inString, const PMSInt32 inRepeatCount) {
  for (PMSInt32 i=0 ; i<inRepeatCount ; i++) {
    *this << inString ;
  }
}

//---------------------------------------------------------------------------*
//                          Comments                                         *
//---------------------------------------------------------------------------*

static const PMSInt32 kCommentMaxLength = 77 ;

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendHyphenLineCommentWithoutExtraBlankLine (const C_String & inLineCommentPrefix) {
  *this << inLineCommentPrefix ;
  for (PMSInt32 i=0 ; i<(kCommentMaxLength-2) ; i++) {
    *this << "-" ;
  }
  *this << "*\n";
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendTitleComment (const C_String & inLineCommentPrefix,
                    const C_String & inCommentString) {
  appendHyphenLineCommentWithoutExtraBlankLine (inLineCommentPrefix) ;
  appendSpaceLineComment (inLineCommentPrefix) ;
  appendCenterJustifiedComment (inLineCommentPrefix, inCommentString) ;
  appendSpaceLineComment (inLineCommentPrefix) ;
  appendCppHyphenLineComment (inLineCommentPrefix) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendComment (const C_String & inLineCommentPrefix,
               const C_String & inCommentString) {
  *this << inLineCommentPrefix << " " << inCommentString << "\n" ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCenterJustifiedComment (const C_String & inLineCommentPrefix,
                              const C_String & inCommentString) {
  const PMSInt32 commentLength = inCommentString.length () ;
  const PMSInt32 n = (kCommentMaxLength - 3 - commentLength) / 2 ;
  
  *this << inLineCommentPrefix ;
  for (PMSInt32 i=0 ; i<n ; i++) {
   *this << " " ;
  }
  *this << inCommentString ;
  const PMSInt32 fin = kCommentMaxLength - n - commentLength - 2 ;
  for (PMSInt32 j=0 ; j<fin ; j++) {
    *this << " " ;
  }
  *this << "*\n" ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendSpaceLineComment (const C_String & inLineCommentPrefix) {
  *this << inLineCommentPrefix ;
  for (PMSInt32 i=0 ; i<(kCommentMaxLength-2) ; i++) {
    *this << " " ;
  }
  *this << "*\n";
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCppHyphenLineComment (const C_String & inLineCommentPrefix) {
  appendHyphenLineCommentWithoutExtraBlankLine (inLineCommentPrefix) ;
  *this << "\n" ;
}

//---------------------------------------------------------------------------*
//                          C Comments                                       *
//---------------------------------------------------------------------------*

void AC_OutputStream::append_C_HyphenLineComment (void) {
  *this << "/*" ;
  for (PMSInt32 i=0 ; i<(kCommentMaxLength-4) ; i++) {
    *this << "-" ;
  }
  *this << "*/\n" ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::append_C_SpaceLineComment (void) {
  *this << "/*" ;
  for (PMSInt32 i=0 ; i<(kCommentMaxLength-4) ; i++) {
    *this << " " ;
  }
  *this << "*/\n" ;
}

//---------------------------------------------------------------------------*
//                        C++ Comments                                       *
//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCppHyphenLineCommentWithoutExtraBlankLine (void) {
  appendHyphenLineCommentWithoutExtraBlankLine ("//") ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCppTitleComment (const C_String & inCommentString) {
  appendTitleComment ("//", inCommentString) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCppTitleComment (const char * inCommentString) {
  appendTitleComment ("//", inCommentString) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCppComment (const C_String & inCommentString) {
  appendComment ("//", inCommentString) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCppCenterJustifiedComment (const C_String & inCommentString) {
  appendCenterJustifiedComment ("//", inCommentString) ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCppSpaceLineComment (void) {
  appendSpaceLineComment ("//") ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCppHyphenLineComment (void) {
  appendCppHyphenLineComment ("//") ;
}

//---------------------------------------------------------------------------*

static void
internalWriteCstringConstant (AC_OutputStream & ioStream,
                              const C_String & inString,
                              const PMSInt32 inStringLength,
                              const PMSInt32 inLineMaxLength) {
  ioStream << "\"" ;
  PMSInt32 currentColumn = 0 ;
  for (PMSInt32 i=0 ; i<inStringLength ; i++) {
    if (currentColumn > inLineMaxLength) {
      ioStream << "\"\n  \"" ;
      currentColumn = 0 ;
    }
    currentColumn ++ ;
    const utf32 c = inString (i COMMA_HERE) ;
    switch (UNICODE_VALUE (c)) {
    case '\0' :
      break ;
    case '\a' :
      ioStream << "\\a" ;
      break ;
    case '\b' :
      ioStream << "\\b" ;
      break ;
    case '\f' :
      ioStream << "\\f" ;
      break ;
    case '\n' :
      ioStream << "\\n" ;
      if (i < (inStringLength - 1)) {
        ioStream << "\"\n  \"" ;
        currentColumn = 1 ;
      }
      break ;
    case '\r' :
      ioStream << "\\r" ;
      break ;
    case '\t' :
      ioStream << "\\t" ;
      break ;
    case '\v' :
      ioStream << "\\v" ;
      break ;
    case '\\' :
      ioStream << "\\\\" ;
      break ;
    case '\"' :
      ioStream << "\\\"" ;
      break ;
    case '\?' :
      ioStream << "\\?" ;
      break ;
    default :
      if ((UNICODE_VALUE (c) >= ' ') && (UNICODE_VALUE (c) < 127)) {
        ioStream.appendUnicodeCharacter (c COMMA_HERE) ;
      }else{
        char buffer [5] ;
        const PMSInt32 n = UTF8StringFromUTF32Character (c, buffer) ;
        for (PMSInt32 j=0 ; j<n ; j++) {
          ioStream << "\\x" ;
          ioStream.appendUnsignedHex2 ((PMUInt32) buffer [j]) ;
          ioStream << "\"\""  ;
        }
      }
    }
  }
  ioStream << "\"" ;
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCLiteralStringConstant (const C_String & inString) {
  internalWriteCstringConstant (*this, inString, inString.length (), 150) ;
}


//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCLiteralStringConstant (const C_String & inString,
                              const PMSInt32 inLineMaxLength) {
  internalWriteCstringConstant (*this, inString, inString.length (), inLineMaxLength) ;
}


//---------------------------------------------------------------------------*

void AC_OutputStream::
appendCLiteralCharConstant (const utf32 c) {
  switch (UNICODE_VALUE (c)) {
  case '\0' :
    *this << ("'\\0'") ;
    break ;
  case '\a' :
    *this << ("'\\a'") ;
    break ;
  case '\b' :
    *this << ("'\\b'") ;
    break ;
  case '\f' :
    *this << ("'\\f'") ;
    break ;
  case '\n' :
    *this << ("'\\n'") ;
    break ;
  case '\r' :
    *this << ("'\\r'") ;
    break ;
  case '\t' :
    *this << ("'\\t'") ;
    break ;
  case '\v' :
    *this << ("'\\v'") ;
    break ;
  case '\\' :
    *this << ("'\\\\'") ;
    break ;
  case '\'' :
    *this << ("'\\''") ;
    break ;
  case '\"' :
    *this << ("'\\\"'") ;
    break ;
  case '\?' :
    *this << ("'\\\?'") ;
    break ;
  default :
    if ((UNICODE_VALUE (c) >= ' ') && (UNICODE_VALUE (c) <= '~')) {
      appendCString ("'") ;
      appendUnicodeCharacter (c COMMA_HERE) ;
      appendCString ("'") ;
    }else{
      appendUnsigned (UNICODE_VALUE (c)) ;
    }
    break ;
  }
}

//---------------------------------------------------------------------------*

void AC_OutputStream::
appendFileHeaderComment (const C_String & inLineCommentPrefix,
                         const C_String & inTitle,
                         const C_String & in_generatedBy_subtitle,
                         const bool inIncludeLGPLtext) {
  if (inLineCommentPrefix.length () > 0) {
    appendCppHyphenLineCommentWithoutExtraBlankLine () ;
    appendCppSpaceLineComment () ;
    appendCppCenterJustifiedComment (inTitle) ;
    C_String subTitle ;
    if (in_generatedBy_subtitle.length () != 0) {
      subTitle << "Generated by " << in_generatedBy_subtitle ;
      appendCppCenterJustifiedComment (subTitle) ;
      subTitle.setLengthToZero () ;
    }
    C_DateTime today ;
    subTitle << today ;
    appendCppCenterJustifiedComment (subTitle) ;
    if (inIncludeLGPLtext) {
      appendCppSpaceLineComment () ;
      *this << inLineCommentPrefix << " This file is free software; you can redistribute it and/or modify it      *\n"
            << inLineCommentPrefix << " under the terms of the GNU Lesser General Public License as published     *\n"
            << inLineCommentPrefix << " by the Free Software Foundation; either version 2 of the License, or      *\n"
            << inLineCommentPrefix << " (at your option) any later version.                                       *\n"
            << inLineCommentPrefix << "                                                                           *\n"
            << inLineCommentPrefix << " This file is distributed in the hope it will be useful, but WITHOUT       *\n"
            << inLineCommentPrefix << " ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or     *\n"
            << inLineCommentPrefix << " FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public       *\n"
            << inLineCommentPrefix << " License for more details.                                                 *\n"
            << inLineCommentPrefix << "                                                                           *\n"
            << inLineCommentPrefix << " You should have received a copy of the GNU General Public License along   *\n"
            << inLineCommentPrefix << " with this program; if not, write to the Free Software Foundation          *\n"
            << inLineCommentPrefix << " Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA            *\n" ;
    }
    appendCppSpaceLineComment () ;
    appendCppHyphenLineComment () ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithUnsigned
#endif

//---------------------------------------------------------------------------*

C_String cStringWithUnsigned (const PMUInt64 inValue) {
  C_String result ;
  result.appendUnsigned64 (inValue) ;
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithSigned
#endif

//---------------------------------------------------------------------------*

C_String cStringWithSigned (const PMSInt64 inValue) {
  C_String result ;
  result.appendSigned64 (inValue) ;
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithCharacter
#endif

//---------------------------------------------------------------------------*

C_String cStringWithCharacter (const char inValue) {
  C_String result ;
  result.appendUnicodeCharacter (TO_UNICODE ((PMUInt32) inValue) COMMA_HERE) ;
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithUnicodeCharacter
#endif

//---------------------------------------------------------------------------*

C_String cStringWithUnicodeCharacter (const utf32 inValue) {
  C_String result ;
  result.appendUnicodeCharacter (inValue COMMA_HERE) ;
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithPointer
#endif

//---------------------------------------------------------------------------*

C_String cStringWithPointer (const void * inValue) {
  C_String result ;
  result.appendPointer (inValue) ;
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cStringWithDouble
#endif

//---------------------------------------------------------------------------*

C_String cStringWithDouble (const double inValue) {
  C_String result ;
  result.appendDouble (inValue) ;
  return result ;
}

//---------------------------------------------------------------------------*