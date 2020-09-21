#ifndef ESTANDARDMACROS_HPP
#define ESTANDARDMACROS_HPP

/*
 * @description: Integer value representing the current line in the source code file being compiled.
 */
#ifdef EToolkitGetCurrentFileLine
#undef EToolkitGetCurrentFileLine
#endif
#define EToolkitGetCurrentFileLine() __LINE__

/*
 * @description: A string literal containing the presumed name of the source file being compiled.
 */
#ifdef EToolkitGetCurrentFileName
#undef EToolkitGetCurrentFileName
#endif
#define EToolkitGetCurrentFileName() __FILE__

/*
 * @description: A string literal in the format "Mmm dd yyyy" containing the date in which the compilation process began.
 */
#ifdef EToolkitGetCompilationDate
#undef EToolkitGetCompilationDate
#endif
#define EToolkitGetCompilationDate() __DATE__

/*
 * @description: A string literal in the format "hh:mm:ss" containing the time at which the compilation process began.
 */
#ifdef EToolkitGetCompilationTime
#undef EToolkitGetCompilationTime
#endif
#define EToolkitGetCompilationTime() __TIME__

/*
 * @description: concatenate 'data1' and 'data2' in one code.
 */
#ifdef EToolkitConcatenate
#undef EToolkitConcatenate
#endif
#define EToolkitConcatenate(data1, data2) data1##data2

/*
 * @description: transform 'string' into a C string.
 */
#ifdef EToolkitMakeString
#undef EToolkitMakeString
#endif
#define EToolkitMakeString(string) #string

#endif /* ESTANDARDMACROS_HPP_ */
