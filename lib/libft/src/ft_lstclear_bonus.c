/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:36 by vsanz-su          #+#    #+#             */
/*   Updated: 2023/10/04 12:11:31 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;

	if (!lst)
		return ;
	while (*lst)
	{
		pos = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pos;
	}
}
