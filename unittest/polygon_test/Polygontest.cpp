// Polygontest.cpp
// Copyright (c) 2009, Perttu "celero55" Ahola
// This program is released under the BSD license. See the file COPYING for details.

#include <gtest/gtest.h>

#ifndef UNITTEST_NO_HEEKS
#define UNITTEST_NO_HEEKS
#endif

#include "src/Polygon.h"
#include <stdlib.h>

TEST(TestSuite, testSweepLine)
{
	std::vector<LineSegment> lines_vector;

	/*lines_vector.push_back(LineSegment(-2,3,3,4));
	lines_vector.push_back(LineSegment(-4,3,-2,-1));
	lines_vector.push_back(LineSegment(-4,-1,-1,1));
	lines_vector.push_back(LineSegment(-2,-1,2,-1));
	lines_vector.push_back(LineSegment(-4,0.5,-1,-0.5));
	lines_vector.push_back(LineSegment(-3.5,2,1.5,-1));
	lines_vector.push_back(LineSegment(-4,0.5,4,0.5));
	lines_vector.push_back(LineSegment(6,1,8,1));
	lines_vector.push_back(LineSegment(7,4,6,-2));
	lines_vector.push_back(LineSegment(9,1,7,1));
	lines_vector.push_back(LineSegment(1,-4,1,5));
	lines_vector.push_back(LineSegment(6,5,1,5));
	lines_vector.push_back(LineSegment(1,-2,1,-3));
	lines_vector.push_back(LineSegment(4,3,3,2));*/

	//srand(time(0));
	srand(0);

	int num_lines = 400;

	for(int i=0; i<num_lines; i++){
		double x1, y1, x2, y2;
		x1 = (double)(rand() % 100);
		y1 = (double)(rand() % 100);
		x2 = (double)(rand() % 100);
		y2 = (double)(rand() % 100);
		lines_vector.push_back(LineSegment(x1,y1,x2,y2));
	}
	
	unsigned int num;
	num = SweepLine(lines_vector);

	//std::list<Polygon> result_list;
	//UnionPolygons(lines_vector, result_list);
	

	/*std::cout<<"lines_vector:"<<std::endl;
	for(unsigned int i=0; i<lines_vector.size(); i++)
	{
		std::cout<<"\t"<<lines_vector[i].str();
		if(!lines_vector[i].m_intersections_set.empty())
			{ std::cout<<" intersects with:"<<std::endl; }
		else
			{ std::cout<<" doesn't intersect."<<std::endl; }
		for(std::set<IntersectionInfo>::const_iterator
				it = lines_vector[i].m_intersections_set.begin();
				it != lines_vector[i].m_intersections_set.end(); it++)
		{
			std::cout<<"\t\t"<<it->str()<<"  \t"<<lines_vector[it->i].str()<<std::endl;
		}
	}*/

  /* For random seed "0" we should have 2,098 intersections. */
  /* A different random seed will give a different result. */
  EXPECT_EQ(2098, num);
	std::cout<<"found "<<num<<" intersection points from "
			<<num_lines<<" lines."<<std::endl;
}

// Run all the tests that were declared with TEST()
int main(int argc, char *argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

