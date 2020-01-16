#ifndef __OPTION_H__
#define __OPTION_H__

struct option
{
	struct server** servers;
};

struct option proxy_option;

int get_option_from_argument(int argc, const char**argv);
int get_option_from_file();
void skip_whitespace(char** data);

void show_config_key_invalid(const char* key, const char* correct_parent_key);

int create_option_file();
#endif
