#ifndef LEXER_H
# define LEXER_H

/**
 * @brief Function pointer.
 */
typedef int	(*t_function_ptr)(t_vec *vec, int index);

int whtspc(t_vec *vec, char *line, int index);
int varsub(t_vec *vec, char *line, int index);
int bkslh(t_vec *vec, char *line, int index);
int sglqot(t_vec *vec, char *line, int index);

#endif /* LEXER_H */
