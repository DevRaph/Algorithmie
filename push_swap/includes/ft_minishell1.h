/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 16:20:19 by rpinet            #+#    #+#             */
/*   Updated: 2015/02/10 16:21:19 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <unistd.h>
# include <stdlib.h>

char					*ft_join(char *path, char *cmd);
int						ft_minishell1(char **env);
void					ft_builtin(char ***env, char **cmd);
char					*ft_clean(char *s);
char					*ft_get_env(char **env, char *id);
void					ft_print_cmd(char **cmd);
void					ft_env(char **env, char **cmd);
void					ft_unsetenv(char *name, char ***env);
void					ft_setenv(char *name, char *value, int o, char ***env);
int						ft_exec_cmd(char **env, char **cmd);
int						ft_exec(char **env, char **cmd);
int						ft_exec_cd(char **env, char **cmd);
void					ft_recup_signal(int signal);
void					ft_prompt(char **env, char *str);
void					ft_unset_all(char ***env);
size_t					ft_size_id(char const *s, char *c);

#endif