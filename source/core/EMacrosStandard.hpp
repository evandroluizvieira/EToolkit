#ifndef EMACROSSTANDARD_HPP
#define EMACROSSTANDARD_HPP

/*
 * @description: Integer value representing the current line in the source code file being compiled.
 */
#ifdef EGetCurrentFileLine
#undef EGetCurrentFileLine
#endif
#define EGetCurrentFileLine() __LINE__

/*
 * @description: A string literal containing the presumed name of the source file being compiled.
 */
#ifdef EGetCurrentFileName
#undef EGetCurrentFileName
#endif
#define EGetCurrentFileName() __FILE__

/*
 * @description: A string literal in the format "Mmm dd yyyy" containing the date in which the compilation process began.
 */
#ifdef EGetCompilationDate
#undef EGetCompilationDate
#endif
#define EGetCompilationDate() __DATE__

/*
 * @description: A string literal in the format "hh:mm:ss" containing the time at which the compilation process began.
 */
#ifdef EGetCompilationTime
#undef EGetCompilationTime
#endif
#define EGetCompilationTime() __TIME__

/*
 * @description: concatenate 'data1' and 'data2' in one code.
 */
#ifdef EConcatenate
#undef EConcatenate
#endif
#define EConcatenate(data1, data2) data1##data2

/*
 * @description: transform 'string' into a C string.
 */
#ifdef EMakeString
#undef EMakeString
#endif
#define EMakeString(string) #string

#endif /* EMACROSSTANDARD_HPP */
