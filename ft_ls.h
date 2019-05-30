/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:33:59 by olaktion          #+#    #+#             */
/*   Updated: 2018/10/31 12:34:03 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <grp.h>
# include <pwd.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include "libft/inc/ft_printf.h"
# include "libft/inc/libft.h"

# define LSF(x) (flags & x)
# define FMT(x, y) ((x & S_IFMT) == y)

# define VWF(x, y) (max) ? max[x] : ft_strlen(stats[y]), stats[y]

# define USR(x, a, b) ((st_mode & S_IRWXU) & x) ? a : b
# define GRP(x, a, b) ((st_mode & S_IRWXG) & x) ? a : b
# define OTE(x, a, b) ((st_mode & S_IRWXO) & x) ? a : b

# define SET_STAT(x, y) (file->stats[x] = y)

# define STAT(x, y) file->stats[x][y]

time_t		g_time;
const char	*g_app;

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct s_file	t_file;
typedef struct s_lsflag	t_lsflag;

struct					s_file
{
	char			*name;
	char			*path;
	long long		block_size;
	long long		byte_size;
	char			*stats[10];
	int				maxlen[6];
	struct timespec	timestamp;
	struct s_file	*parent;
	struct s_file	**child;
	int				child_count;
	int				i;
};

struct					s_lsflag
{
	char	c;
	int		flag;
	char	*obligatory;
	char	*contrast;
};

enum					e_lsflags
{
	LS_ALL = 1,
	LS_FTYPE = 1 << 1,
	LS_REC = 1 << 2,
	LS_SIZE = 1 << 3,
	LS_CT = 1 << 4,
	LS_BTIME = 1 << 5,
	LS_A = 1 << 6,
	LS_CTIME = 1 << 7,
	LS_D = 1 << 8,
	LS_F = 1 << 9,
	LS_GROUP = 1 << 10,
	LS_L = 1 << 11,
	LS_OMIT_GROUP = 1 << 12,
	LS_P = 1 << 13,
	LS_REV = 1 << 14,
	LS_MTIME = 1 << 15,
	LS_ATIME = 1 << 16,
	LS_1 = 1 << 17
};

/*
** ft_args.c
*/

void					split_sort(int flags, t_file **args);

t_bool					sort_args(int argc, int idx, char **argv);

void					sort_types(t_file **child);

void					*free_args(t_file **args);

t_file					**build_args(int argc, int idx, int flags, char **argv);

/*
** ft_loading.c
*/

t_file					*build_file(char *name, int flags, char *path);

void					*free_file(t_file **file);

t_bool					skip_file(int flags, char *fname);

t_file					*loading_parent(int flags, char *path);

t_bool					loading_child(int flags, t_file *file);

/*
** ft_ls.c
*/

int						get_max_width(int field, t_file **child);

void					set_padding(t_file *file);

int						main(int argc, char **argv);

/*
** ft_pars.c
*/

t_bool					is_defis(char *arg);

t_bool					print_usage(char c);

void					set_flag(const t_lsflag *f, int *flags);

t_bool					parse_flags(int *idx, int *flags, char **argv,
						int argc);

/*
** ft_print.c
*/

void					print_long(int *max, int flags, char **stats);

void					print_files(int flags, t_file *file);

void					print_recursive(int flags, t_file *file);

t_file					*get_next_dir(int flags, t_file *file);

/*
** ft_sort.c
*/
int						cmp(const t_file *f1, const t_file *f2, int flags);

void					max_stack(int flags, t_file **array, int node,
							int size);
int						dir_len(int flags, char *path);

void					stack_sort(int flags, t_file **child,
							int child_count);

/*
** ft_stat.c
*/

char					get_type(mode_t st_mode);

char					*get_time_str(int flags, t_file *file, t_stat *stats);

char					*get_permis(mode_t st_mode);

t_bool					is_simdir(t_file *file, int flags);

t_bool					loading_stats(int flags, t_file *file, t_stat *stats);

/*
** ft_util.c
*/

char					*build_name(int flags, t_file *file);

char					*build_link(int flags, char *link, char *target);

char					*build_path(char *parent, char *child);

/*
** ft_valid.c
*/

void					*ls_error(char *path);

t_bool					valid_args(int idx, char **argv);

/*
** ft_wrap.c
*/

int						ls_close(char *path, DIR *dir);

DIR						*ls_open(char *path);

t_dirent				*ls_read(char *path, DIR *dir);

extern time_t			g_time;
extern const char		*g_app;
extern const t_lsflag	g_lsflags[];
extern const int		g_lsflag_count;
#endif
