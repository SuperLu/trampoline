/*Instance 3 of task t2*/

#include "embUnit.h"
#include "Os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance3(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_1 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK, result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq13_t2_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance3",test_t2_instance3)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTSTest_sequence13",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}