#pragma once

#include "../memory/safe_ptr.h"

#include <string>

namespace caspar { namespace diagnostics {
	
struct color
{
	float red;
	float green;
	float blue;
	float alpha;
	
	color(float r = 0.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
		: red(r)
		, green(g)
		, blue(b)
		, alpha(a){}
};

class graph
{
	friend safe_ptr<graph> create_graph(const std::string& name);
	graph(const std::string& name);
public:
	void update(const std::string& name, float value);
	void tag(const std::string& name);
	void guide(const std::string& name, float value);
	void set_color(const std::string& name, color c);
private:
	struct implementation;
	std::shared_ptr<implementation> impl_;
};

safe_ptr<graph> create_graph(const std::string& name);
	
}}