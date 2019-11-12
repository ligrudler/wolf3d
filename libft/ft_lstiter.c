/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:01:43 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/24 16:22:26 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *nxtlist;

	nxtlist = lst;
	while (nxtlist != NULL)
	{
		(*f)(nxtlist);
		nxtlist = nxtlist->next;
	}
}
