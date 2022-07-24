#include <stdio.h>
#include <string.h>

// exceptions
enum exception_type {
    INCORRECT_USAGE = 0
};

// public accessible
typedef enum exception_type exception_type;

// exception structure
struct exception {
    char *message;
    exception_type type;
};

// public accessible
typedef struct exception exception;

/**
 * @brief Convert exception type to string
 * 
 * @param var - the variable to apply to
 * @param type - the exception type
 */
void to_string(char *var, exception_type type)
{
    // switch exception type
    switch (type)
    {
        // get messages
        case 0: strcpy(var, "INCORRECT_USAGE_EXCEPTION"); break;
    }
}

/**
 * @brief Throw an exception
 * 
 * @param exception - the exception
 */
void throw(exception *exception)
{
    // get exception type
    char type[100];
    to_string(type, exception->type);

    // throw
    printf("Error: %s\n%s\n", type, exception->message);
}