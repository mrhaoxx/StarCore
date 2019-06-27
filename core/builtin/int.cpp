#include "int.h"
#include "_string.h"
#include "bool.h"
#include "char.h"
#include "void.h"
#include "../domain.h"

std::unique_ptr<root> root_int::convert_type(const std::string& t)
{
	SWITCH_BEGIN(t)
		SWITCH_CASE("string")
	{
		return _make_unique<root_string>(std::to_string(d));
	}
	SWITCH_CASE("bool")
	{
		return _make_unique<root_bool>(d);
	}
	SWITCH_CASE("char")
	{
		return _make_unique<root_char>(char(d));
	}
	SWITCH_DEFAULT
		return std::unique_ptr<root_void>();
	SWITCH_END
}
root* root_int::new_this()
{
	member->insert("plus", new variable(new plus(this)));
	member->insert("minus", new variable(new minus(this)));
	member->insert("equals", new variable(new equals(this)));
	member->insert("less", new variable(new less(this)));
	member->insert("more", new variable(new more(this)));
	member->insert("multiply", new variable(new multiply(this)));
	member->insert("division", new variable(new division(this)));

	return this;
}
FUNCTION_DEFINITION(root_int::plus)
{
	if (args.size() != 1)
		ERR_ARG_LEN(1);
	return new variable(new root_int(GET_TYPE("int", root_int, parent)->d + GET_TYPE("int", root_int, args[0]->get())->d));
}
FUNCTION_DEFINITION(root_int::minus)
{
	if (args.size() != 1)
		ERR_ARG_LEN(1);
	return new variable(new root_int(GET_TYPE("int", root_int, parent)->d - GET_TYPE("int", root_int, args[0]->get())->d));
}
FUNCTION_DEFINITION(root_int::multiply)
{
	if (args.size() != 1)
		ERR_ARG_LEN(1);
	return new variable(new root_int(GET_TYPE("int", root_int, parent)->d * GET_TYPE("int", root_int, args[0]->get())->d));
}
FUNCTION_DEFINITION(root_int::division)
{
	if (args.size() != 1)
		ERR_ARG_LEN(1);
	return new variable(new root_int(GET_TYPE("int", root_int, parent)->d / GET_TYPE("int", root_int, args[0]->get())->d));
}
FUNCTION_DEFINITION(root_int::less)
{
	if (args.size() != 1)
		ERR_ARG_LEN(1);
	return new variable(new root_bool(GET_TYPE("int", root_int, parent)->d < GET_TYPE("int", root_int, args[0]->get())->d));
}
FUNCTION_DEFINITION(root_int::more)
{
	if (args.size() != 1)
		ERR_ARG_LEN(1);
	return new variable(new root_bool(GET_TYPE("int", root_int, parent)->d > GET_TYPE("int", root_int, args[0]->get())->d));
}
FUNCTION_DEFINITION(root_int::equals)
{
	if (args.size() != 1)
		ERR_ARG_LEN(1);
	return new variable(new root_bool(GET_TYPE("int", root_int, parent)->d == GET_TYPE("int", root_int, args[0]->get())->d));
}