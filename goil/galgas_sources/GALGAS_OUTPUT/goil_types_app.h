//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_types_app.h'                           *
//                        Generated by version 1.9.9                         *
//                     january 28th, 2010, at 15h58'47"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_types_app_DEFINED
#define goil_types_app_DEFINED

#include <string.h>

//---------------------------------------------------------------------------*

#include "galgas/GGS__header.h"

//---------------------------------------------------------------------------*

// Include imported semantics
#include "goil_basic_types.h"

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          Class Predeclarations                            *
//                                                                           *
//---------------------------------------------------------------------------*

class GGS_app_trusted_obj ;
class cPtr_app_trusted_obj ;
class GGS_app_trusted_void ;
class cPtr_app_trusted_void ;
class GGS_app_trusted_false ;
class cPtr_app_trusted_false ;
class GGS_app_trusted_true ;
class cPtr_app_trusted_true ;
class GGS_app_obj ;
class cPtr_app_obj ;
class GGS_app_map ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    GALGAS class 'GGS_app_trusted_obj'                     *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptorEX kTypeDescriptor_GGS_app_trusted_obj ;

//---------------------------------------------------------------------------*

class GGS_app_trusted_obj : public AC_galgas_class {
//--- Default constructor
  public : inline GGS_app_trusted_obj (void) :
  AC_galgas_class () {}

//--- Pointer assignment constructor
  public : GGS_app_trusted_obj (const cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_app_trusted_obj (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_app_trusted_obj
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_app_trusted_obj * getPtr (void) const {
    return (cPtr_app_trusted_obj *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_location  reader_location (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_app_trusted_obj * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_app_trusted_obj * operator () (LOCATION_ARGS) const {
      return (cPtr_app_trusted_obj *) mPointer ;
    }
  #endif

//--- Galgas RTTI
AC_galgasClassRunTimeInformationEX * galgasObjectRunTimeInfo (void) const ;

//--- Introspection
  public : virtual const C_galgas_type_descriptorEX * typeDescriptor (void) const ;

  public : GGS_object reader_object (void) const ;

  public : static GGS_app_trusted_obj castFromObject (C_Compiler & inLexique,
                                           const GGS_object & inObject,
                                           const GGS_location & inErrorLocation
                                           COMMA_LOCATION_ARGS) ;

} ;

//---------------------------------------------------------------------------*

extern C_galgasRootClassRunTimeInformationEX gClassInfoFor__app_trusted_obj ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   GALGAS class 'GGS_app_trusted_void'                     *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptorEX kTypeDescriptor_GGS_app_trusted_void ;

//---------------------------------------------------------------------------*

class GGS_app_trusted_void : public GGS_app_trusted_obj {
//--- Default constructor
  public : inline GGS_app_trusted_void (void) :
  GGS_app_trusted_obj () {}

//--- Pointer assignment constructor
  public : GGS_app_trusted_void (const cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_app_trusted_void (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_app_trusted_void
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_app_trusted_void constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_app_trusted_void * getPtr (void) const {
    return (cPtr_app_trusted_void *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_app_trusted_void * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_app_trusted_void * operator () (LOCATION_ARGS) const {
      return (cPtr_app_trusted_void *) mPointer ;
    }
  #endif

//--- Introspection
  public : virtual const C_galgas_type_descriptorEX * typeDescriptor (void) const ;

  public : GGS_object reader_object (void) const ;

  public : static GGS_app_trusted_void castFromObject (C_Compiler & inLexique,
                                           const GGS_object & inObject,
                                           const GGS_location & inErrorLocation
                                           COMMA_LOCATION_ARGS) ;

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformationEX gClassInfoFor__app_trusted_void ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   GALGAS class 'GGS_app_trusted_false'                    *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptorEX kTypeDescriptor_GGS_app_trusted_false ;

//---------------------------------------------------------------------------*

class GGS_app_trusted_false : public GGS_app_trusted_obj {
//--- Default constructor
  public : inline GGS_app_trusted_false (void) :
  GGS_app_trusted_obj () {}

//--- Pointer assignment constructor
  public : GGS_app_trusted_false (const cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_app_trusted_false (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_app_trusted_false
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_app_trusted_false constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_app_trusted_false * getPtr (void) const {
    return (cPtr_app_trusted_false *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_app_trusted_false * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_app_trusted_false * operator () (LOCATION_ARGS) const {
      return (cPtr_app_trusted_false *) mPointer ;
    }
  #endif

//--- Introspection
  public : virtual const C_galgas_type_descriptorEX * typeDescriptor (void) const ;

  public : GGS_object reader_object (void) const ;

  public : static GGS_app_trusted_false castFromObject (C_Compiler & inLexique,
                                           const GGS_object & inObject,
                                           const GGS_location & inErrorLocation
                                           COMMA_LOCATION_ARGS) ;

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformationEX gClassInfoFor__app_trusted_false ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   GALGAS class 'GGS_app_trusted_true'                     *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptorEX kTypeDescriptor_GGS_app_trusted_true ;

//---------------------------------------------------------------------------*

class GGS_app_trusted_true : public GGS_app_trusted_obj {
//--- Default constructor
  public : inline GGS_app_trusted_true (void) :
  GGS_app_trusted_obj () {}

//--- Pointer assignment constructor
  public : GGS_app_trusted_true (const cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_app_trusted_true (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_app_trusted_true
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_app_trusted_true constructor_new (C_Compiler & inLexique,
                                const GGS_location & argument_0,
                                const GGS_stringset & argument_1
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_app_trusted_true * getPtr (void) const {
    return (cPtr_app_trusted_true *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_stringset  reader_trusted_fcts (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_app_trusted_true * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_app_trusted_true * operator () (LOCATION_ARGS) const {
      return (cPtr_app_trusted_true *) mPointer ;
    }
  #endif

//--- Introspection
  public : virtual const C_galgas_type_descriptorEX * typeDescriptor (void) const ;

  public : GGS_object reader_object (void) const ;

  public : static GGS_app_trusted_true castFromObject (C_Compiler & inLexique,
                                           const GGS_object & inObject,
                                           const GGS_location & inErrorLocation
                                           COMMA_LOCATION_ARGS) ;

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformationEX gClassInfoFor__app_trusted_true ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        GALGAS class 'GGS_app_obj'                         *
//                                                                           *
//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptorEX kTypeDescriptor_GGS_app_obj ;

//---------------------------------------------------------------------------*

class GGS_app_obj : public GGS_oil_obj {
//--- Default constructor
  public : inline GGS_app_obj (void) :
  GGS_oil_obj () {}

//--- Pointer assignment constructor
  public : GGS_app_obj (const cPtr__AC_galgas_class * inPointer) ;

//--- Object assignment constructor
  public : GGS_app_obj (cPtr__AC_galgas_class & inObject) ;

//--- castFrom class method (implements cast expression)
  public : static GGS_app_obj
  castFrom (C_Compiler & inLexique,
             cPtr__AC_galgas_class * inPointer,
             const bool inUseKindOfClass,
             const GGS_location & inErrorLocation
             COMMA_LOCATION_ARGS) ;

//--- 'new' constructor
  public : static GGS_app_obj constructor_new (C_Compiler & inLexique,
                                const GGS_lstring & argument_0,
                                const GGS_app_trusted_obj & argument_1,
                                const GGS_basic_type & argument_2,
                                const GGS_basic_type & argument_3,
                                const GGS_basic_type & argument_4,
                                const GGS_basic_type & argument_5,
                                const GGS_ident_map & argument_6,
                                const GGS_ident_map & argument_7,
                                const GGS_ident_map & argument_8,
                                const GGS_ident_map & argument_9,
                                const GGS_ident_map & argument_10,
                                const GGS_ident_map & argument_11,
                                const GGS_ident_map & argument_12
                                COMMA_LOCATION_ARGS) ;

//--- getPtr
  public : inline cPtr_app_obj * getPtr (void) const {
    return (cPtr_app_obj *) mPointer ;
  }

//--- 'description' reader
  public : virtual const char * actualTypeName (void) const ;

//--- Readers
  public : GGS_app_trusted_obj  reader_trusted (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_startuphook (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_shutdownhook (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_errorhook (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_basic_type  reader_restart (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_ident_map  reader_tasks (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_ident_map  reader_isrs (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_ident_map  reader_alarms (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_ident_map  reader_scheduletables (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_ident_map  reader_counters (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_ident_map  reader_resources (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;
  public : GGS_ident_map  reader_messages (C_Compiler & inLexique COMMA_LOCATION_ARGS) const ;

//--- Modifiers

//--- operator ()
  #ifndef DO_NOT_GENERATE_CHECKINGS
    public : cPtr_app_obj * operator () (LOCATION_ARGS) const ;
  #else
    public : inline cPtr_app_obj * operator () (LOCATION_ARGS) const {
      return (cPtr_app_obj *) mPointer ;
    }
  #endif

//--- Introspection
  public : virtual const C_galgas_type_descriptorEX * typeDescriptor (void) const ;

  public : GGS_object reader_object (void) const ;

  public : static GGS_app_obj castFromObject (C_Compiler & inLexique,
                                           const GGS_object & inObject,
                                           const GGS_location & inErrorLocation
                                           COMMA_LOCATION_ARGS) ;

} ;

//---------------------------------------------------------------------------*

extern C_galgasClassRunTimeInformationEX gClassInfoFor__app_obj ;

//---------------------------------------------------------------------------*
//                                                                           *
//                              Map '@app_map'                               *
//                                                                           *
//---------------------------------------------------------------------------*

class elementOf_GGS_app_map ;

extern const C_galgas_type_descriptorEX kTypeDescriptor_GGS_app_map ;

//---------------------------------------------------------------------------*

class GGS_app_map : public AC_galgas_map {
//--- Element Class
  public : typedef elementOf_GGS_app_map cElement ;

//--- Get pointers
  public : inline cElement * firstObject (void) const { return (cElement *) internalFirstObject () ; }
  public : inline cElement * lastObject (void) const { return (cElement *) internalLastObject () ; }

//--- Comparison methods
  public : GGS_bool operator_isEqual (const GGS_app_map & inOperand) const ;
  public : GGS_bool operator_isNotEqual (const GGS_app_map & inOperand) const ;

//--- Introspection
  public : virtual const C_galgas_type_descriptorEX * typeDescriptor (void) const ;

  public : GGS_object reader_object (void) const ;

  public : static GGS_app_map castFromObject (C_Compiler & inLexique,
                                           const GGS_object & inObject,
                                           const GGS_location & inErrorLocation
                                           COMMA_LOCATION_ARGS) ;

//--- Create a new element
  protected : virtual AC_galgas_map_element *
  new_element (const GGS_lstring & inKey, void * inInfo) ;

//--- Assign information to an existing element
  protected : virtual void
  assignInfo (AC_galgas_map_element * inPtr, void * inInfo) ;

//--- Enter an index
  public : void enterIndex (const GGS_lstring & inKey,
                            AC_galgas_index_core & outIndex) ;

//--- Get object pointer (for method call)
  public : inline GGS_app_map * operator () (UNUSED_LOCATION_ARGS) { return this ; }
  public : inline const GGS_app_map * operator () (UNUSED_LOCATION_ARGS) const { return this ; }

//--- 'emptyMap' constructor
  public : static GGS_app_map constructor_emptyMap (C_Compiler & inLexique COMMA_LOCATION_ARGS) ;

//--- Method used for duplicate a map
  protected : virtual void internalInsertForDuplication (AC_galgas_map_element * inPtr) ;

//--- Modifiers "set'Value'ForKey"

  public : static const utf32 kRemoveMessage_del [] ;

//--- 'del' Remove Modifier
  public : void modifier_del (C_Compiler & inLexique,
                                const GGS_lstring & inKey,
                                GGS_app_obj & outParameter0 COMMA_LOCATION_ARGS) ;

  public : static const utf32 kInsertMessage_put [] ;

//--- 'put' Insert Modifier
  public : void modifier_put (C_Compiler & inLexique,
                                const GGS_lstring & inKey,
                                const GGS_app_obj &  inParameter0 COMMA_LOCATION_ARGS) ;

  public : static const utf32 kSearchMessage_get [] ;

//--- 'get' Search Method
  public : void method_get (C_Compiler & inLexique,
                                const GGS_lstring & inKey,
                                GGS_app_obj   & outParameter0 COMMA_LOCATION_ARGS) const ;
//--- Internal method for removing an element
  protected : void removeElement (C_Compiler & inLexique,
                                   const utf32 * inErrorMessage,
                                   const GGS_lstring & inKey,
                                   GGS_app_obj & outParameter0,
                                   GGS_luint * outIndex
                                   COMMA_LOCATION_ARGS) ;
//--- Internal method for inserting an element
  protected : void insertElement (C_Compiler & inLexique,
                                   const utf32 * inErrorMessage,
                                   const GGS_lstring & inKey,
                                   const GGS_app_obj & inParameter0,
                                   GGS_luint * outIndex
                                   COMMA_LOCATION_ARGS) ;
//--- Internal method for searching for an element
  protected : void searchElement (C_Compiler & inLexique,
                                   const utf32 * inErrorMessage,
                                   const GGS_lstring & inKey,
                                   GGS_app_obj & outParameter0,
                                   GGS_luint * outIndex
                                   COMMA_LOCATION_ARGS) const ;
  public : virtual GGS_string reader_description (const PMSInt32 inIndentation = 0) const ;
  public : static GGS_app_map constructor_mapWithMapToOverride (C_Compiler & inLexique,
                                            const GGS_app_map & inMapToOverride
                                            COMMA_LOCATION_ARGS) ;
  public : GGS_app_map reader_overriddenMap (C_Compiler & inLexique
                                            COMMA_LOCATION_ARGS) const ;
//--------------------------------- Map Enumerator
  public : class cEnumerator : public cAbstractMapEnumerator {
  //--- Constructors
    public : inline cEnumerator (const GGS_app_map & inMap,
                                 const bool inAscending) :
    cAbstractMapEnumerator (inMap, inAscending) {
    }
    public : inline cEnumerator (const GGS_app_map & inMap) :
    cAbstractMapEnumerator (inMap) {
    }
  //--- Iterator method
    public : inline cElement * nextObject (void) {
      return (cElement *) internalNextObject () ;
    }
    public : /* const */ GGS_app_obj   & _app (LOCATION_ARGS) const ;
  } ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  abstract class 'cPtr_app_trusted_obj'                    *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_app_trusted_obj : public cPtr__AC_galgas_class {
//--- Constructor
  public : cPtr_app_trusted_obj (const GGS_location & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_app_trusted_obj (void) {}
  #endif

//--- Attributes
  public : GGS_location  location ;
//--- Class message
  public : virtual const char * instanceMessage (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_String & ioString,
                        const PMSInt32 inIndentation) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformationEX * galgasRTTI (void) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  abstract class 'cPtr_app_trusted_void'                   *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_app_trusted_void : public cPtr_app_trusted_obj {
  private : typedef cPtr_app_trusted_obj inherited ;
//--- Constructor
  public : cPtr_app_trusted_void (const GGS_location & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_app_trusted_void (void) {}
  #endif

//--- Attributes
//--- Class message
  public : virtual const char * instanceMessage (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_String & ioString,
                        const PMSInt32 inIndentation) const ;

//--- Comparison
  public : virtual bool
  isEqualToObject (const cPtr__AC_galgas_class * inOperand) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformationEX * galgasRTTI (void) const ;

//--- Make clone
  public : virtual cPtr__AC_galgas_class * makeClone (void) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 abstract class 'cPtr_app_trusted_false'                   *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_app_trusted_false : public cPtr_app_trusted_obj {
  private : typedef cPtr_app_trusted_obj inherited ;
//--- Constructor
  public : cPtr_app_trusted_false (const GGS_location & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_app_trusted_false (void) {}
  #endif

//--- Attributes
//--- Class message
  public : virtual const char * instanceMessage (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_String & ioString,
                        const PMSInt32 inIndentation) const ;

//--- Comparison
  public : virtual bool
  isEqualToObject (const cPtr__AC_galgas_class * inOperand) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformationEX * galgasRTTI (void) const ;

//--- Make clone
  public : virtual cPtr__AC_galgas_class * makeClone (void) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  abstract class 'cPtr_app_trusted_true'                   *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_app_trusted_true : public cPtr_app_trusted_obj {
  private : typedef cPtr_app_trusted_obj inherited ;
//--- Constructor
  public : cPtr_app_trusted_true (const GGS_location & ,
                                const GGS_stringset & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_app_trusted_true (void) {}
  #endif

//--- Attributes
  public : GGS_stringset  trusted_fcts ;
//--- Class message
  public : virtual const char * instanceMessage (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_String & ioString,
                        const PMSInt32 inIndentation) const ;

//--- Comparison
  public : virtual bool
  isEqualToObject (const cPtr__AC_galgas_class * inOperand) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformationEX * galgasRTTI (void) const ;

//--- Make clone
  public : virtual cPtr__AC_galgas_class * makeClone (void) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      abstract class 'cPtr_app_obj'                        *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_app_obj : public cPtr_oil_obj {
  private : typedef cPtr_oil_obj inherited ;
//--- Constructor
  public : cPtr_app_obj (const GGS_lstring & ,
                                const GGS_app_trusted_obj & ,
                                const GGS_basic_type & ,
                                const GGS_basic_type & ,
                                const GGS_basic_type & ,
                                const GGS_basic_type & ,
                                const GGS_ident_map & ,
                                const GGS_ident_map & ,
                                const GGS_ident_map & ,
                                const GGS_ident_map & ,
                                const GGS_ident_map & ,
                                const GGS_ident_map & ,
                                const GGS_ident_map & 
                                COMMA_LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_GGS_Object::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~cPtr_app_obj (void) {}
  #endif

//--- Attributes
  public : GGS_app_trusted_obj  trusted ;
  public : GGS_basic_type  startuphook ;
  public : GGS_basic_type  shutdownhook ;
  public : GGS_basic_type  errorhook ;
  public : GGS_basic_type  restart ;
  public : GGS_ident_map  tasks ;
  public : GGS_ident_map  isrs ;
  public : GGS_ident_map  alarms ;
  public : GGS_ident_map  scheduletables ;
  public : GGS_ident_map  counters ;
  public : GGS_ident_map  resources ;
  public : GGS_ident_map  messages ;
//--- Class message
  public : virtual const char * instanceMessage (void) const ;
  public : static const char * _static_message (void) ;

//--- Method for 'description' reader
  public : virtual void
  appendForDescription (C_String & ioString,
                        const PMSInt32 inIndentation) const ;

//--- Comparison
  public : virtual bool
  isEqualToObject (const cPtr__AC_galgas_class * inOperand) const ;

//--- Galgas RTTI
  public : virtual AC_galgasClassRunTimeInformationEX * galgasRTTI (void) const ;

//--- Make clone
  public : virtual cPtr__AC_galgas_class * makeClone (void) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Element of map '@app_map'                          *
//                                                                           *
//---------------------------------------------------------------------------*

class e_app_map {
  public : GGS_app_obj  app ;

  public : e_app_map (void) ;
} ;

//---------------------------------------------------------------------------*

class elementOf_GGS_app_map : public AC_galgas_map_element {
//--- Constructor
  public : elementOf_GGS_app_map (const GGS_lstring & inKey,
                                     const PMSInt32 inIndex,
                                     const e_app_map & inInfo) ;
//--- Get pointers
  public : inline elementOf_GGS_app_map * nextObject (void) const { return (elementOf_GGS_app_map *) mNextItem ; }
  public : inline elementOf_GGS_app_map * infObject (void) const { return (elementOf_GGS_app_map *) mInfPtr ; }
  public : inline elementOf_GGS_app_map * supObject (void) const { return (elementOf_GGS_app_map *) mSupPtr ; }
//--- Comparison
  protected : virtual bool isEqualToMapElement (const AC_galgas_map_element * inOperand) const ;
//--- Data member
  public : e_app_map mInfo ;
//--- Method for 'description' reader
  public : void appendForMapDescription (const PMSInt32 inElementIndex,
                                         C_String & ioString,
                                         const PMSInt32 inIndentation) const ;
} ;

//---------------------------------------------------------------------------*

#endif
