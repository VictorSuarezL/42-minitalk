/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:45:04 by vsanz-su          #+#    #+#             */
/*   Updated: 2023/10/06 09:40:07 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*end;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
		{
			end = lst;
		}
		lst = lst->next;
	}
	return (end);
}
