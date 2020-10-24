#include "authenticate.h"
#include "CUnit/Basic.h"
#include <string.h>


/* code de test unitaire */

int init_suite(void)
{
    return 0;
}

int clean_suite(void)
{
    return 0;
}

/* simple test of authenticate */ 

void test_authenticate(void)
{
    char userName[100] = "username";
    char password[100] = "password";
    
    CU_ASSERT(0 == authenticate(userName,password));
}

/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */

int main(void)
{
    CU_pSuite pSuite = NULL;
    
    /* initialize the CUnit test registry */
    if(CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    
    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite", init_suite, clean_suite);
    if(NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if((NULL == CU_add_test(pSuite, "....test of authenticate....\n", test_authenticate)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

/* compilation avec clang : clang -lncurses test_saisie.c */
