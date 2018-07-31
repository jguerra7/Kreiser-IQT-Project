/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// PERFORMANCE LAB I.5.A-4 ////////////////////////////////////////////////
/////////////////////////////////////////////// FUNCTION ARGUMENTS //////////////////////////////////////////////////
///////////////////////////////////////////////// "Surfin' Bird" ////////////////////////////////////////////////////
/////////////////////////////////////////////// Instructor Solution /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The students must define find_the_word() as specified below.
// Do *NOT* change main() as it contains 56 tests created for find_the_word()
// char * find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr)
// Return Value
//     char pointer to the first occurrence of searchWord in the null-terminated string found at sentence_ptr
//     NULL for all other situations (e.g., sentence_ptr is NULL, searchWord_ptr is NULL, errorCode_ptr is NULL)
// Parameters
//     sentence_ptr - char pointer to a null-terminated string which represents the sentence to search
//     searchWord_ptr - char pointer to a null-terminated string which represents the key to search for
//     errorCode_ptr - int pointer which will store an error code provided by find_the_word (see below)
// Purpose - Safely (e.g., watch for array overruns, mind the null-terminators) locate the memory address
//     of the string found at searchWord_ptr within sentence_ptr
// Requirements
//     Only Address Arithmetic is permitted to access sentence_ptr and searchWord_ptr.  The test input utilizes
//         methods other than address arithmetic but that is none of your concern.
//     Assign your error code to the memory address found in errorCode_ptr.  The error codes are #defined as constant
//         MACROS at the beginning of main() but are also listed here:
//         DEFAULT_ERROR_CODE - This is a default value used in testing.  The error code variable is initialized
//             with this value.  The error code variable is also reset to this value after each test.  The
//             students will not need to return this code.  It is entirely restricted to testing and debugging.
//         ERROR_CODE_SUCCESS - This is not an actual error.  Rather, it indicates your function has successfully
//             completed.  Use this MACRO to indicate success.
//         ERROR_NULL_SENTENCE_POINTER - This MACRO is to be used when sentence_ptr is NULL.  The return value of 
//             the function will of course be NULL but the function also needs to store this MACRO in the memory 
//             address stored in errorCode_ptr.
//         ERROR_NULL_SEARCH_POINTER - This MACRO is to be used when searchWord_ptr is NULL.  The return value 
//             of the function will of course be NULL but the function also needs to store this MACRO in the memory 
//             address stored in errorCode_ptr.
//         ERROR_SEARCH_NOT_FOUND - This MACRO is to be used when the string located at searchWord_ptr has not
//             been found inside the string located at sentence_ptr.  The return value of the function will of
//             course be NULL but the function also needs to store this MACRO in the memory address stored in
//             errorCode_ptr.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Error code default value */
#ifdef DEFAULT_ERROR_CODE
#undef DEFAULT_ERROR_CODE
#endif
#define DEFAULT_ERROR_CODE 90318

/* Just in case NULL was undefined... */
#ifndef NULL
#define NULL ((void*) 0)
#endif

/* Error code for success */
#ifdef ERROR_CODE_SUCCESS
#undef ERROR_CODE_SUCCESS
#endif
#define ERROR_CODE_SUCCESS ((int)1)

/* Error code if sentence_ptr is NULL */
#ifdef ERROR_NULL_SENTENCE_POINTER
#undef ERROR_NULL_SENTENCE_POINTER
#endif
#define ERROR_NULL_SENTENCE_POINTER ((int)-1)

/* Error code if searchWord_ptr is NULL */
#ifdef ERROR_NULL_SEARCH_POINTER
#undef ERROR_NULL_SEARCH_POINTER
#endif
#define ERROR_NULL_SEARCH_POINTER ((int)-2)

/* Error code is the string in searchWord_ptr can not be found in the string located at sentence_ptr */
#ifdef ERROR_SEARCH_NOT_FOUND
#undef ERROR_SEARCH_NOT_FOUND
#endif
#define ERROR_SEARCH_NOT_FOUND ((int)-3)

/* Standard array size for manual dimension declaration */
#ifdef BUFF_SIZE
#undef BUFF_SIZE
#endif
#define BUFF_SIZE 1024

/*
* FUNCTION:   find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr)
*
* ARGUMENTS:  sentence_ptr is a char pointer to a null-terminated string to search
*             searchWord_ptr is a char pointer to a null-terminated string to find inside sentence_ptr
*             errorCode_ptr is an int pointer.  Store your error code at this memory address.
*
* RETURNS:	   char pointer to the first occurrence of the searchWord_ptr string found in the
*                 sentence_ptr string.  The char pointer should be a memory address in the
*                 sentence_ptr string and this memory address should represent the first 'index'
*                 of the searchWord_ptr string.  This memory address from the sentence_ptr string
*                 should dereference to a value equivalent to searchWord_ptr[0].
*             All other occurences should return NULL.  This includes, but is not limited to, the
*                 following:
*                     sentence_ptr is NULL
*                     searchWord_ptr is NULL
*                     errorCode_ptr is NULL
*                     the searchWord_ptr string is not found in the sentence_ptr string
*
* NOTES:      This function only utilizes address arithmetic to access information within the
*                 null-terminated char array found at both sentence_ptr and searchWord_ptr
*             Only access elements of the char array found at both sentence_ptr and searchWord_ptr
*                 using address arithmetic (AKA pointer math).  The definition of this function should
*                 be entirely devoid of the [ and ] characters.  (e.g., sentence_ptr[i] is forbidden)
*             The only guarantees for the arguments are:
*                 Any string found at sentence_ptr is null-terminated
*                 Any string found at searchWord_ptr is null-terminated
*             There is no guarantee sentence_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee searchWord_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee errorCode_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee the string found at sentence_ptr contains the string found at
*                 searchWord_ptr (return NULL if the string at searchWord_ptr is not found and assign the
*                 proper error code)
*             There is no guarantee the strings found at both sentence_ptr and searchWord_ptr will
*                 return a string length longer than zero (0)
*/

char * find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr);

typedef struct
{
	char * inputString;
	char * searchWordString;
	char * expectedReturnValue;
	int expectedErrorCode;
	int * errorCode;
}wordFind;


