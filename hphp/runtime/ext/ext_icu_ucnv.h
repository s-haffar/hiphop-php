/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_EXT_ICU_UCNV_H_
#define incl_HPHP_EXT_ICU_UCNV_H_

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include "hphp/runtime/base/base_includes.h"
#include "hphp/runtime/base/zend/zend_collator.h"

// Avoid dragging in the icu namespace.
#ifndef U_USING_ICU_NAMESPACE
#define U_USING_ICU_NAMESPACE 0
#endif

#include "unicode/utypes.h"
#include "unicode/ucnv.h"
#include "unicode/ustring.h"
namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

extern const int64_t q_UConverter$$REASON_UNASSIGNED;
extern const int64_t q_UConverter$$REASON_ILLEGAL;
extern const int64_t q_UConverter$$REASON_IRREGULAR;
extern const int64_t q_UConverter$$REASON_RESET;
extern const int64_t q_UConverter$$REASON_CLOSE;
extern const int64_t q_UConverter$$REASON_CLONE;
extern const int64_t q_UConverter$$UNSUPPORTED_CONVERTER;
extern const int64_t q_UConverter$$SBCS;
extern const int64_t q_UConverter$$DBCS;
extern const int64_t q_UConverter$$MBCS;
extern const int64_t q_UConverter$$LATIN_1;
extern const int64_t q_UConverter$$UTF8;
extern const int64_t q_UConverter$$UTF16_BigEndian;
extern const int64_t q_UConverter$$UTF16_LittleEndian;
extern const int64_t q_UConverter$$UTF32_BigEndian;
extern const int64_t q_UConverter$$UTF32_LittleEndian;
extern const int64_t q_UConverter$$EBCDIC_STATEFUL;
extern const int64_t q_UConverter$$ISO_2022;
extern const int64_t q_UConverter$$LMBCS_1;
extern const int64_t q_UConverter$$LMBCS_2;
extern const int64_t q_UConverter$$LMBCS_3;
extern const int64_t q_UConverter$$LMBCS_4;
extern const int64_t q_UConverter$$LMBCS_5;
extern const int64_t q_UConverter$$LMBCS_6;
extern const int64_t q_UConverter$$LMBCS_8;
extern const int64_t q_UConverter$$LMBCS_11;
extern const int64_t q_UConverter$$LMBCS_16;
extern const int64_t q_UConverter$$LMBCS_17;
extern const int64_t q_UConverter$$LMBCS_18;
extern const int64_t q_UConverter$$LMBCS_19;
extern const int64_t q_UConverter$$LMBCS_LAST;
extern const int64_t q_UConverter$$HZ;
extern const int64_t q_UConverter$$SCSU;
extern const int64_t q_UConverter$$ISCII;
extern const int64_t q_UConverter$$US_ASCII;
extern const int64_t q_UConverter$$UTF7;
extern const int64_t q_UConverter$$BOCU1;
extern const int64_t q_UConverter$$UTF16;
extern const int64_t q_UConverter$$UTF32;
extern const int64_t q_UConverter$$CESU8;
extern const int64_t q_UConverter$$IMAP_MAILBOX;

///////////////////////////////////////////////////////////////////////////////
// class UConverter

FORWARD_DECLARE_CLASS_BUILTIN(UConverter);
class c_UConverter : public ExtObjectData {
 public:
  DECLARE_CLASS(UConverter, UConverter, ObjectData)

  // need to implement
  public: c_UConverter(Class* cls = c_UConverter::s_cls);
  public: ~c_UConverter();
  public: void t___construct(CStrRef toEncoding = "utf-8",
                             CStrRef fromEncoding = "utf-8");
  public: Variant t___destruct();
  public: String t_getsourceencoding();
  public: void t_setsourceencoding(CStrRef encoding);
  public: String t_getdestinationencoding();
  public: void t_setdestinationencoding(CStrRef encoding);
  public: int64_t t_getsourcetype();
  public: int64_t t_getdestinationtype();
  public: String t_getsubstchars();
  public: bool t_setsubstchars(CStrRef chars);
  public: Variant t_fromucallback(int64_t reason, CArrRef source,
                                  int64_t codepoint, VRefParam error);
  public: Variant t_toucallback(int64_t reason, CStrRef source,
                                CStrRef codeunits, VRefParam error);
  public: Variant t_convert(CStrRef str, bool reverse = false);
  public: static Variant ti_transcode(CStrRef str,
                                      CStrRef toEncoding, CStrRef fromEncoding,
                                      CArrRef options = null_variant);
  public: int64_t t_geterrorcode();
  public: String t_geterrormessage();
  public: static String ti_reasontext(int64_t reason);
  public: static Array ti_getavailable();
  public: static Array ti_getaliases(CStrRef encoding);
  public: static Array ti_getstandards();
  public: static String ti_getstandardname(CStrRef name,
                                           CStrRef standard);
  public: static String ti_getmimename(CStrRef name);

  private:
    static void throwFailure(UErrorCode error, const char *fname,
                             intl_error &merror);
    bool checkLimits(int64_t available, int64_t needed);
    void appendToUTarget(Variant val, UConverterToUnicodeArgs *args);
    void appendFromUTarget(Variant val, UConverterFromUnicodeArgs *args);
    static void ucnvToUCallback(c_UConverter *objval,
                                UConverterToUnicodeArgs *args,
                                const char *codeUnits, int32_t length,
                                UConverterCallbackReason reason,
                                UErrorCode *pErrorCode);
    static void ucnvFromUCallback(c_UConverter *objval,
                                  UConverterFromUnicodeArgs *args,
                                  const UChar *codeUnits, int32_t length,
                                  UChar32 codePoint,
                                  UConverterCallbackReason reason,
                                  UErrorCode *pErrorCode);
    static bool setEncoding(CStrRef encoding, UConverter **pcnv,
                            intl_error &err);
    static bool setSubstChars(String chars, UConverter *cnv, intl_error &err);
    bool setCallback(UConverter *cnv);
    Variant defaultCallback(int64_t reason, VRefParam error);
    static String doConvert(CStrRef str, UConverter *toCnv,
                            UConverter *fromCnv, intl_error &err);
  public:
    intl_error  m_error;
    UConverter *m_src;
    UConverter *m_dest;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_ICU_UCNV_H_
