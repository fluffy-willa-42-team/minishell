#ifndef BUILD_IN_H
# define BUILD_IN_H


typedef	t_vec	*(*t_build_in)();
t_vec	*dummy(char **env);
t_vec	*env(char **env);

#endif /* BUILD_IN_H */
