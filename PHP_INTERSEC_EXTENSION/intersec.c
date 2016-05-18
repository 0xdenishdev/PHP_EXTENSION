#include "php.h"

PHP_FUNCTION(intersec);

const zend_function_entry intersec_functions[] = {
    PHP_FE(intersec, NULL)
    {
        NULL, NULL, NULL
    }
};

zend_module_entry intersec_module_entry = {
    STANDARD_MODULE_HEADER,       // #if ZEND_MODULE_API_NO >= 20010901
    "intersec",                   // Module name
    intersec_functions,           // Exported functions
    NULL,                         // Module Initialization  - PHP_MINIT(intersec),
    NULL,                         // Module Shutdown        - PHP_MSHUTDOWN(intersec),
    NULL,                         // Request Initialization - PHP_RINIT(intersec),
    NULL,                         // Request Shutdown       - PHP_RSHUTDOWN(intersec),
    NULL,                         // Module Info            - PHP_MINFO(intersec) (This value is used for phpinfo()),
    "0.1",                        // Module version
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(intersec)

/**
 * intersec - custom php function
 *
 * @param l_array - left array
 * @param r_array - right array
 *
 * @return array - intersection
 */
PHP_FUNCTION(intersec)
{
    zval *l_arr, *r_arr, **l_data, **r_data;
    HashTable *l_arr_hash, *r_arr_hash;
    HashPosition l_pointer, r_pointer;
    int l_arr_count, r_arr_count;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa", &l_arr, &r_arr) == FAILURE)
    {
        RETURN_NULL();
    }

    array_init(return_value);

    l_arr_hash = Z_ARRVAL_P(l_arr);
    r_arr_hash = Z_ARRVAL_P(r_arr);

    l_arr_count = zend_hash_num_elements(l_arr_hash);
    r_arr_count = zend_hash_num_elements(r_arr_hash);

    int *l = unique_filter(l_arr_hash, l_pointer, l_data, l_arr_count);
    int *r = unique_filter(r_arr_hash, r_pointer, r_data, r_arr_count);

    int i, j, k = 0;
    for (i = 0; i < l_arr_count; i++)
    {
        for (j = 0; j < r_arr_count; j++)
        {
            if (l[i] == r[j])
            {
                add_index_long(return_value, k++, (long) l[i]);
            }
        }
    }
}

int
unique_filter(HashTable *arr_hash, HashPosition pointer, zval **data, int size)
{
    int i = 0;
    int *t = malloc (sizeof (int) * size);
    for (zend_hash_internal_pointer_reset_ex(arr_hash, &pointer);
         zend_hash_get_current_data_ex(arr_hash, (void**) &data, &pointer) == SUCCESS;
         zend_hash_move_forward_ex(arr_hash, &pointer))
    {
        if (in_array(Z_LVAL_PP(data), t, size) == 0)
        {
            t[i++] = Z_LVAL_PP(data);
        }
    }

    zend_hash_destroy(arr_hash);
    FREE_HASHTABLE(arr_hash);

    return t;
}

int
in_array(long val, int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (val == arr[i])
        {
            return 1;
        }
    }

    return 0;
}

