// MLStudio.core.Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest\gtest.h"
#include "..\MLStudio.core\Node.h"
#include "..\MLStudio.core\NodeMeta.h"
#include "..\MLStudio.core\ExecutionPlan.h"


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

TEST(TestNodes, CreatedFine)
{
	NodeMeta nm;
	Node n(nm);
	n.GetId();
	Node n2(nm);
	EXPECT_NE(n2.GetId(), n.GetId());
	EXPECT_EQ(n.GetInputMapping().size(), 3);
	ASSERT_EQ(n.GetOutputMapping().size(), 4);
	
}

TEST(TestExPlan, BasicWorkflow)
{
	NodeMeta nm;
	Node n(nm);
	Node n2(nm);
	ExecutionPlan ex;
	ex.AddNode(n);
	ex.AddNode(n2);
	for (auto i = ex.Begin(); i != ex.End(); i++)
	{
		auto tar = *i;

	} 
	for (int i = 0; i < ex.Size(); i++)
	{
		
	}
	unsigned int aaa = 3; unsigned int bbb = 4;
	Node& src = ex.GetNodeById(aaa);
	src.ConnectNode(ex.GetNodeById(bbb), 0, 0);
	auto a = src;
}