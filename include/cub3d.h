/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:41:27 by lps               #+#    #+#             */
/*   Updated: 2024/10/03 12:40:46 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define ROTATE_SPEED 0.05
# define MOVE_SPEED 0.05

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef enum e_error
{
	SUCCESS,
	INVALID_ARG,
	WRONG_MAP,
	WRONG_INPUT,
	MALLOC_FAIL,
	IMG_FAIL,
	OPEN_ERR,
	MLX_FAIL,
	WRITE_FAIL,
	WRONG_TEXTURE
}						t_error;

typedef struct s_stack_node
{
	char				*val;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node		*front;
	t_stack_node		*back;
}						t_stack;

void					init_stack(t_stack *s);
void					add_node(t_stack *s, void *val);
void					*remove_node(t_stack *s);
char					*stack_to_str(t_stack *s);
void					free_stack(t_stack *s);

typedef struct s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct s_row_list
{
	char				*row;
	int					size;
	struct s_row_list	*next;
}						t_row_list;

typedef struct s_map_infos
{
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	t_color				floor_color;
	t_color				ceiling_color;
	t_stack				stack;
	int					no_path_parsed;
	int					so_path_parsed;
	int					we_path_parsed;
	int					ea_path_parsed;
	int					floor_color_parsed;
	int					ceiling_color_parsed;
	t_row_list			*rowlist;
}						t_map_infos;

typedef struct s_map
{
	int					cols;
	int					rows;
	char				**map_data;
}						t_map;

typedef struct s_image
{
	void				*img;
	char				*address;
	int					bits_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_image;

typedef struct s_arr
{
	char				**strings;
	int					length;
}						t_arr;

typedef struct s_ray
{
	double				raydir_x;
	double				raydir_y;
	int					map_x;
	int					map_y;
	double				delta_x;
	double				delta_y;
	double				side_x;
	double				side_y;
	int					step_x;
	int					step_y;
	int					side;
	double				wall_dist;
	int					current_x;
	int					draw_start;
	int					line_height;
	int					draw_end;
}						t_ray;

typedef struct s_line
{
	int					x;
	int					y;
	int					y0;
	int					y1;
	int					tex_x;
	int					tex_y;
}						t_line;

typedef struct s_key
{
	bool				w;
	bool				s;
	bool				a;
	bool				d;
	bool				left;
	bool				right;
	bool				up;
	bool				down;
}						t_key;

typedef struct s_player
{
	double				cam_height;
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				speed;
	t_line				line;
	double				camera_x;
	char				direction;

}						t_player;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	t_image				image;
	t_ray				ray;
	t_key				keys;
	t_map				map;
	t_map_infos			map_infos;
	t_player			player;
	t_image				north_texture;
	t_image				south_texture;
	t_image				west_texture;
	t_image				east_texture;
	int					floor_color;
	int					ceiling_color;

}						t_data;

typedef struct s_map_val
{
	char				**map;
	int					row_count;
	int					col_count;
}						t_map_val;

typedef struct s_array
{
	char				**strs;
	int					length;
}						t_array;

void					ft_free(void **ptr);
void					free_array(char **array);
void					free_2d_array(char ***map);
void					free_map_infos(t_map_infos *map_infos);
void					free_and_cleanup(t_data *data);

int						parse_map(char *file_name, t_map_infos *map_infos);

int						verify_colors(t_color *color, char **colors);
int						check_texture(char *path);

int						beginswith(char **array, char *str);
int						arr_length(char **array);
int						is_empty_line(char *line);
int						open_map_file(char *file_name);
int						is_number(char *str);
void					print_error(const char *error_message);
int						print_error_ms(const char *error_message);

int						is_valid_map(t_map *map);

void					convert_stack_to_2d_array(t_map *map, t_stack *stack);

int						check_texture_path(t_map_infos *map_infos, t_arr *array,
							int *parsed_flag, char *type);

int						print_missing_elements_error(t_map_infos *map_infos);

void					run_game(t_data *data);
void					cast_rays(t_data *data, t_player *player);
void					wall_distance(t_map *map, t_ray *ray, t_player *player);

int						on_keyrelease(int key, void *info);
int						exit_game(void *info);
int						hook_loop(void *info);
int						on_keypress(int key, void *info);
void					go_forward(t_data *data);
void					go_backward(t_data *data);
void					move_left(t_data *data);
void					move_right(t_data *data);
void					rotate_left(t_data *data);
void					rotate_right(t_data *data);

void					paint_texture_line(t_data *root, t_ray *ray,
							t_line *line, double wall_x);
void					load_texture(t_data *data, t_image *image, char *path);

void					init_player_direction(t_data *data, char dir);
void					ray_info(t_ray *ray, t_player *player);
void					init_keys(t_key *keys);
void					data_info(t_data *data);
void					player_info(t_data *data);
void					print_array(char **array);
unsigned int			color_to_hex(t_color color);
void					error_message(const char *message);
int						open_map_file(char *file_name);
void					init_map_infos(t_map_infos *map_info);
int						verify_arguments(int ac, char **av);
int						is_map_open(t_map_infos *info, int row, int col);
int						convert_list_to_map(t_map_infos *info);
int						init_map(t_map_infos *info);
int						additional_check(t_map_infos *map_info);
char					*ft_strchr(const char *str, int c);
char					*my_strjoin(char *string1, char *string2);
char					*read_line(int fd, char *str);
char					*skip_line(char *input_string);
char					*extract_line(char *input_str);
char					*get_next_line(int fd);
void					ft_free(void **ptr);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
int						num_words(const char *s, char seperator);
char					**ft_split(char const *s, char seperator);
void					print_error(const char *error_message);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
int						is_number(char *str);
int						all_elements_parsed(t_map_infos *map_infos);
int						ft_isdigit(int c);
void					free_array(char **arr);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
int						arr_length(char **array);
void					ft_free(void **ptr);
int						check_colors(char **colors);
int						count_commas(char *str);
int						count_rows_in_stack(t_stack *stack);
int						count_columns(t_stack *stack);
void					*remove_node(t_stack *s);
void					convert_stack_to_2d_array(t_map *map, t_stack *stack);
int						parse_arguments(int argc, char **argv,
							t_map_infos *map_infos, t_map *map);
int						print_missing_elements_error(t_map_infos *map_infos);
int						is_empty_line(char *line);
void					add_node(t_stack *s, void *val);
char					*ft_strtrim(char const *s1, char const *set);
int						is_valid_map_char(char c);
int						is_map_enclosed(t_map *map);
int						valid_sides(t_map *map, int i, int j);
int						is_valid_map(t_map *map);
void					free_map_info(t_map_infos *map_infos);
void					free_stack(t_stack *s);
void					free_2d_array(char ***map);
void					free_map_infos(t_map_infos *map_infos);
int	validate_and_assign_color(t_map_infos *map_infos,
								t_array *array);
int						check_texture(char *path);
int	process_color_setting(t_map_infos *map_infos,
							t_array *array,
							int *parsed_flag,
							char *type);
int	check_color_line(t_map_infos *map_infos,
						t_array *array);
int						verify_colors(t_color *color, char **colors);
int						check_color(t_color *color);
int	parse_texture_line(t_map_infos *map_infos,
						t_array *array);
int						nbr_len(int n);
void					init_stack(t_stack *s);
int						check_duplicates(t_map_infos *map_infos, t_array *array,
							int *parsed_flag, char *type);
int						parse_line(t_map_infos *map_infos, char *map_line);
bool					read_map(int fd, t_map_infos *map_infos);
int						check_duplicates(t_map_infos *map_infos, t_array *array,
							int *parsed_flag, char *type);
int						verify_map_element(t_map *map, int i, int j);
int						count_columns(t_stack *stack);
int	handle_color_line(t_map_infos *map_infos,
						t_array *array,
						int *parsed_flag,
						char *type);

#endif