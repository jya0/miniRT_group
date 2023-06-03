/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:41:28 by jyao              #+#    #+#             */
/*   Updated: 2023/05/22 14:22:01 by jyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_EXIT_H
# define RT_EXIT_H

typedef struct s_minirt	t_minirt;

void	rt_free_rt_split_arr(char **arr);

void	rt_free(t_minirt *minirt);

void	rt_exit(t_minirt *minirt);

#endif