#include "stdafx.h"
#include "gtest\gtest.h"
#include "..\MLStudio.core\Factory.h"
#include <atomic>

TEST(TestUtility, IdGenerationOkay)
{
	auto a = Utility::GetId();
	while (Utility::GetId()!=10)
	{

	}
	ASSERT_EQ(Utility::GetId(), 11);
}