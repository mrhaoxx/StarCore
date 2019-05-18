#include "void.h"
#include "bool.h"
#include "int.h"
#include "_string.h"
#include "../variable.h"
std::unique_ptr<root> root_void::convert_type(const std::string& t)
{
	SWITCH_BEGIN(t)
		SWITCH_CASE("string")
	{
		return std::make_unique<root_string>("void");
	}
	SWITCH_CASE("bool")
	{
		return std::make_unique<root_bool>(false);
	}
	SWITCH_CASE("int")
	{
		return std::make_unique<root_int>(0);
	}
	SWITCH_DEFAULT
		return std::unique_ptr<root_void>();
	SWITCH_END
}