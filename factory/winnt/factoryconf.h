/* emacs edit mode for this file is -*- C -*- */
/* $Id: factoryconf.h,v 1.1 1997-11-27 21:34:35 stobbe Exp $ */

#ifndef INCL_CONFIG_H
#define INCL_CONFIG_H

/* {{{ docu
 *
 * config.h.in - used by `configure' to create `config.h'.
 *
 * This file is included at building time from almost all source
 * files belonging to Factory.  Furthermore, it is (textually)
 * included into `factoryconf.h' by `makeheader' so we have an
 * installed version of this file, too.  This way, the installed
 * source files will be compiled with the same settings as the
 * library itself.
 *
 * In general, you should let `configure' guess the correct
 * values for the `#define's below.  But if something seriously
 * goes wrong in configuring, please inform the authors and feel
 * free to edit the marked section.
 *
 * ---RS---
 * This is the specialized version of config.h for compiling
 * Factory on Windows NT 4.0 with MS Visula C++ 5.x
 * ---RS---
 */
/* }}} */

/************** START OF CONFIGURABLE SECTION **************/

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* factory version */
#define FACTORYVERSION "1.3b"

/* factory configuration */
#define FACTORYCONFIGURATION "WINNT"

/* where the gftables live */
#define GFTABLEDIR "."

/* define if your compiler does arithmetic shift */
#define HAS_ARITHMETIC_SHIFT 1

/* define to build factory without stream IO */
#undef NOSTREAMIO

/* define if linked to Singular */
#undef SINGULAR

/* define if linked with factory memory manager */
#define USE_MEMUTIL 1

/* define if linked with old factory memory manager */
#define USE_OLD_MEMMAN 1

/* define if linked with new factory manager, debugging version */
#undef MDEBUG

/* define if you do not want to activate assertions */
#undef NOASSERT

/* define if you want to activate the timing stuff */
#undef TIMING

/* define if you want to have debugging output */
#undef DEBUGOUTPUT

/************** END OF CONFIGURABLE SECTION **************/

#endif /* ! INCL_CONFIG_H */
/* emacs edit mode for this file is -*- C -*- */
/* $Id: factoryconf.h,v 1.1 1997-11-27 21:34:35 stobbe Exp $ */

/* This is for compatibility with standard assert.h */
#if defined (NDEBUG) && ! defined (NOASSERT)
#define NOASSERT
#endif

/* It should be possible to include this file multiple times for different */
/* settings of NOASSERT */

/* {{{ undefines */
#undef __ASSERT
#undef __ASSERT1
#undef STICKYASSERT
#undef STICKYASSERT1
#undef ASSERT
#undef ASSERT1

#undef __WARN
#undef STICKYWARN
#undef WARN

#undef PVIRT_VOID
#undef PVIRT_INTCF
#undef PVIRT_BOOL
#undef PVIRT_INT
#undef PVIRT_CHARCC
/* }}} */

#include <stdio.h>
#include <stdlib.h>

/* {{{ permanent macro definitions */
#ifndef __GNUC__
#define __ASSERT(expression, message, file, line) \
(fprintf( stderr, "error: " message "\n%s:%u: failed assertion `%s'\n", \
 file, line, expression ), abort(), 0 )
#define __ASSERT1(expression, message, parameter1, file, line)  \
(fprintf( stderr, "error: " message "\n%s:%u: failed assertion `%s'\n", \
 parameter1, file, line, expression ), abort(), 0 )

