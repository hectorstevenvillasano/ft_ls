#ifndef FT_LS_H
#define FT_LS_H

# include "libft/inc/ft_printf.h"
# include <sys/types.h>
# include <dirent.h>

typedef enum s_flags
{
	long_format = 1,	//	-l
	recursive_list = 2, // 	-R
	all_dirs = 4,		// -a
	reverse_order = 8,	// -r
 	timemodified_sort = 16,	//-t
	//all_flags_on =
}			t_flags;

typedef struct	s_files
{
	char			*file; //file name
	struct s_files	*next;
}				t_files;

typedef struct	s_dirs
{
	char			*dir_name;		//name of specific dir
	t_files			*files; //files of this dir_name
	struct s_dirs	*next;
}				t_dirs;

typedef struct s_entries
{
	t_dirs		*dirs;	//hold list of dirs
	t_files		*file_list; //hold list of files to output
	t_files		*none_ex; //holds files that are non existent
	t_flags		flags;
}				t_entries;

/*
**	ftls_list.c
*/
void 		print_list(t_files *list);
void 		lstadd_files(t_files **head,char *file_name);
void 		lstadd_dirs(t_dirs **alst, t_dirs *t_new);
t_entries	entries_init(void);

/*
**	merge_sort.c
*/
void 	merge_sort(t_files **headref);

/*
**	none_ex.c
*/
void addto_file_list(char **av, t_files **file_list, t_files **none_ex);

#endif
