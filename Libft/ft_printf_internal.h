/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:18:01 by gyildiz           #+#    #+#             */
/*   Updated: 2025/02/28 11:48:09 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# ifdef __APPLE__
#  define NUL "0x0"
#  define WRITTEN 3
#  define NL "0x0"
#  define WRT 3
# else
#  define NUL "(null)"
#  define WRITTEN 6
#  define NL "(nil)"
#  define WRT 5
# endif

# include "libft.h"
# include <stdarg.h>

int	ft_string(char *s);
int	ft_pointer(unsigned long long n, int first_call);
int	ft_pointercast(void *ptr);
int	ft_decint(int di);
int	ft_unsignedint(unsigned int u);
int	ft_lowhex(unsigned int x);
int	ft_uphex(unsigned int ux);

#endif