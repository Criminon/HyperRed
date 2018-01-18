#include <pokeagb/pokeagb.h>

bool cmd_var_add(struct ScriptEnvironment* scr_env)
{
	var1 = script_read_halfword(src_env);
	var2 = script_read_halfword(src_env);
	var_set(var1, (var_load(var1) + var_load(var2)));
}

bool cmd_var_sub(struct ScriptEnvironment* scr_env)
{
	var1 = script_read_halfword(src_env);
	var2 = script_read_halfword(src_env);
	var_set(var1, (var_load(var1) - var_load(var2)));
}

bool cmd_var_div(struct ScriptEnvironment* scr_env)
{
	var1 = script_read_halfword(src_env);
	var2 = script_read_halfword(src_env);
	var_set(var1, (var_load(var1) / var_load(var2)));
}

bool cmd_var_mul(struct ScriptEnvironment* scr_env)
{
	var1 = script_read_halfword(src_env);
	var2 = script_read_halfword(src_env);
	var_set(var1, (var_load(var1) * var_load(var2)));
}