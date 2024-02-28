/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:44:16 by vsanz-su          #+#    #+#             */
/*   Updated: 2023/10/04 09:11:48 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_lst;

	n_lst = (t_list *)malloc(sizeof(t_list));
	if (!n_lst)
	{
		return (NULL);
	}
	n_lst->content = content;
	n_lst->next = NULL;
	return (n_lst);
}
