#include <Windows.h>
#include <stdio.h>
#include "test_defs.h"

extern void movememory(void* dst, void* src, size_t count);

TEST(FirstTask, memcpy)
{
	size_t oldEsp = 0;
	size_t newEsp = 0;

	char str1[] = "This is a test\n";
	char str2[] = "is a test test\n";
	char str3[] = "is a is a test\n";

	

	__asm { mov oldEsp, esp }
	movememory(str1, str1 + 5, 9);
	__asm { mov newEsp, esp }

	


	if (oldEsp != newEsp)
		FAIL_WITH_CODE(AssertFailStackUnbalanced);

	ASSERT_EQUAL(0, memcmp(str1, str2, sizeof(str2)));

	

}


TEST(SecondTask, memmove)
{

	size_t oldEsp = 0;
	size_t newEsp = 0;

	char str1[] = "is a test test\n";
	char str2[] = "is a is a test\n";

	__asm { mov oldEsp, esp }
	movememory(str1 + 5, str1, 8);
	__asm { mov newEsp, esp }



	if (oldEsp != newEsp)
		FAIL_WITH_CODE(AssertFailStackUnbalanced);

	ASSERT_EQUAL(0, memcmp(str1, str2, sizeof(str2)));



}