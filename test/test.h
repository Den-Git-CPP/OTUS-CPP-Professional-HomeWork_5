#pragma once
#include "g_test_vector_editor.h"

TEST(graph_project, add_primitive_line) { 
 	graph_project model{};
	view_project view{ model };
	controller canvas(model, view);
 	auto primitive = std::shared_ptr <base_primitive>(
		new Line{ Coord{1,2},Coord{3,4} }
	);
  std::stringstream buffer,strm;
  strm<<"-------------------------------\n"
      <<"*LINE from (1,2) to (3,4)\n"
      <<"-------------------------------\n\n\n";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  canvas.add_primitive(primitive);
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

TEST(graph_project, add_primitive_rectangle) { 
 	graph_project model{};
	view_project view{ model };
	controller canvas(model, view);
 	auto primitive = std::shared_ptr <base_primitive>(
		new Rectangle{ Coord{3,3},Coord{6,4} }
	);
  std::stringstream buffer,strm;
  strm<<"-------------------------------\n"
      <<"*RECTANGLE from (3,3) to (6,4)\n"
      <<"-------------------------------\n\n\n";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  canvas.add_primitive(primitive);
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

TEST(graph_project, add_primitive_circle) { 
 	graph_project model{};
	view_project view{ model };
	controller canvas(model, view);
 	auto primitive = std::shared_ptr <base_primitive>(
		new  Circle{ Coord{5,5},2 }
	);
  std::stringstream buffer,strm;
  strm<<"-------------------------------\n"
  <<"*CIRCLE at (5,5) with radius 2\n"
  <<"-------------------------------\n\n\n";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  canvas.add_primitive(primitive);
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }

TEST(graph_project, constructor_model) { 
 	graph_project model{};
  size_t p= static_cast<int>(model.elements.size());
  ASSERT_EQ(p, 0);
 }

TEST(canvas, import_project) { 
 	graph_project model{};
	view_project view{ model };
	controller canvas(model, view);

 	std::stringstream buffer,strm;
  strm<<"-------------------------------\n"
  <<"EMPTY WINDOW\n"
  <<"-------------------------------\n\n\n";	  
  std::streambuf *sbuf =std::cout.rdbuf();
  std::cout.rdbuf(buffer.rdbuf());
  canvas.import_project("document");
  //controller.import_project("document");
  std::cout.rdbuf(sbuf);
  
  ASSERT_EQ(buffer.str(), strm.str());
 }