#define STICKYASSERT(expression, message) \
((void)((expression) ? 0 : __ASSERT(#expression, message, __FILE__, __LINE__)))
#define STICKYASSERT1(expression, message, parameter1) \
((void)((expression) ? 0 : __ASSERT1(#expression, message, parameter1, __FILE__, __LINE__)))

#define __WARN(expression, message, file, line)  \
(fprintf( stderr, "warning: " message "\n%s:%u: failed assertion `%s'\n", \
 file, line, expression ), 0 )
#define STICKYWARN(expression, message) \
((void)((expression) ? 0 : __WARN(#expression, message, __FILE__, __LINE__)))
#else /* __GNUCC__ */
/* use preprocessor macro __PRETTY_FUNCTION__ for more informative output */
#define __ASSERT(expression, message, file, line, function) \
(fprintf( stderr, "error: " message "\n%s:%u: In function `%s':\nfailed assertion `%s'\n", \
 file, line, function, expression ), abort(), 0 )
#define __ASSERT1(expression, message, parameter1, file, line, function)  \
(fprintf( stderr, "error: " message "\n%s:%u: In function `%s':\nfailed assertion `%s'\n", \
 parameter1, file, line, function, expression ), abort(), 0 )

#define STICKYASSERT(expression, message) \
((void)((expression) ? 0 : __ASSERT(#expression, message, __FILE__, __LINE__, __PRETTY_FUNCTION__)))
#define STICKYASSERT1(expression, message, parameter1) \
((void)((expression) ? 0 : __ASSERT1(#expression, message, parameter1, __FILE__, __LINE__, __PRETTY_FUNCTION__)))

#define __WARN(expression, message, file, line, function)  \
(fprintf( stderr, "warning: " message "\n%s:%u: In function `%s':\nfailed assertion `%s'\n", \
 file, line, function, expression ), 0 )
#define STICKYWARN(expression, message) \
((void)((expression) ? 0 : __WARN(#expression, message, __FILE__, __LINE__, __PRETTY_FUNCTION__)))
#endif /* __GNUCC__ */
/* }}} */

/* {{{ macro definitions dependent on NOASSERT */
#ifndef NOASSERT
#ifndef __GNUC__
#define ASSERT(expression, message) \
((void)((expression) ? 0 : __ASSERT(#expression, message, __FILE__, __LINE__)))
#define ASSERT1(expression, message, parameter1) \
((void)((expression) ? 0 : __ASSERT1(#expression, message, parameter1, __FILE__, __LINE__)))

#define WARN(expression, message) \
((void)((expression) ? 0 : __WARN(#expression, message, __FILE__, __LINE__)))
#else /* __GNUCC__ */
/* use preprocessor macro __PRETTY_FUNCTION__ for more informative output */
#define ASSERT(expression, message) \
((void)((expression) ? 0 : __ASSERT(#expression, message, __FILE__, __LINE__, __PRETTY_FUNCTION__)))
#define ASSERT1(expression, message, parameter1) \
((void)((expression) ? 0 : __ASSERT1(#expression, message, parameter1, __FILE__, __LINE__, __PRETTY_FUNCTION__)))

#define WARN(expression, message) \
((void)((expression) ? 0 : __WARN(#expression, message, __FILE__, __LINE__, __PRETTY_FUNCTION__)))
#endif /* __GNUCC__ */

#define PVIRT_VOID(msg) \
{ fprintf( stderr, "pure method( " msg " ) called\n" ); abort(); }
#define PVIRT_INTCF(msg) \
{ fprintf( stderr, "pure method( " msg " ) called\n" ); abort(); return 0; }
#define PVIRT_BOOL(msg) \
{ fprintf( stderr, "pure method( " msg " ) called\n" ); abort(); return false; }
#define PVIRT_INT(msg) \
{ fprintf( stderr, "pure method( " msg " ) called\n" ); abort(); return 0; }
#define PVIRT_CHARCC(msg) \
{ fprintf( stderr, "pure method( " msg " ) called\n" ); abort(); return 0; }
#else /* NOASSERT */
#define ASSERT(expression, message)
#define ASSERT1(expression, message, parameter1)

#define WARN(expression, message)

#define PVIRT_VOID(msg) = 0
#define PVIRT_INTCF(msg) = 0
#define PVIRT_BOOL(msg) = 0
#define PVIRT_INT(msg) = 0
#define PVIRT_CHARCC(msg) = 0
#endif /* NOASSERT */
/* }}} */
