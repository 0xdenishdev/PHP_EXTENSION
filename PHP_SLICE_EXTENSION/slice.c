#include "php.h"

PHP_FUNCTION(slice);

const zend_function_entry slice_functions[] = {
	PHP_FE(slice, NULL)
	{
        NULL, NULL, NULL
    }
};

zend_module_entry slice_module_entry = {
	STANDARD_MODULE_HEADER,       // #if ZEND_MODULE_API_NO >= 20010901
	"slice",                      // Module name
	slice_functions,              // Exported functions
	NULL,                         // Module Initialization  - PHP_MINIT(slice),
	NULL,                         // Module Shutdown        - PHP_MSHUTDOWN(slice),
	NULL,                         // Request Initialization - PHP_RINIT(slice),
	NULL,                         // Request Shutdown       - PHP_RSHUTDOWN(slice),
	NULL,                         // Module Info            - PHP_MINFO(slice) (This value is used for phpinfo()),
	"0.1",                        // Module version
	STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(slice)

/**
 * slice - custom php function
 *
 * @param source_str - string in which search is produced
 * @param slice_from - from index
 * @param slice_to   - to index, default = string length
 *
 * @return string - slice
 */
PHP_FUNCTION(slice)
{
	char* source_str;
	int ss_length;
	long slice_from;
	long slice_to = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl|l", &source_str, &ss_length, &slice_from, &slice_to) == FAILURE)
	{
        return;
	}

    array_init(return_value);
    if (slice_to == 0)
    {
        slice_to = ss_length;
    }

    if (slice_to < slice_from)
    {
        RETURN_STRING(source_str, 1);
    }

    char* slice = strndup(source_str + slice_from, slice_to - slice_from);

    RETURN_STRING(slice, 1);
}















