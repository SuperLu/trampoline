/*Instance 1 of error*/

#include "embUnit.h"
#include "Os.h"

DeclareScheduleTable(INVALID_SCHEDULETABLE);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_error_instance1(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = OSErrorGetServiceId();
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2,INVALID_SCHEDULETABLE , OSServiceId_StartScheduleTableSynchron_ScheduleTableID());
	SCHEDULING_CHECK_AND_EQUAL_INT(2,OSServiceId_StartScheduleTableSynchron, result_inst_1);
		
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq2_error_instance1(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_error_instance1",test_error_instance1)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTSTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}